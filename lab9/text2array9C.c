// ENCM 335 Fall 2021 Lab 9 Exercise C
// Function definition for text2array.

#include <stdio.h>
#include <stdlib.h>

#include "arr_dbl_t.h"
#include "text2array9C.h"

#define T2A_BASE_CAP 8

int text2array(const char *filename, arr_dbl_t *ad)
{
  // Zero out *ad in case of failure.
  ad->arr = NULL;
  ad->len = ad->cap = 0;

  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
    return T2A_OPEN_FAIL;

  // Allocate an array.
  double *storage = malloc(T2A_BASE_CAP * sizeof(double));
  if (storage == NULL)
    return T2A_MALLOC_FAIL;
  size_t len = 0, cap = T2A_BASE_CAP, i;
  int nscan;

  // Read data into array.  Allocate a bigger array whenever
  // the current array is full.
  while (1) {
    if (len == cap) {
      double *old = storage;
      storage = malloc(2 * cap * sizeof(double));
      if (storage == NULL) {
		  free(old);
		  return T2A_MALLOC_FAIL;
      }
      for (i = 0; i < cap; i++)
		  storage[i] = old[i];
      cap *= 2;
      
      // point one
      // (This point is considered to have been reached only if the
      // if-statement condition len == cap was true.)

      free(old);
    }
    
    nscan = fscanf(fp, "%lf", &storage[len]);
    if (nscan != 1)
      break;
    len++;
  }
  if (fclose(fp) != 0)
    return T2A_CLOSE_FAIL;
  if (nscan == 0)
    return T2A_BAD_CHARS;

  ad->arr = storage;
  ad->len = len;
  ad->cap = cap;
  return T2A_SUCCESS;
}
