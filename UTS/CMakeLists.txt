cmake_minimum_required(VERSION 3.27)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(uts)

add_executable(uts main.cxx)

add_subdirectory(../common common)
target_include_directories(uts PUBLIC ../common)

target_link_libraries(uts Matriks draw_points dda bresenham)
