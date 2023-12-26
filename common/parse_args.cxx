#include "parse_args.hxx"

using namespace std;

void Args::parse_args(int *argc, char *argv[]) {
  for (int i = 1; i < *argc; i++) {
    args_map[argv[i]] = argv[i + 1];
    i++;
  }
}

string &Args::operator[](string key) { return args_map[key]; };
