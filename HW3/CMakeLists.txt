cmake_minimum_required(VERSION 3.27)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(HW3)

add_executable(HW3 main.cxx)

# custom libs
target_include_directories(HW3 PUBLIC ../common/)

add_subdirectory(../common ./common)

target_link_libraries(HW3 Matriks)
target_link_libraries(HW3 new_rand)

# system libs
find_package(glfw3 REQUIRED)
target_link_libraries(HW3 glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(HW3 OpenGL::GL)

find_package(GLEW REQUIRED)
target_link_libraries(HW3 GLEW)

