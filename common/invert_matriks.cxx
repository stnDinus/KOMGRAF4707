#include "Matriks.hxx"

Matriks2x2 invert_matriks(Matriks2x2 *input) {
  double determinan = 1. / (input->get_elemen(0, 0) * input->get_elemen(1, 1) -
                            input->get_elemen(0, 1) * input->get_elemen(1, 0));

  if (determinan == INFINITY) {
    std::cerr << "Error: matriks tidak memiliki invers" << std::endl;
    exit(1);
  }

  Matriks2x2 matriks_hasil = Matriks2x2();

  matriks_hasil.set_elemen(0, 0, determinan * input->get_elemen(1, 1));
  matriks_hasil.set_elemen(0, 1, determinan * input->get_elemen(0, 1) * -1);
  matriks_hasil.set_elemen(1, 0, determinan * input->get_elemen(1, 0) * -1);
  matriks_hasil.set_elemen(1, 1, determinan * input->get_elemen(0, 0));

  return matriks_hasil;
}
