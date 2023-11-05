#include "Matriks.hxx"
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
  // A11.2022.14433
  Matriks A = Matriks<int>(2, 1);
  A.arr_2d[0][0] = 3;
  A.arr_2d[1][0] = 3;

  Matriks B = Matriks<int>(2, 1);
  B.arr_2d[0][0] = 4;
  B.arr_2d[1][0] = 4;

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

  Matriks A_rotated = A.rotate_matriks_2d(20);
  Matriks B_rotated = B.rotate_matriks_2d(20);

  cout << "Rotate(20)\n";
  cout << "Matriks A\n";
  A_rotated.print();
  cout << "Matriks B\n";
  B_rotated.print();
  cout << endl;
}
