find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_library(new_rand new_rand.cxx)

add_library(Matriks Matriks.cxx penjumlahan_matrkis.cxx pengurangan_matriks.cxx
perkalian_matriks.cxx invert_matriks.cxx)
target_link_libraries(Matriks OpenGL::GL new_rand)

add_library(loadShaders loadShaders.cxx)
target_link_libraries(loadShaders GLEW)

add_library(draw_points draw_points.cxx loadShaders.cxx)
target_link_libraries(draw_points GLEW OpenGL::GL glfw)

add_library(dda dda.cxx)

add_library(bresenham bresenham.cxx)

add_library(parse_args parse_args.cxx)

add_library(degs_to_rads degs_to_rads.cxx)
