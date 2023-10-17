#import "draw_points.hxx"
#import "lib/bresenham.hxx"
#import <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 5) {
    cerr << "masukan 4 argumen: 1x 1y 2x 2y" << endl;
    return -1;
  }

  vector<float> titik_awal = {stof(argv[1]), stof(argv[2])};
  vector<float> titik_akhir = {stof(argv[3]), stof(argv[4])};

  vector<float> bresenham_vec = bresenham(titik_awal, titik_akhir);
  for (int i = 0; i < bresenham_vec.size(); i++) {
    cout << bresenham_vec[i] << endl;
    bresenham_vec[i] /= 10;
  }

  draw_points(bresenham_vec);

  return 0;
}
