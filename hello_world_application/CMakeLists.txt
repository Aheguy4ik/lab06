cmake_minimum_required(VERSION 3.10)
project(hello_world LANGUAGES CXX)

# Используем явный относительный путь
add_subdirectory(../formatter_ex_lib ${CMAKE_CURRENT_BINARY_DIR}/formatter_ex)

add_executable(hello_world hello_world.cpp)
target_include_directories(hello_world PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib
)
target_link_libraries(hello_world PRIVATE formatter_ex)
