cmake_minimum_required(VERSION 3.27.7) 
project(challange_rentbrella)
set(CMAKE_CXX_STANDARD 17)
add_executable(challange_rentbrella 
    ../src/rb-ihm.cpp
    ../src/message/message.cpp
    ../src/protocol/protocolv1/backlight/message/backlight.cpp
    ../src/protocol/protocolv1/qrcode/message/qrcode.cpp
    ../src/protocol/protocolv1/backlight/mode/mode.cpp
    ../src/protocol/protocolv1/backlight/mode/normal_mode.cpp
    ../src/protocol/protocolv1/backlight/mode/low_mode.cpp
    ../src/protocol/protocolv1/backlight/mode/period_mode.cpp
    ../src/protocol/protocolv1/backlight/mode/factory.cpp
    ../src/ihm/ihm.cpp
    ../src/protocol/factory/factory.cpp
    ../src/protocol/protocolv1/protocolv1.cpp
    ../src/protocol/protocol.cpp)
target_include_directories(challange_rentbrella PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/factory
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/backlight/message
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/backlight/mode
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/message
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/protocol/protocolv1/qrcode/message
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/ihm
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/constants)