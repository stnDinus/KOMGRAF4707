#pragma once

#include <GL/gl.h>
#include <vector>

/**
 * @param titik_awal vector berisi 2 nilai posisi (x, y)
 * @param titik_akhir vector berisi 2 nilai posisi (x, y)
 * @returns vector berisi nilai-nilai posisi setiap titik
 */
std::vector<GLfloat> dda(std::vector<GLfloat> titik_awal,
                         std::vector<GLfloat> titik_akhir);
