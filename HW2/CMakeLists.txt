cmake_minimum_required(VERSION 3.26)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(HW2)

add_executable(HW2 main.cxx)

target_include_directories(HW2 PUBLIC "${PROJECT_SOURCE_DIR}/lib")

add_subdirectory(lib)

target_link_libraries(HW2 Matriks)
target_link_libraries(HW2 new_rand)
