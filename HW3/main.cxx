#include "lib/dda.hxx"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 5) {
    cerr << "masukan 4 argumen: 1x 1y 2x 2y" << endl;
    return -1;
  }

  vector<double> titik_awal = {stod(argv[1]), stod(argv[2])};
  vector<double> titik_akhir = {stod(argv[3]), stod(argv[4])};
  vector<double> dda_vec = dda(titik_awal, titik_akhir);
  for (int i = 0; i < dda_vec.size(); i++)
    cout << dda_vec[i] << ',' << dda_vec[++i] << endl;
}
