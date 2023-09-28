#include <iostream>

#include "Matriks.hxx"

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
  Matriks matriks_hasil_pengurangan =
      kurang_matriks(&matriks_hasil_penjumlahan, &matriks_b);
  matriks_hasil_pengurangan.print();

  // PERKALIAN
  std::cout << "Matriks Hasil Perkalian\n";
  Matriks matriks_hasil_perkalian = kali_matriks(&matriks_a, &matriks_b);
  matriks_hasil_perkalian.print();

  // PEMBAGIAN
  std::cout << "Matriks Hasil Pembagian\n";
  Matriks matriks_b_invers = invert_matriks(&matriks_b);
  Matriks matriks_hasil_pembagian = kali_matriks(&matriks_a, &matriks_b_invers);
  matriks_hasil_pembagian.print();

  return 0;
}
