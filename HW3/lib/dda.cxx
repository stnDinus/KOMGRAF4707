#include "dda.hxx"

using namespace std;

vector<double> dda(vector<double> titik_awal, vector<double> titik_akhir) {
  double dx = titik_akhir[0] - titik_awal[0];
  double dy = titik_akhir[1] - titik_awal[1];

  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

  double x_increment = dx / steps;
  double y_increment = dy / steps;

  vector<double> return_vec((steps *= 2) + 2);
  return_vec[0] = titik_awal[0];
  return_vec[1] = titik_awal[1];
  for (int i = 2; i < steps; i++) {
    return_vec[i] = x_increment + return_vec[i - 2];
    return_vec[++i] = y_increment + return_vec[i - 1];
  }
  return_vec[steps] = titik_akhir[0];
  return_vec[steps + 1] = titik_akhir[1];

  return return_vec;
}
