#include "Matriks.hxx"

/**
 * Mengembalikan matriks baru hasil invers dari matriks input, jika matriks
 * tidak memiliki invers, hentikan program dengan kode error 1
 * @todo convert int -> double
 * @params {Matriks *} input - matriks input !! DENGAN DIMENSI 2x2
 * @returns {Matriks} invers dari matriks input
 */
Matriks invert_matriks(Matriks *input) {
  double determinan = 1. / (input->get_elemen(0, 0) * input->get_elemen(1, 1) -
                            input->get_elemen(0, 1) * input->get_elemen(1, 0));

  if (determinan == INFINITY) {
    std::cerr << "Error: matriks tidak memiliki invers" << std::endl;
    exit(1);
  }

  Matriks matriks_hasil = Matriks(2, 2);

  matriks_hasil.set_elemen(0, 0, determinan * input->get_elemen(1, 1));
  matriks_hasil.set_elemen(0, 1, determinan * input->get_elemen(0, 1) * -1);
  matriks_hasil.set_elemen(1, 0, determinan * input->get_elemen(1, 0) * -1);
  matriks_hasil.set_elemen(1, 1, determinan * input->get_elemen(0, 0));

  return matriks_hasil;
}
