cmake_minimum_required(VERSION 3.27.7) 
project(challange_rentbrella)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-return-type")
add_executable(challange_rentbrella 
    ../src/rb-ihm.cpp
    ../src/message/message.cpp
    ../src/message/messagevp.cpp
    ../src/message/messagere.cpp
    ../src/protocol/protocolv1/backlight/message/backlight.cpp
    ../src/protocol/protocolv1/qrcode/message/qrcode.cpp
    ../src/protocol/protocolv1/backlight/mode/mode.cpp
    ../src/protocol/protocolv1/backlight/mode/normal_mode.cpp
    ../src/protocol/protocolv1/backlight/mode/low_mode.cpp
    ../src/protocol/protocolv1/backlight/mode/period_mode.cpp
    ../src/protocol/protocolv1/backlight/mode/factory/factory.cpp
    ../src/protocol/protocolv1/screen/confpicid/byte.cpp
    ../src/protocol/protocolv1/screen/confpicid/highbyte.cpp
    ../src/protocol/protocolv1/screen/confpicid/lowbyte.cpp
    ../src/protocol/protocolv1/screen/confpicid/factory/factory.cpp
    ../src/protocol/protocolv1/screen/message/screen.cpp
    ../src/protocol/protocolv1/button/message/button.cpp
    ../src/ihm/ihm.cpp
    ../src/protocol/factory/factory.cpp
    ../src/protocol/protocolv1/protocolv1.cpp
    ../src/protocol/protocol.cpp
    ../src/utils/utils.cpp)
add_subdirectory(src/uart)
target_link_libraries(challange_rentbrella PRIVATE rbuart)
target_include_directories(challange_rentbrella PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/factory
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/backlight/message
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/backlight/mode
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/backlight/mode/factory
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/screen
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/screen/confpicid
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/screen/confpicid/factory
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/screen/message
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/button/message
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/message
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/qrcode/message
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/ihm
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/constants
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/utils
    )