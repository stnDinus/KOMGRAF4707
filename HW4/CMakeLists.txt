cmake_minimum_required(VERSION 3.27)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(HW4)

add_executable(HW4 main.cxx lib/bresenham.cxx)

add_subdirectory(../common ./common)
target_include_directories(HW4 PUBLIC ../common)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(HW4 glfw OpenGL::GL GLEW draw_points)
