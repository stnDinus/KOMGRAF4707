cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(T3D)

add_executable(T3D main.cxx)

add_subdirectory(../common ./common)
target_include_directories(T3D PUBLIC ../common)

target_link_libraries(T3D Matriks draw_points parse_args degs_to_rads)
