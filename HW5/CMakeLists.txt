cmake_minimum_required(VERSION 3.26)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(HW5)

add_executable(HW5 main.cxx)

target_include_directories(HW5 PUBLIC ../common/)

add_subdirectory(../common ./common)

target_link_libraries(HW5 Matriks new_rand)
