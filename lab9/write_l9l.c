// ENCM 335 Fall 2021 Lab 9 Exercise B
// Implementation of the write_l9l function.

#include <stdio.h>
#include "write_l9l.h"

int write_l9l(const char *filename, const double* a, size_t n)
{
  FILE *fp = fopen(filename, "wb");
  int len=n;
  if (fp == NULL)
	  return WL9L_OPEN_FAIL;
	  
  fwrite((void*) &L9L_FIRST_4, sizeof(char), 4, fp);
  fwrite((void*) &len, sizeof(int), 1, fp);
  fwrite((void*) a, sizeof(double), n, fp);
  fwrite((void*) &L9L_FIRST_4, sizeof(char), 4, fp);
  fwrite((void*) &len, sizeof(int), 1, fp);
  
  if (fclose(fp) != 0)
    return WL9L_CLOSE_FAIL;
  
  
  return WL9L_SUCCESS;
}
