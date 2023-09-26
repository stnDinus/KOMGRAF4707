#include "Matriks.hxx"

/**
 * Mengurangkan 2 buah input Matriks !!DENGAN DIMENSI YANG SAMA
 * @param {Matriks *} matriks_a - matriks pertama
 * @param {Matriks *} matriks_b - matriks kedua
 * @returns {Matriks} matriks hasil pengurangan
 */
Matriks kurang_matriks(Matriks *matriks_a, Matriks *matriks_b) {
  int dimensi_x = matriks_a->get_dimensi_x();
  int dimensi_y = matriks_a->get_dimensi_y();

  Matriks matriks_hasil = Matriks(dimensi_x, dimensi_y);

  int **arr_2d_matriks_hasil = matriks_hasil.get_arr_2d();

  for (int y = 0; y < matriks_a->get_dimensi_y(); y++) {
    int *matriks_hasil_x = new int[dimensi_x];

    for (int x = 0; x < dimensi_x; x++) {
      int nilai_a = matriks_a->get_elemen_at(y, x);
      int nilai_b = matriks_b->get_elemen_at(y, x);

      matriks_hasil_x[x] = nilai_a - nilai_b;
    }

    arr_2d_matriks_hasil[y] = matriks_hasil_x;
  }
  return matriks_hasil;
}
