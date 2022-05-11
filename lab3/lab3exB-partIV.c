// ENCM 335 Fall 2021 Lab 3 Exercise B part IV
// An exercise to help you understand the use of pointer variables.
// Author: Steve Norman

#include <stdio.h>

void bar(int c, int *d);
void quux(int *a, int *b);

int main(void)
{
  int i = 400, j = 500;
  int *p;
  p = &j;
  quux(&i, p);
  printf("i, j values: %d, %d.\n", i, j);

  return 0;
}

void bar(int c, int *d)
{
  // Hint: d must point to an int variable. In other words,
  // d contains the address of an int variable.

  // point one

  *d = c + 7;

  // point two

  return;
}

void quux(int *a, int *b)
{
  *a += 30;
  *b += 20;
  
  // Hint: The next call passes the value of the int pointed to by a 
  // but passes the address that is in b.
  bar(*a, b);
}

