#include "bresenham.hxx"

using namespace std;

vector<float> bresenham(vector<float> titik_awal, vector<float> titik_akhir) {
  vector<float> return_vec;

  int x0 = titik_awal[0], x1 = titik_akhir[0];
  int y0 = titik_awal[1], y1 = titik_akhir[1];

  int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = dx + dy, e2;

  while (true) {
    return_vec.push_back(x0);
    return_vec.push_back(y0);
    if (x0 == x1 && y0 == y1)
      break;
    e2 = 2 * err;
    if (e2 >= dy) {
      err += dy;
      x0 += sx;
    }
    if (e2 <= dx) {
      err += dx;
      y0 += sy;
    }
  }

  return return_vec;
}
