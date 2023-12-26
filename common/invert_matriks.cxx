#include "Matriks.hxx"
#include <cmath>
#include <iostream>

template <typename T> Matriks2x2<T> invert_matriks(Matriks2x2<T> *input) {
  double determinan = 1. / (input->arr_2d[0][0] * input->arr_2d[1][1] -
                            input->arr_2d[0][1] * input->arr_2d[1][0]);

  if (determinan == INFINITY) {
    std::cerr << "Error: matriks tidak memiliki invers" << std::endl;
    exit(1);
  }

  Matriks2x2 matriks_hasil = Matriks2x2<T>();

  matriks_hasil.arr_2d[0][0] = determinan * input->arr_2d[1][1];
  matriks_hasil.arr_2d[0][1] = determinan * input->arr_2d[0][1] * -1;
  matriks_hasil.arr_2d[1][0] = determinan * input->arr_2d[1][0] * -1;
  matriks_hasil.arr_2d[1][1] = determinan * input->arr_2d[0][0];

  return matriks_hasil;
}

template Matriks2x2<int> invert_matriks(Matriks2x2<int> *input);
template Matriks2x2<GLfloat> invert_matriks(Matriks2x2<GLfloat> *input);
