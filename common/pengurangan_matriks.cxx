#include "Matriks.hxx"

template <typename T>
Matriks<T> kurang_matriks(Matriks<T> *matriks_a, Matriks<T> *matriks_b) {
  int dimensi_x = matriks_a->dimensi_x;
  int dimensi_y = matriks_a->dimensi_y;

  Matriks matriks_hasil = Matriks<T>(dimensi_x, dimensi_y);

  T **arr_2d_matriks_hasil = matriks_hasil.arr_2d;

  for (int y = 0; y < matriks_a->dimensi_y; y++) {
    T *matriks_hasil_x = new T[dimensi_x];

    for (int x = 0; x < dimensi_x; x++) {
      int nilai_a = matriks_a->arr_2d[y][x];
      int nilai_b = matriks_b->arr_2d[y][x];

      matriks_hasil_x[x] = nilai_a - nilai_b;
    }

    arr_2d_matriks_hasil[y] = matriks_hasil_x;
  }
  return matriks_hasil;
}

template Matriks<int> kurang_matriks(Matriks<int> *matriks_a,
                                     Matriks<int> *matriks_b);
template Matriks<GLfloat> kurang_matriks(Matriks<GLfloat> *matriks_a,
                                         Matriks<GLfloat> *matriks_b);
