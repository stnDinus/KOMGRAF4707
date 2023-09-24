#include <iostream>

#include "./new_rand.cxx"

class Matriks {
  int dimensi_x, dimensi_y, **matriks;

public:
  Matriks(int dimensi_x, int dimensi_y) {
    this->dimensi_x = dimensi_x;
    this->dimensi_y = dimensi_y;
  };

  void init_acak(int nilai_maks = 9) {
    *matriks = new int[dimensi_y];

    for (int y = 0; y < dimensi_y; y++) {

      int *matriks_x = new int[dimensi_x];
      for (int x = 0; x < dimensi_x; x++) {
        matriks_x[x] = new_rand(nilai_maks);
      }

      matriks[y] = matriks_x;
    }
  }

  void print() {
    for (int y = 0; y < dimensi_y; y++) {
      std::cout << "│ ";

      for (int x = 0; x < dimensi_x; x++)
        std::cout << matriks[y][x] << " ";

      std::cout << "│\n";
    }
  }
};
