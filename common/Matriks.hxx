#pragma once

#include "new_rand.hxx"
#include <GL/gl.h>
#include <iostream>
#include <math.h>

template <typename T> class Matriks {
public:
  int dimensi_x, dimensi_y;
  T **arr_2d;
  // Constructors
  Matriks(int dimensi_y, int dimensi_x);

  // Destructor
  ~Matriks();

  // Methods
  void init_acak(int nilai_maks = 9);
  void from_vec(std::vector<T> vec);
  std::vector<T> to_vec();
  void print();
  // untuk matriks posisi 2 dimensi + 1 dimensi homogen
  Matriks translate_matriks(T x, T y);
  Matriks scale_matriks_2d(T x, T y);
  Matriks rotate_matriks_2d(T rad);
  Matriks mirror_matriks_x();
  Matriks mirror_matriks_y();
  Matriks mirror_matriks_d();

  // Operator Overloads
  Matriks<T> operator+(Matriks<T> &matriks_b);
  Matriks<T> operator-(Matriks<T> &matriks_b);
  Matriks<T> operator*(Matriks<T> &matriks_b);
};

template <typename T> class Matriks2x2 : public Matriks<T> {
public:
  // Constructors
  Matriks2x2();

  // Operator Overloads
  Matriks2x2 operator!();
};

/**
 * Menjumlahkan 2 buah input Matriks !!DENGAN DIMENSI YANG SAMA
 * @param {Matriks *} matriks_a - matriks pertama
 * @param {Matriks *} matriks_b - matriks kedua
 * @returns {Matriks} matriks hasil penjumlahan
 */
template <typename T>
Matriks<T> tambah_matriks(Matriks<T> *matriks_a, Matriks<T> *matriks_b);

/**
 * Mengurangkan 2 buah input Matriks !!DENGAN DIMENSI YANG SAMA
 * @param {Matriks *} matriks_a - matriks pertama
 * @param {Matriks *} matriks_b - matriks kedua
 * @returns {Matriks} matriks hasil pengurangan
 */
template <typename T>
Matriks<T> kurang_matriks(Matriks<T> *matriks_a, Matriks<T> *matriks_b);

/**
 * Mengalikan 2 buah input Matriks !!DENGAN DIMENSI X MATRIKS A YANG SAMA DENGAN
 * DIMENSI Y MATRIKS B
 * @param {Matriks *} matriks_a - matriks pertama
 * @param {Matriks *} matriks_b - matriks kedua
 * @returns {Matriks} matriks hasil perkalian
 */
template <typename T>
Matriks<T> kali_matriks(Matriks<T> *matriks_a, Matriks<T> *matriks_b);

/**
 * Mengembalikan matriks baru hasil invers dari matriks input, jika matriks
 * tidak memiliki invers, hentikan program dengan kode error 1
 * @todo convert int -> double
 * @params {Matriks *} input - matriks input !! DENGAN DIMENSI 2x2
 * @returns {Matriks} invers dari matriks input
 */
template <typename T> Matriks2x2<T> invert_matriks(Matriks2x2<T> *input);
