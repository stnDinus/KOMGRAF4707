#pragma once

#include <cstdlib>
#include <vector>

/**
 * @param titik_awal vector berisi 2 nilai posisi (x, y)
 * @param titik_akhir vector berisi 2 nilai posisi (x, y)
 * @returns vector berisi nilai-nilai posisi setiap titik
 */
std::vector<double> dda(std::vector<double> titik_awal,
                        std::vector<double> titik_akhir);
