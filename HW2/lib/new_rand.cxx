#include "new_rand.hxx"

int new_rand(int max) {
  srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
  return rand() % max;
}
