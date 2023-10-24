cmake_minimum_required(VERSION 3.27.7)
project(rbuart)

set(CMAKE_CXX_STANDARD 17)

set(UART_SOURCE_FILES uart.cpp)

add_library(rbuart SHARED ${UART_SOURCE_FILES})

target_include_directories(rbuart PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../includes/uart)

set_target_properties(rbuart PROPERTIES OUTPUT_NAME "rb-uart")