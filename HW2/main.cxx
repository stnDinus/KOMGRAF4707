#include <iostream>

#include "./lib/Matriks.cxx"

int main() {
  int dimensi_x, dimensi_y;
  std::cout << "Masukan dimensi x dan y matriks dengan pemisah spasi: ";
  std::cin >> dimensi_x >> dimensi_y;

  Matriks matriks_a = Matriks(dimensi_x, dimensi_y);
  matriks_a.init_acak();
  std::cout << "Matriks A\n";
  matriks_a.print();

  Matriks matriks_b = Matriks(dimensi_x, dimensi_y);
  matriks_b.init_acak();
  std::cout << "Matriks B\n";
  matriks_b.print();

  return 0;
}
