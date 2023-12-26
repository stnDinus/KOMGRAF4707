#include "degs_to_rads.hxx"
#include <GL/gl.h>
#include <math.h>

template <typename T> T degs_to_rads(T degs) {
  return static_cast<T>(degs * (M_PI / 100));
};

template int degs_to_rads(int);
template GLfloat degs_to_rads(GLfloat);
