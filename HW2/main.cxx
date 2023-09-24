#include <iostream>

#include "./lib/Matriks.cxx"

int main(int argc, char *argv[]) {
  // int dimensi_x;
  // int dimensi_y;
  // std::cout << "Masukan dimensi x dan y matriks a, dengan pemisah spasi: ";
  // std::cin >> dimensi_x >> dimensi_y;

  Matriks matriks_a = Matriks(3, 3);
  matriks_a.init_acak();
  matriks_a.print();

  return 0;
}
