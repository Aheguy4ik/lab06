cmake_minimum_required(VERSION 3.10)
project(solver_app)

add_executable(solver equation.cpp)
target_include_directories(solver PRIVATE
    ${CMAKE_SOURCE_DIR}/formatter_ex_lib
    ${CMAKE_SOURCE_DIR}/solver_lib
)
target_link_libraries(solver PRIVATE formatter_ex solver_lib)
