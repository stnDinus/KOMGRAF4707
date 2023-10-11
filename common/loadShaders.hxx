#pragma once

#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

GLuint loadShaders(const char *vertex_file_path,
                   const char *fragment_file_path);
