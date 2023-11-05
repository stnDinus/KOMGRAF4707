#include <iostream>

#include "Matriks.hxx"

int main() {
  Matriks2x2<int> matriks_a;
  matriks_a.init_acak();
  std::cout << "Matriks A\n";
  matriks_a.print();

  Matriks2x2<int> matriks_b;
  matriks_b.init_acak();
  std::cout << "Matriks B\n";
  matriks_b.print();

  // PENJUMLAHAN
  std::cout << "Matriks Hasil Penjumlahan\n";
  Matriks matriks_hasil_penjumlahan = matriks_a + matriks_b;
  matriks_hasil_penjumlahan.print();

  // PENGURANGAN
  std::cout << "Matriks Hasil Pengurangan\n";
  Matriks matriks_hasil_pengurangan = matriks_hasil_penjumlahan - matriks_b;
  matriks_hasil_pengurangan.print();

  // PERKALIAN
  std::cout << "Matriks Hasil Perkalian\n";
  Matriks matriks_hasil_perkalian = matriks_a * matriks_b;
  matriks_hasil_perkalian.print();

  // PEMBAGIAN
  std::cout << "Matriks Hasil Pembagian\n";
  Matriks2x2 matriks_b_invers = !matriks_b;
  Matriks matriks_hasil_pembagian = matriks_a * matriks_b_invers;
  matriks_hasil_pembagian.print();

  return 0;
}
