#pragma once

#include "loadShaders.hxx"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

void draw_points(std::vector<GLfloat> points, std::string title = "OpenGL");
