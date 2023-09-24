#pragma once

#include <iostream>
#include "new_rand.hxx"

class Matriks {
  int dimensi_x, dimensi_y, **matriks;

public:
  // Constructors
  Matriks(int dimensi_x, int dimensi_y);

  // Destructor
  ~Matriks();

  // Getters & Setters
  int **get_matriks();
  void set_matriks(int **matriks);

  int get_dimensi_x();
  void set_dimensi_x(int x);

  int get_dimensi_y();
  void set_dimensi_y(int y);

  // Methods
  void init_acak(int nilai_maks = 9);

  void print();
};
