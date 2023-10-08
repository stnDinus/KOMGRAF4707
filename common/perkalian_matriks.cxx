#include "Matriks.hxx"

Matriks kali_matriks(Matriks *matriks_a, Matriks *matriks_b) {
  int dimensi_y = matriks_a->get_dimensi_y();
  int dimensi_x = matriks_b->get_dimensi_x();

  Matriks matriks_hasil = Matriks(dimensi_y, dimensi_x);

  int **arr_2d_matriks_hasil = matriks_hasil.get_arr_2d();

  for (int y = 0; y < dimensi_y; y++) {
    for (int x = 0; x < dimensi_x; x++) {
      arr_2d_matriks_hasil[y][x] = 0;
      for (int i = 0; i < matriks_a->get_dimensi_x(); i++) {
        arr_2d_matriks_hasil[y][x] +=
            matriks_a->get_arr_2d()[y][i] * matriks_b->get_arr_2d()[i][x];
      }
    }
  }

  return matriks_hasil;
}
