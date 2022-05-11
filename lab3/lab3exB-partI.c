// ENCM 335 Fall 2021 Lab 3 Exercise B part I
// An exercise to help you understand the use of pointer variables.
// Author: Steve Norman

#include <stdio.h>

int main(void)
{
  int *alpha;
  int *beta;
  int gamma = 333;
  int delta = 555;

  alpha = &gamma;

  // point one

  printf("point one: value of gamma is %d; value of delta is %d.\n", 
         gamma, delta);

  beta = &delta;
  *alpha += 30;
  *beta += 40;

  // point two

  printf("point two: value of gamma is %d; value of delta is %d.\n", 
         gamma, delta);

  beta = &gamma;
  *beta += 100;

  // point three

  printf("point three: value of gamma is %d; value of delta is %d.\n", 
         gamma, delta);
  printf("point three: value of *alpha is %d; value of *beta is %d.\n", 
         *alpha, *beta);

  beta = &delta;
  *beta = *alpha;

  // point four

  printf("point four: value of gamma is %d; value of delta is %d.\n", 
         gamma, delta);

  beta = alpha;
  *beta += 5000;

  // point five

  printf("point five: value of gamma is %d; value of delta is %d.\n", 
         gamma, delta);
  printf("point five: value of *alpha is %d; value of *beta is %d.\n", 
         *alpha, *beta);

  return 0;
}
