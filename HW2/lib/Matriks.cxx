#include <iostream>

#include "./new_rand.cxx"

class Matriks {
  int dimensi_x, dimensi_y, **matriks;

public:
  // Constructors
  Matriks(int dimensi_x, int dimensi_y) {
    this->dimensi_x = dimensi_x;
    this->dimensi_y = dimensi_y;
  };

  // Destructor
  ~Matriks() {
    for (int y = 0; y < dimensi_y; y++) {
      delete[] matriks[y];
    }
    delete[] matriks;
  }

  // Getters & Setters
  int **get_matriks() { return matriks; }
  void set_matriks(int **matriks) { this->matriks = matriks; }

  // Methods
  void init_acak(int nilai_maks = 9) {
    matriks = new int *[dimensi_y];

    for (int y = 0; y < dimensi_y; y++) {
      matriks[y] = new int[dimensi_x];
      for (int x = 0; x < dimensi_x; x++) {
        matriks[y][x] = new_rand(nilai_maks);
      }
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
