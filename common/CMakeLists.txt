add_library(new_rand new_rand.cxx)

add_library(Matriks Matriks.cxx penjumlahan_matrkis.cxx pengurangan_matriks.cxx
perkalian_matriks.cxx invert_matriks.cxx)

add_library(loadShaders loadShaders.cxx)
find_package(GLEW REQUIRED)
target_link_libraries(loadShaders GLEW)
