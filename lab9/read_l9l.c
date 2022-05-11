// ENCM 335 Fall 2021 Lab 9 Exercise A
// Function definition for read_l9l.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for the memcmp function

#include "list_dbl_t.h"
#include "read_l9l.h"

int read_l9l(const char *filename, list_dbl_t *ld)
{
  // Do this in case there is a failure.
  ld->len = 0;

  FILE *fp = fopen(filename, "rb");
  char first4read[4], trailer_first4[4];
  unsigned int el_count, trailer_count;
  size_t read_count;

  if (fp == NULL)
    return RL9L_OPEN_FAIL;

  read_count = fread((void *) first4read, 1, 4, fp);
  if (read_count != 4)
    return RL9L_TOO_SHORT;
  
  // memcmp returns 0 if two blocks of bytes of the same length
  // match exactly.
  if (memcmp((void *) first4read, (void *) L9L_FIRST_4, 4) != 0)
    return RL9L_BAD_HEADER;

  read_count = fread((void *) &el_count, sizeof(unsigned int), 1, fp);
  if (read_count != 1)
    return RL9L_TOO_SHORT;
  if (el_count > MAX_LENGTH)
    return RL9L_WONT_FIT;

  read_count = fread((void *) ld->arr, sizeof(double), el_count, fp);
  if (read_count != el_count)
    return RL9L_TOO_SHORT;

  read_count = fread((void *) trailer_first4, 1, 4, fp);
  if (read_count != 4)
     return RL9L_TOO_SHORT;
  
  read_count = fread((void *) &trailer_count, sizeof(unsigned int), 1, fp);
  if (read_count != 1)
     return RL9L_TOO_SHORT;
 
  if (memcmp((void *) trailer_first4, (void *) L9L_FIRST_4, 4) != 0
      || el_count != trailer_count)
    return RL9L_BAD_TRAILER;    

  if (fclose(fp) != 0)
    return RL9L_CLOSE_FAIL;

  ld->len = el_count;
  return RL9L_SUCCESS;
}
