#include "dda.hxx"
#include <cstdlib>

using namespace std;

vector<GLfloat> dda(vector<GLfloat> titik_awal, vector<GLfloat> titik_akhir) {
  GLfloat dx = titik_akhir[0] - titik_awal[0];
  GLfloat dy = titik_akhir[1] - titik_awal[1];

  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

  GLfloat x_increment = dx / steps;
  GLfloat y_increment = dy / steps;

  vector<GLfloat> return_vec((steps *= 3) + 3);
  return_vec[0] = titik_awal[0];
  return_vec[1] = titik_awal[1];
  return_vec[2] = 1;
  for (int i = 3; i < steps; i++) {
    return_vec[i] = x_increment + return_vec[i - 3];
    return_vec[++i] = y_increment + return_vec[i - 2];
    return_vec[++i] = 1;
  }
  return_vec[steps] = titik_akhir[0];
  return_vec[steps + 1] = titik_akhir[1];
  return_vec[steps + 2] = 1;

  return return_vec;
}
