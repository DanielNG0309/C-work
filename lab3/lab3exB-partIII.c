// ENCM 335 Fall 2021 Lab 3 Exercise B part III
// An exercise to help you understand the use of pointer variables.
// Author: Steve Norman

#include <stdio.h>

int foo(int *a0, int a1);

int main(void)
{
  int x, y, z;
  x = 20;
  y = 300;
  z = 4000;
  
  // point one

  printf("In main before call to foo, values are %d, %d, %d.\n",
	 x, y, z);

  x = foo(&y, z);

  // point three

  printf("In main after call to foo, values are %d, %d, %d.\n",
	 x, y, z);

  return 0;
}

int foo(int *a0, int a1)
{
  a1 += 5;
  *a0 += 6;

  // point two

  return a1 + 2;
}
