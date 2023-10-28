#include "../includes/message/message.h"
#include "../protocol/protocolv1/igenericbyte.h"
#include "../uart/uart.h"
#include "../utils/utils.h"
#include <iostream>
#include <memory>

Message::Message(uint8_t frame_header_h,
                 uint8_t frame_header_l,
                 uint8_t command)
{
    this->frame_header_h = frame_header_h;
    this->frame_header_l = frame_header_l;
    this->command = command;
    this->byte_count = 0;
    this->_register = std::nullopt;
    this->data = std::nullopt;
    this->lenght = std::nullopt;
    this->vp_address = std::nullopt;
}

Message::Message(const Message &other)
    : frame_header_h(other.frame_header_h),
      frame_header_l(other.frame_header_l),
      command(other.command),
      byte_count(other.byte_count),
      _register(other._register),
      data(other.data),
      lenght(other.lenght),
      vp_address(other.vp_address)
{
}

Message::~Message() {}

uint8_t Message::get_frame_header_h()
{
    return this->frame_header_h;
}

uint8_t Message::get_frame_header_l()
{
    return this->frame_header_l;
}
uint8_t Message::get_byte_count()
{
    return this->byte_count;
}
uint8_t Message::get_command()
{
    return this->command;
}

std::optional<uint8_t> Message::get_lenght()
{
    return this->lenght;
}

std::optional<uint8_t> Message::get_register()
{
    return this->_register;
}

std::optional<std::vector<uint8_t>> Message::get_data()
{
    return this->data;
}

std::optional<uint16_t> Message::get_vp_address()
{
    return this->vp_address;
}

void Message::set_register(std::optional<uint8_t> _register)
{
    this->_register = _register;
}

void Message::set_data(std::optional<std::vector<uint8_t>> data)
{
    this->data = data;
}

void Message::set_data(char *data)
{
    if (nullptr == data)
    {
        std::cout << "Data is empty! " << std::endl;
        return;
    }

    std::optional<std::vector<uint8_t>> result = std::vector<uint8_t>();

    for (size_t i = 0; data[i] != '\0'; i++)
    {
        result.value().push_back(static_cast<uint8_t>(data[i]));
    }

    // To be the same as exercise b.1.b, I didn't understand why
    result.value().push_back('\0');
    result.value().push_back('\0');

    this->data = result;
}

void Message::set_length(std::optional<uint8_t> lenght)
{
    this->lenght = lenght;
}

void Message::set_byte_count(uint8_t byte_count)
{
    this->byte_count = byte_count;
}

std::vector<uint8_t> Message::get_bytes()
{
    std::vector<uint8_t> bytes;

    bytes.push_back(this->get_frame_header_h());
    bytes.push_back(this->get_frame_header_l());
    bytes.push_back(this->byte_count);
    bytes.push_back(this->get_command());
    if (this->_register.has_value())
        bytes.push_back(this->_register.value());
    if (this->vp_address.has_value())
    {
        std::vector<uint8_t> split_vp = split_vp_address();
        for (auto vp : split_vp)
            bytes.push_back(vp);
    }
    if (this->lenght.has_value())
        bytes.push_back(this->lenght.value());
    if (this->data.has_value())
        for (auto data : this->data.value())
        {
            bytes.push_back(data);
        }

    return bytes;
}

bool Message::is_memory_overflow()
{
    uint16_t max = this->get_memory_max();
    const std::type_info &tipo = typeid(this);
    std::string class_name = tipo.name();

    uint16_t start_memory_addrs = this->get_memory_address(); // vp or register

    if (this->data.value().size() > max - start_memory_addrs)
    {
        std::cout << "Invalid data size {" + class_name + "}" << std::endl;
        return true;
    }

    return false;
}

void Message::set_vp_address(std::optional<uint16_t> vp_address)
{
    this->vp_address = vp_address;
}

std::vector<uint8_t> Message::split_vp_address()
{
    const std::type_info &tipo = typeid(this);
    std::string class_name = tipo.name();
    uint8_t low_byte = 0;
    uint8_t high_byte = 0;
    std::vector<uint8_t> splited;

    if (!this->vp_address.has_value())
    {
        throw std::invalid_argument("Invalid vp address {" + class_name + "}");
    }

    uint16_t vp_address;

    vp_address = this->vp_address.value();
    low_byte = static_cast<uint8_t>(vp_address & 0xFF);
    high_byte = static_cast<uint8_t>((vp_address >> 8) & 0xFF);

    splited.push_back(low_byte);
    splited.push_back(high_byte);

    return splited;
}

uint8_t Message::calc_byte_count()
{
    uint8_t size_lenght = (this->get_lenght().has_value()) ? 1 : 0;
    uint8_t size_data = (this->get_data().has_value()) ? this->get_data().value().size() : 0;
    size_t cmd_reg = 2; // lenght cmd plus register

    if (this->get_lenght().has_value() && this->get_data().has_value())
    {
        return size_lenght + size_data + cmd_reg;
    }

    if (this->get_lenght().has_value())
    {
        return size_lenght + cmd_reg;
    }

    if (this->get_data().has_value())
    {
        return this->get_data().value().size() + cmd_reg;
    }
    return 0;
}

uint16_t Message::get_memory_max()
{
    return 0xFF;
}

uint16_t Message::get_memory_address()
{
    std::optional<uint8_t> _register = get_register();
    if (!_register.has_value())
    {
        std::cout << "Invalid Register! " << std::endl;
        return true;
    }
    return _register.value();
}

void Message::process_and_send_data(const std::optional<std::vector<uint8_t>> &data,
                                    std::optional<std::unique_ptr<IGenericByte>> &generic_byte) 
{
    if (data.has_value())
    {
        if(generic_byte.has_value()){
            generic_byte.value().get()->check_data(data);
        }

        if (is_memory_overflow())
        {
            throw std::overflow_error("Memory Overflow! ");
        }
    }

    std::vector<uint8_t> bytes = this->get_bytes();

    std::cout << "Write serial: " << std::endl;
    for(auto a: bytes){
        std::cout << "[" << static_cast<int>(a) << "]";
    }

    std::cout << std::endl;

    std::unique_ptr<Uart> uart = std::make_unique<Uart>(); 
    std::unique_ptr<Utils> utils = std::make_unique<Utils>(); 
    size_t bytes_length = bytes.size();
    unsigned char *c_bytes = utils->to_char_pointer(bytes);
    uart->send(c_bytes, bytes_length);
    std::cout << std::endl;
}