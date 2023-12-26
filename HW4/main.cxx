#include "draw_points.hxx"
#include "lib/bresenham.hxx"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 5) {
    cerr << "masukan 4 argumen: 1x 1y 2x 2y" << endl;
    return -1;
  }

  vector<GLfloat> titik_awal = {stof(argv[1]), stof(argv[2])};
  vector<GLfloat> titik_akhir = {stof(argv[3]), stof(argv[4])};

  vector<GLfloat> bresenham_vec = bresenham(titik_awal, titik_akhir);

  for (GLfloat i : bresenham_vec)
    cout << i << endl;

  draw_points(bresenham_vec);

  return 0;
}
