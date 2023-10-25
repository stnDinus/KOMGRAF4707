#pragma once

#include "new_rand.hxx"
#include <iostream>

class Matriks {
public:
  int dimensi_x, dimensi_y, **arr_2d;
  // Constructors
  Matriks(int dimensi_y, int dimensi_x);

  // Destructor
  ~Matriks();

  // Getters & Setters
  int **get_arr_2d();
  void set_arr_2d(int **matriks);

  int get_dimensi_y();
  void set_dimensi_y(int y);

  int get_dimensi_x();
  void set_dimensi_x(int x);

  int get_elemen(int y, int x);
  void set_elemen(int y, int x, int e);

  // Methods
  void init_acak(int nilai_maks = 9);
  void translasi_matriks(int arr_penambah[], int n);

  void print();

  // Operator Overloads
  Matriks operator+(Matriks &matriks_b);
  Matriks operator-(Matriks &matriks_b);
  Matriks operator*(Matriks &matriks_b);
};

class Matriks2x2 : public Matriks {
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
Matriks tambah_matriks(Matriks *matriks_a, Matriks *matriks_b);

/**
 * Mengurangkan 2 buah input Matriks !!DENGAN DIMENSI YANG SAMA
 * @param {Matriks *} matriks_a - matriks pertama
 * @param {Matriks *} matriks_b - matriks kedua
 * @returns {Matriks} matriks hasil pengurangan
 */
Matriks kurang_matriks(Matriks *matriks_a, Matriks *matriks_b);

/**
 * Mengalikan 2 buah input Matriks !!DENGAN DIMENSI X MATRIKS A YANG SAMA DENGAN
 * DIMENSI Y MATRIKS B
 * @param {Matriks *} matriks_a - matriks pertama
 * @param {Matriks *} matriks_b - matriks kedua
 * @returns {Matriks} matriks hasil perkalian
 */
Matriks kali_matriks(Matriks *matriks_a, Matriks *matriks_b);

/**
 * Mengembalikan matriks baru hasil invers dari matriks input, jika matriks
 * tidak memiliki invers, hentikan program dengan kode error 1
 * @todo convert int -> double
 * @params {Matriks *} input - matriks input !! DENGAN DIMENSI 2x2
 * @returns {Matriks} invers dari matriks input
 */
Matriks2x2 invert_matriks(Matriks2x2 *input);
