cmake_minimum_required(VERSION 3.27.7) 
project(challange_rentbrella)
set(CMAKE_CXX_STANDARD 17)
add_executable(challange_rentbrella 
    ../src/rb-ihm.cpp
    ../src/message.cpp
    ../src/backlight.cpp)
target_include_directories(challange_rentbrella PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)