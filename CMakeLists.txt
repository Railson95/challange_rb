cmake_minimum_required(VERSION 3.27.7) 
project(challange_rentbrella)
set(CMAKE_CXX_STANDARD 17)
add_executable(challange_rentbrella 
    ../src/rb-ihm.cpp
    ../src/message/message.cpp
    ../src/backlight/command/backlight.cpp
    ../src/backlight/mode/mode.cpp
    ../src/backlight/mode/normal_mode.cpp
    ../src/backlight/mode/low_mode.cpp
    ../src/backlight/mode/period_mode.cpp
    ../src/backlight/mode/factory.cpp)
target_include_directories(challange_rentbrella PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/backlight/command
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/backlight/mode
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes/message)