#include <iostream>

#include "Matriks.hxx"
#include "penjumlahan_matrkis.cxx"

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

  std::cout << "Matriks Hasil Penjumlahan\n";
  Matriks matriks_hasil_penjumlahan = tambah_matriks(&matriks_a, &matriks_b);
  matriks_hasil_penjumlahan.print();

  return 0;
}
