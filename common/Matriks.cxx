#include "./Matriks.hxx"

// Constructors
template <typename T> Matriks<T>::Matriks(int dimensi_y, int dimensi_x) {
  this->dimensi_x = dimensi_x;
  this->dimensi_y = dimensi_y;
  this->arr_2d = new T *[dimensi_y];

  for (int y = 0; y < dimensi_y; y++) {
    this->arr_2d[y] = new T[dimensi_x];
  }
};

template <typename T> Matriks2x2<T>::Matriks2x2() : Matriks<T>(2, 2){};

// Destructor
template <typename T> Matriks<T>::~Matriks() {
  for (int y = 0; y < dimensi_y; y++) {
    delete[] arr_2d[y];
  }
  delete[] arr_2d;
}

// Methods
template <typename T> void Matriks<T>::init_acak(int nilai_maks) {
  for (int y = 0; y < dimensi_y; y++) {
    for (int x = 0; x < dimensi_x; x++) {
      arr_2d[y][x] = new_rand(nilai_maks);
    }
  }
}

template <typename T> void Matriks<T>::print() {
  for (int y = 0; y < dimensi_y; y++) {
    std::cout << "│ ";

    for (int x = 0; x < dimensi_x; x++)
      std::cout << arr_2d[y][x] << " ";

    std::cout << "│\n";
  }
}

template <typename T>
void Matriks<T>::translate_matriks(int arr_penambah[], int n) {
  for (int y = 0; y < this->dimensi_y; y++) {
    for (int x = 0; x < n; x++) {
      arr_2d[y][x] += arr_penambah[y];
    }
  }
}

template <typename T> Matriks<T> Matriks<T>::scale_matriks_2d(int x, int y) {
  Matriks matriks_perkalian = Matriks(2, 2);
  matriks_perkalian.arr_2d[0][0] = x;
  matriks_perkalian.arr_2d[0][1] = 0;
  matriks_perkalian.arr_2d[1][0] = 0;
  matriks_perkalian.arr_2d[1][1] = y;

  return matriks_perkalian * *this;
}

template <typename T> Matriks<T> Matriks<T>::rotate_matriks_2d(int deg) {
  Matriks matriks_rotasi = Matriks(2, 2);
  matriks_rotasi.arr_2d[0][0] = round(cos(deg));
  matriks_rotasi.arr_2d[0][1] = round(sin(deg));
  matriks_rotasi.arr_2d[1][0] = round(sin(deg));
  matriks_rotasi.arr_2d[1][1] = round(cos(deg));

  return matriks_rotasi * *this;
};

// Operator Overloads
template <typename T> Matriks<T> Matriks<T>::operator+(Matriks &matriks_b) {
  return tambah_matriks(this, &matriks_b);
}

template <typename T> Matriks<T> Matriks<T>::operator-(Matriks &matriks_b) {
  return kurang_matriks(this, &matriks_b);
}

template <typename T> Matriks<T> Matriks<T>::operator*(Matriks &matriks_b) {
  return kali_matriks(this, &matriks_b);
}

template <typename T> Matriks2x2<T> Matriks2x2<T>::operator!() {
  return invert_matriks(this);
}

template class Matriks<int>;
template class Matriks<GLfloat>;
template class Matriks2x2<int>;
template class Matriks2x2<GLfloat>;
