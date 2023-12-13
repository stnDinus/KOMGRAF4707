cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(HW8)

add_executable(HW8 main.cxx)

add_subdirectory(../common ./common)
target_include_directories(HW8 PUBLIC ../common)

target_link_libraries(HW8 Matriks draw_points)
