// ptr2ptr10A1.c
// ENCM 335 Fall 2021 Lab 10 Exercise A Part I

#include <stdio.h>

int aa[ ] = {100, 200, 300, 400}; 

int main()
{
  int *p = &aa[3];
  int *q = &aa[1];
  int **ee = &p;
  int **ff = &q;
  int i;

  **ee += 3;
  *ff += 3;

  // point one

  *p += 5;
  ff = &p;
  *ff -= 2;
  **ff -= 2;
  
  // point two

  printf("array contents:");
  for (i = 0; i < 4; i++)
    printf("  %d", aa[i]);
  printf("\n");

  return 0;
}
