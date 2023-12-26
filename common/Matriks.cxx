#include "./Matriks.hxx"
#include "new_rand.hxx"
#include <iostream>
#include <math.h>

// Constructors
template <typename T> Matriks<T>::Matriks(int dimensi_y, int dimensi_x) {
  this->dimensi_x = dimensi_x;
  this->dimensi_y = dimensi_y;
  this->arr_2d = new T *[dimensi_y];

  for (int y = 0; y < dimensi_y; y++) {
    this->arr_2d[y] = new T[dimensi_x];
  }
};

template <typename T> Matriks2x2<T>::Matriks2x2() : Matriks<T>(2, 2){};

// Destructor
template <typename T> Matriks<T>::~Matriks() {
  for (int y = 0; y < dimensi_y; y++) {
    delete[] arr_2d[y];
  }
  delete[] arr_2d;
}

// Methods
template <typename T> void Matriks<T>::init_acak(int nilai_maks) {
  for (int y = 0; y < dimensi_y; y++) {
    for (int x = 0; x < dimensi_x; x++) {
      arr_2d[y][x] = new_rand(nilai_maks);
    }
  }
}

template <typename T> std::vector<T> Matriks<T>::to_vec() {
  std::vector<T> return_vec(this->dimensi_x * this->dimensi_y);
  int i = 0;
  for (int x = 0; x < this->dimensi_x; x++) {
    for (int y = 0; y < this->dimensi_y; y++) {
      return_vec[i++] = this->arr_2d[y][x];
    }
  }
  return return_vec;
}

template <typename T> void Matriks<T>::from_vec(std::vector<T> vec) {
  int i = 0;
  for (int x = 0; x < this->dimensi_x; x++) {
    for (int y = 0; y < this->dimensi_y; y++) {
      this->arr_2d[y][x] = vec[i++];
    }
  }
}

template <typename T> void Matriks<T>::print() {
  for (int y = 0; y < dimensi_y; y++) {
    std::cout << "│ ";

    for (int x = 0; x < dimensi_x; x++)
      std::cout << arr_2d[y][x] << " ";

    std::cout << "│\n";
  }
}

template <typename T> Matriks<T> Matriks<T>::translate_matriks(T x, T y) {
  Matriks matriks_perkalian = Matriks(3, 3);
  matriks_perkalian.from_vec(std::vector<T>{
      1, //
      0, //
      0, //

      0, //
      1, //
      0, //

      x, //
      y, //
      1, //
  });
  return matriks_perkalian * *this;
}

template <typename T> Matriks<T> Matriks<T>::scale_matriks_2d(T x, T y) {
  Matriks matriks_perkalian = Matriks(3, 3);
  matriks_perkalian.from_vec(std::vector<T>{
      x, //
      0, //
      0, //

      0,
      y, //
      0, //

      0, //
      0, //
      1, //
  });
  return matriks_perkalian * *this;
}

template <typename T> Matriks<T> Matriks<T>::rotate_matriks_2d(T rad) {
  Matriks matriks_perkalian = Matriks(3, 3);
  matriks_perkalian.from_vec(std::vector<T>{
      static_cast<T>(cos(rad)), //
      static_cast<T>(sin(rad)), //
      0,                        //

      static_cast<T>(sin(rad)) * -1, //
      static_cast<T>(cos(rad)),      //
      0,                             //

      0, //
      0, //
      1, //
  });
  return matriks_perkalian * *this;
};

template <typename T> Matriks<T> Matriks<T>::mirror_matriks_x() {
  Matriks matriks_perkalian = Matriks(3, 3);
  matriks_perkalian.from_vec(std::vector<T>{
      1, //
      0, //
      0, //

      0,  //
      -1, //
      0,  //

      0, //
      0, //
      1, //
  });

  return matriks_perkalian * *this;
}

template <typename T> Matriks<T> Matriks<T>::mirror_matriks_y() {
  Matriks matriks_perkalian = Matriks(3, 3);
  matriks_perkalian.from_vec(std::vector<T>{
      -1, //
      0,  //
      0,  //

      0, //
      1, //
      0, //

      0, //
      0, //
      1, //
  });

  return matriks_perkalian * *this;
}

template <typename T> Matriks<T> Matriks<T>::mirror_matriks_d() {
  Matriks matriks_perkalian = Matriks(3, 3);
  matriks_perkalian.from_vec(std::vector<T>{
      0, //
      1, //
      0, //

      1, //
      0, //
      0, //

      0, //
      0, //
      1, //
  });

  return matriks_perkalian * *this;
}

template <typename T>
Matriks<T> Matriks<T>::translate_matriks_3d(T x, T y, T z) {
  Matriks matriks_perkalian = Matriks(4, 4);
  matriks_perkalian.from_vec(std::vector<T>{
      1, //
      0, //
      0, //
      0, //

      0, //
      1, //
      0, //
      0, //

      0, //
      0, //
      1, //
      0, //

      x, //
      y, //
      z, //
      1, //
  });
  return matriks_perkalian * *this;
}

template <typename T> Matriks<T> Matriks<T>::scale_matriks_3d(T x, T y, T z) {
  Matriks matriks_perkalian(4, 4);
  matriks_perkalian.from_vec(std::vector<T>{
      x, //
      0, //
      0, //
      0, //

      0, //
      y, //
      0, //
      0, //

      0, //
      0, //
      z, //
      0, //

      0, //
      0, //
      0, //
      1, //
  });
  return matriks_perkalian * *this;
}

template <typename T> Matriks<T> Matriks<T>::rotate_matriks_3d_x(T rad) {
  Matriks<T> matriks_perkalian(4, 4);
  matriks_perkalian.from_vec(std::vector<T>{
      1, //
      0, //
      0, //
      0, //

      0,                        //
      static_cast<T>(cos(rad)), //
      static_cast<T>(sin(rad)), //
      0,                        //

      0,                             //
      static_cast<T>(sin(rad)) * -1, //
      static_cast<T>(cos(rad)),      //
      0,                             //

      0, //
      0, //
      0, //
      1, //
  });
  return matriks_perkalian * *this;
};

template <typename T> Matriks<T> Matriks<T>::rotate_matriks_3d_y(T rad) {
  Matriks<T> matriks_perkalian(4, 4);
  matriks_perkalian.from_vec(std::vector<T>{
      static_cast<T>(cos(rad)),      //
      0,                             //
      static_cast<T>(sin(rad)) * -1, //
      0,                             //

      0, //
      1, //
      0, //
      0, //

      static_cast<T>(sin(rad)), //
      0,                        //
      static_cast<T>(cos(rad)), //
      0,                        //

      0, //
      0, //
      0, //
      1, //
  });
  return matriks_perkalian * *this;
}
// Operator Overloads
template <typename T> Matriks<T> Matriks<T>::operator+(Matriks &matriks_b) {
  return tambah_matriks(this, &matriks_b);
}

template <typename T> Matriks<T> Matriks<T>::operator-(Matriks &matriks_b) {
  return kurang_matriks(this, &matriks_b);
}

template <typename T> Matriks<T> Matriks<T>::operator*(Matriks &matriks_b) {
  return kali_matriks(this, &matriks_b);
}

template <typename T> Matriks2x2<T> Matriks2x2<T>::operator!() {
  return invert_matriks(this);
}

template class Matriks<int>;
template class Matriks<GLfloat>;
template class Matriks2x2<int>;
template class Matriks2x2<GLfloat>;
