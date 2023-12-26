#include "Matriks.hxx"
#include <cmath>
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
  // A11.2022.14433
  Matriks A = Matriks<GLfloat>(3, 1);
  A.from_vec(std::vector<GLfloat>{3, 3, 1});

  Matriks B = Matriks<GLfloat>(3, 1);
  B.from_vec(std::vector<GLfloat>{4, 4, 1});

  cout << "Matriks Awal\n";
  cout << "Matriks A\n";
  A.print();
  cout << "Matriks B\n";
  B.print();
  cout << endl;

  Matriks translatedA = A.translate_matriks(5, 10);
  Matriks translatedB = B.translate_matriks(5, 10);

  cout << "Translasi(5, 10)\n";
  cout << "Matriks A\n";
  translatedA.print();
  cout << "Matriks B\n";
  translatedB.print();
  cout << endl;

  Matriks scaledA = A.scale_matriks_2d(5, 10);
  Matriks scaledB = B.scale_matriks_2d(5, 10);

  cout << "Scale(5, 10)\n";
  cout << "Matriks A\n";
  scaledA.print();
  cout << "Matriks B\n";
  scaledB.print();
  cout << endl;

  Matriks A_rotated = A.rotate_matriks_2d(20 * M_PI / 180 /* deg -> rad */);
  Matriks B_rotated = B.rotate_matriks_2d(20 * M_PI / 180 /* deg -> rad */);

  cout << "Rotate(20)\n";
  cout << "Matriks A\n";
  A_rotated.print();
  cout << "Matriks B\n";
  B_rotated.print();
  cout << endl;
}
