cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(HW7)

add_executable(HW7 main.cxx)

add_subdirectory(../common ./common)
target_include_directories(HW7 PUBLIC ../common)

target_link_libraries(HW7 Matriks draw_points)
