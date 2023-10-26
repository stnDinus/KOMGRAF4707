#include "Matriks.hxx"
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
  // A11.2022.14433
  Matriks A = Matriks(2, 1);
  A.set_elemen(0, 0, 3);
  A.set_elemen(1, 0, 3);

  Matriks B = Matriks(2, 1);
  B.set_elemen(0, 0, 4);
  B.set_elemen(1, 0, 4);

  cout << "Matriks Awal\n";
  cout << "Matriks A\n";
  A.print();
  cout << "Matriks B\n";
  B.print();
  cout << endl;

  int arr_penambah[] = {5, 10};
  A.translate_matriks(arr_penambah, 2);
  B.translate_matriks(arr_penambah, 2);

  cout << "Translasi(5, 10)\n";
  cout << "Matriks A\n";
  A.print();
  cout << "Matriks B\n";
  B.print();
  cout << endl;

  Matriks A_scaled = A.scale_matriks_2d(2, 2);
  Matriks B_scaled = B.scale_matriks_2d(2, 2);

  cout << "Scale(5, 10)\n";
  cout << "Matriks A\n";
  A_scaled.print();
  cout << "Matriks B\n";
  B_scaled.print();
  cout << endl;
}
