#pragma once

#include "new_rand.hxx"
#include <iostream>

class Matriks {
  int dimensi_x, dimensi_y, **arr_2d;

public:
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

  // Methods
  void init_acak(int nilai_maks = 9);

  void print();
};
