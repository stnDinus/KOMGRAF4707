#include "Matriks.hxx"

/**
 * Menjumlahkan 2 buah input matriks !!DENGAN DIMENSI YANG SAMA yang berupa
 * sebuah array 2 dimensi
 * @param {int} dimensi_x - dimensi x kedua array
 * @param {int} dimensi_y - dimensi y kedua array
 * @param {int*} matriks_a - matriks pertama
 * @param {int*} matriks_b - matriks kedua
 * @returns {int**} matriks hasil penjumlahan
 */
int **tambah_matriks(int dimensi_x, int dimensi_y, int **matriks_a,
                     int **matriks_b) {
  int *matriks_hasil[dimensi_y];

  for (int y = 0; y < dimensi_y; y++) {
    int matriks_x[dimensi_x];
    for (int x = 0; x < dimensi_x; y++) {
      matriks_x[x] = matriks_a[x][y] + matriks_b[x][y];
    }
    matriks_hasil[y] = matriks_x;
  }

  return matriks_hasil;
}
