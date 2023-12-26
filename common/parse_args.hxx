#pragma once

#include <string>
#include <unordered_map>

class Args {
  std::unordered_map<std::string, std::string> args_map;

public:
  void parse_args(int *argc, char *argv[]);

  std::string &operator[](std::string key);
};
