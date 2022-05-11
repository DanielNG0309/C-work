// vec7B.c
// ENCM 335 Fall 2021 Lab 7 Exercise B

// Function definitions for operations on vectors in 3-space.

#include <stdio.h>
#include "vec7B.h"

void print_vec(vec_t v)
{
  // REMARK: %g usually does a more helpful job of printing a double
  // than %f does.
  printf("(%g %g %g)", v.x, v.y, v.z);
}

void scalar_product(double k, const vec_t *v, vec_t *w)
{
  w->x = k * v->x;
  w->y = k * v->y;
  w->z = k * v->z;
}

double dot_product(vec_t left, vec_t right){
  double result;
  result= left.x*right.x+left.y*right.y+left.z*right.z;
  return result;
}

void sum(const vec_t* left, const vec_t *right, vec_t *sum){
  sum->x = left->x+right->x;
  sum->y = left->y+right->y;
  sum->z = left->z+right->z;
}

vec_t cross_product(vec_t left, vec_t right){
  vec_t result;
  result.x=left.y*right.z-left.z*right.y;
  result.y=left.z*right.x-left.x*right.z;
  result.z=left.x*right.y-left.y*right.x;	
  return result;
}
