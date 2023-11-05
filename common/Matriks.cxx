#include "./Matriks.hxx"

// Constructors
Matriks::Matriks(int dimensi_y, int dimensi_x) {
  this->dimensi_x = dimensi_x;
  this->dimensi_y = dimensi_y;
  this->arr_2d = new int *[dimensi_y];

  for (int y = 0; y < dimensi_y; y++) {
    this->arr_2d[y] = new int[dimensi_x];
  }
};

Matriks2x2::Matriks2x2() : Matriks(2, 2){};

// Destructor
Matriks::~Matriks() {
  for (int y = 0; y < dimensi_y; y++) {
    delete[] arr_2d[y];
  }
  delete[] arr_2d;
}

// Methods
void Matriks::init_acak(int nilai_maks) {
  for (int y = 0; y < dimensi_y; y++) {
    for (int x = 0; x < dimensi_x; x++) {
      arr_2d[y][x] = new_rand(nilai_maks);
    }
  }
}

void Matriks::print() {
  for (int y = 0; y < dimensi_y; y++) {
    std::cout << "│ ";

    for (int x = 0; x < dimensi_x; x++)
      std::cout << arr_2d[y][x] << " ";

    std::cout << "│\n";
  }
}

void Matriks::translate_matriks(int arr_penambah[], int n) {
  for (int y = 0; y < this->dimensi_y; y++) {
    for (int x = 0; x < n; x++) {
      arr_2d[y][x] += arr_penambah[y];
    }
  }
}

Matriks Matriks::scale_matriks_2d(int x, int y) {
  Matriks matriks_perkalian = Matriks(2, 2);
  matriks_perkalian.arr_2d[0][0] = x;
  matriks_perkalian.arr_2d[0][1] = 0;
  matriks_perkalian.arr_2d[1][0] = 0;
  matriks_perkalian.arr_2d[1][1] = y;

  return matriks_perkalian * *this;
}
Matriks Matriks::rotate_matriks_2d(int deg) {
  Matriks matriks_rotasi = Matriks(2, 2);
  matriks_rotasi.arr_2d[0][0] = round(cos(deg));
  matriks_rotasi.arr_2d[0][1] = round(sin(deg));
  matriks_rotasi.arr_2d[1][0] = round(sin(deg));
  matriks_rotasi.arr_2d[1][1] = round(cos(deg));

  return matriks_rotasi * *this;
};

// Operator Overloads
Matriks Matriks::operator+(Matriks &matriks_b) {
  return tambah_matriks(this, &matriks_b);
}

Matriks Matriks::operator-(Matriks &matriks_b) {
  return kurang_matriks(this, &matriks_b);
}

Matriks Matriks::operator*(Matriks &matriks_b) {
  return kali_matriks(this, &matriks_b);
}

Matriks2x2 Matriks2x2::operator!() { return invert_matriks(this); }
