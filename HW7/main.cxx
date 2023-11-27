#include "Matriks.hxx"
#include <cmath>
#include <format>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  cout << "A11.2022.14433\n" << endl;

  Matriks M = Matriks<GLfloat>(3, 2);
  M.from_vec(vector<GLfloat>{
      1, //
      4, //
      1, //

      4, //
      3, //
      1, //
  });

  cout << "Matriks M awal" << endl;
  M.print();
  cout << endl;

  Matriks Mt = M.translate_matriks(2, 5);
  cout << "Matriks M translated | T(2, 5)" << endl;
  Mt.print();
  cout << endl;

  Matriks Mts = Mt.scale_matriks_2d(6, 7);
  cout << "Matriks M translated, scaled | S(6, 7)" << endl;
  Mts.print();
  cout << endl;

  Matriks Mtsr = Mts.rotate_matriks_2d(270 * M_PI / 180);
  cout << "Matriks M translated, scaled, rotated | R(270)" << endl;
  Mtsr.print();
  cout << endl;

  Matriks Mtsrm = Mtsr.mirror_matriks_x();
  cout << "Matriks M translated, scaled, rotated, mirrored | M(x)" << endl;
  Mtsrm.print();
  cout << endl;

  return 0;
}
