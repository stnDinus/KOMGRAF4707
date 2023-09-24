#include "./Matriks.hxx"

// Constructors
Matriks::Matriks(int dimensi_x, int dimensi_y) {
  this->dimensi_x = dimensi_x;
  this->dimensi_y = dimensi_y;
};

// Destructor
Matriks::~Matriks() {
  for (int y = 0; y < dimensi_y; y++) {
    delete[] matriks[y];
  }
  delete[] matriks;
}

// Getters & Setters
int **Matriks::get_matriks() { return matriks; }
void Matriks::set_matriks(int **matriks) { this->matriks = matriks; }

int Matriks::get_dimensi_x() { return dimensi_x; }
void Matriks::set_dimensi_x(int x) { this->dimensi_x = x; }

int Matriks::get_dimensi_y() { return dimensi_y; }
void Matriks::set_dimensi_y(int y) { this->dimensi_y = y; }

// Methods
void Matriks::init_acak(int nilai_maks) {
  matriks = new int *[dimensi_y];

  for (int y = 0; y < dimensi_y; y++) {
    matriks[y] = new int[dimensi_x];
    for (int x = 0; x < dimensi_x; x++) {
      matriks[y][x] = new_rand(nilai_maks);
    }
  }
}

void Matriks::print() {
  for (int y = 0; y < dimensi_y; y++) {
    std::cout << "│ ";

    for (int x = 0; x < dimensi_x; x++)
      std::cout << matriks[y][x] << " ";

    std::cout << "│\n";
  }
}
