#include "lib/dda.hxx"
#include "lib/draw_points.hxx"

using namespace std;

int main(int argc, char **argv) {
  if (argc != 5) {
    cerr << "masukan 4 argumen: 1x 1y 2x 2y" << endl;
    return -1;
  }

  vector<float> titik_awal = {stof(argv[1]), stof(argv[2])};
  vector<float> titik_akhir = {stof(argv[3]), stof(argv[4])};
  vector<float> dda_vec = dda(titik_awal, titik_akhir);

  vector<GLfloat> GLddaVec(dda_vec.size() / 2 * 3);
  const int ddaMaxVal = 10;
  for (int i = 0, i2 = 0; i < GLddaVec.size(); i++, i2++) {
    GLddaVec[i] = GLfloat(dda_vec[i2]) / ddaMaxVal;
    GLddaVec[++i] = GLfloat(dda_vec[++i2]) / ddaMaxVal;
    GLddaVec[++i] = 0;
  }

  draw_points(GLddaVec);
}
