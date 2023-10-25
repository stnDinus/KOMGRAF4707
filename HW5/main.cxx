#include "Matriks.hxx"

int main(int argc, char *argv[]) {
  Matriks2d m = Matriks2d(2);
  m.init_acak();
  m.print();
  const int n = 2;
  int arr_penambah[n] = {1, 1};
  m.translasi_matriks(arr_penambah, n);
  m.print();
}
