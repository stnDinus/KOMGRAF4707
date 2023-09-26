#include <iostream>

#include "Matriks.hxx"
#include "penjumlahan_matrkis.cxx"
#include "pengurangan_matriks.cxx"
#include "perkalian_matriks.cxx"

int main() {
  int dimensi_x_a, dimensi_y_a;
  std::cout << "Masukan dimensi matriks a (y x): ";
  std::cin >> dimensi_y_a >> dimensi_x_a;

  int dimensi_x_b, dimensi_y_b;
  std::cout << "Masukan dimensi matriks b (y x): ";
  std::cin >> dimensi_y_b >> dimensi_x_b;

  Matriks matriks_a = Matriks(dimensi_y_a, dimensi_x_a);
  matriks_a.init_acak();
  std::cout << "Matriks A\n";
  matriks_a.print();

  Matriks matriks_b = Matriks(dimensi_y_b, dimensi_x_b);
  matriks_b.init_acak();
  std::cout << "Matriks B\n";
  matriks_b.print();

  // PENJUMLAHAN
  std::cout << "Matriks Hasil Penjumlahan\n";
  Matriks matriks_hasil_penjumlahan = tambah_matriks(&matriks_a, &matriks_b);
  matriks_hasil_penjumlahan.print();

  // PENGURANGAN
  std::cout << "Matriks Hasil Pengurangan\n";
  Matriks matriks_hasil_pengurangan = kurang_matriks(&matriks_hasil_penjumlahan, &matriks_b);
  matriks_hasil_pengurangan.print();

  // PERKALIAN
  std::cout << "Matriks Hasil Perkalian\n";
  Matriks matriks_hasil_perkalian = kali_matriks(&matriks_a, &matriks_b);
  matriks_hasil_perkalian.print();

  return 0;
}
