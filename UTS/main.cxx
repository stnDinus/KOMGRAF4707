#include "draw_points.hxx"

#include "Matriks.hxx"
#include "bresenham.hxx"
#include "dda.hxx"
#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
  unordered_map<string, GLfloat> args; // nilai-nilai default:
  args["-ax"] = 1;                     // - inisialisasi matriks NIM
  args["-ay"] = 4;                     // A11.2022.14433
  args["-bx"] = 3;                     // a(1, 4)
  args["-by"] = 3;                     // b(3, 3)
  args["-tx"] = 3;                     // - translasi x
  args["-ty"] = 2;                     // - translasi y
  args["-sx"] = 4;                     // - scaling x
  args["-sy"] = 5;                     // - scaling y
  args["-rdeg"] = 90;                  // - derajat rotasi
  for (int i = 1; i < argc; i++) {
    args.at(argv[i]) = stof(argv[i + 1]);
    i++;
  }

  Matriks a = Matriks<GLfloat>(3, 1);
  a.from_vec(std::vector<GLfloat>{
      args["-ax"], // x
      args["-ay"], // y
      1            // z / homogen
  });

  Matriks b = Matriks<GLfloat>(3, 1);
  b.from_vec(std::vector<GLfloat>{
      args["-bx"], // x
      args["-by"], // y
      1            // z / homogen
  });

  // 1a) DDA
  std::vector<GLfloat> dda_vec = dda(a.to_vec(), b.to_vec());
  Matriks dda_matriks = Matriks<GLfloat>(3, dda_vec.size() / 3);
  dda_matriks.from_vec(dda_vec);
  cout << "1a) Koordinat-koordinat DDA" << endl;
  dda_matriks.print();
  draw_points(dda_vec, "DDA");

  // 1b) bresenham
  std::vector<GLfloat> bresenham_vec = bresenham(a.to_vec(), b.to_vec());
  Matriks bresenham_matriks = Matriks<GLfloat>(3, bresenham_vec.size() / 3);
  bresenham_matriks.from_vec(bresenham_vec);
  cout << "1b) Koordinat-koordinat bresenham" << endl;
  bresenham_matriks.print();
  draw_points(bresenham_vec, "Bresenham");

  // 2) transformasi matriks
  Matriks c = Matriks<GLfloat>(3, 2);
  c.from_vec(std::vector<GLfloat>{
      a.arr_2d[0][0], //
      a.arr_2d[1][0], //
      a.arr_2d[2][0], //
      b.arr_2d[0][0], //
      b.arr_2d[1][0], //
      b.arr_2d[2][0], //
  });
  cout << "\n2) Transformasi matriks\n"
       << "Matriks awal" << endl;
  c.print();
  draw_points(c.to_vec(), "Matriks awal");

  // 2.1) translasi
  Matriks c_translated = c.translate_matriks(args["-tx"], args["-ty"]);
  cout << "Translasi(" << args["-tx"] << ", " << args["-ty"] << ")" << endl;
  c_translated.print();
  draw_points(c_translated.to_vec(), "Translasi");

  // 2.2) scaling
  Matriks c_scaled = c.scale_matriks_2d(args["-sx"], args["-sy"]);
  cout << "Scaling(" << args["-sx"] << ", " << args["-sy"] << ")" << endl;
  c_scaled.print();
  draw_points(c_scaled.to_vec(), "Scaling");

  // 2.3) rotasi
  Matriks c_rotated = c.rotate_matriks_2d(args["-rdeg"] * M_PI / 180);
  cout << "Scaling(" << args["-rdeg"] << ")" << endl;
  c_rotated.print();
  draw_points(c_rotated.to_vec(), "Rotasi");
}
