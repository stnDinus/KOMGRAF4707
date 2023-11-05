#include "Matriks.hxx"

Matriks tambah_matriks(Matriks *matriks_a, Matriks *matriks_b) {
  int dimensi_x = matriks_a->dimensi_x;
  int dimensi_y = matriks_a->dimensi_y;

  Matriks matriks_hasil = Matriks(dimensi_x, dimensi_y);

  int **arr_2d_matriks_hasil = matriks_hasil.arr_2d;

  for (int y = 0; y < matriks_a->dimensi_y; y++) {
    int *matriks_hasil_x = new int[dimensi_x];

    for (int x = 0; x < dimensi_x; x++) {
      int nilai_a = matriks_a->arr_2d[y][x];
      int nilai_b = matriks_b->arr_2d[y][x];

      matriks_hasil_x[x] = nilai_a + nilai_b;
    }

    arr_2d_matriks_hasil[y] = matriks_hasil_x;
  }
  return matriks_hasil;
}
