// main7B.c
// ENCM 335 Fall 2021 Lab 7 Exercise B

// main function to demonstrate operations on vectors in 3-space.

#include <stdio.h>
#include "vec7B.h"

int main(void)
{
  vec_t u = { 1.5, 0.5, 0.125 }, v = { -2.0, 3.5, -3.0 };
  
  printf("Value of u: ");
  print_vec(u);
  printf("\nValue of v: ");
  print_vec(v);
  printf("\n\n");

  // Demonstrate scalar product.
  double k = 0.5;
  vec_t sp;
  scalar_product(k, &v, &sp);
  printf("Scalar product of %g and v is: ", k);
  print_vec(sp);
  printf("\n\n");
  
  printf("The dot product of u and v is: %g \n\n",dot_product(u,v));

  vec_t sum_vector;
  printf("The sum of u and v is: ");
  sum(&u,&v,&sum_vector);
  print_vec(sum_vector);
  printf("\n\n");
  
  printf("The cross product of u and v is: ");
  print_vec(cross_product(u,v));
  return 0;
}
