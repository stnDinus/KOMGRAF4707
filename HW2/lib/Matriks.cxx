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

// Destructor
Matriks::~Matriks() {
  for (int y = 0; y < dimensi_y; y++) {
    delete[] arr_2d[y];
  }
  delete[] arr_2d;
}

// Getters & Setters
int **Matriks::get_arr_2d() { return arr_2d; }
void Matriks::set_arr_2d(int **matriks) { this->arr_2d = matriks; }

int Matriks::get_dimensi_y() { return dimensi_y; }
void Matriks::set_dimensi_y(int y) { this->dimensi_y = y; }

int Matriks::get_dimensi_x() { return dimensi_x; }
void Matriks::set_dimensi_x(int x) { this->dimensi_x = x; }

int Matriks::get_elemen(int y, int x) { return arr_2d[y][x]; };
void Matriks::set_elemen(int y, int x, int e) { arr_2d[y][x] = e; };

// Methods
void Matriks::init_acak(int nilai_maks) {
  for (int y = 0; y < dimensi_y; y++) {
    arr_2d[y] = new int[dimensi_x];
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
