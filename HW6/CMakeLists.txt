cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(HW6)

add_executable(HW6 main.cxx)

add_subdirectory(../common ./common)
target_include_directories(HW6 PUBLIC ../common)

target_link_libraries(HW6 glfw Matriks draw_points)
