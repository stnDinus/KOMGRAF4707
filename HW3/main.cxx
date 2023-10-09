#include "lib/dda.hxx"

#include <iostream>

int main() {
  std::vector<double> titik_awal = {-9, 4};
  std::vector<double> titik_akhir = {9, -1};
  std::vector<double> dda_arr = dda(titik_awal, titik_akhir);
  for (int i = 0; i < dda_arr.size(); i++)
    std::cout << dda_arr[i] << ',' << dda_arr[++i] << std::endl;
}
