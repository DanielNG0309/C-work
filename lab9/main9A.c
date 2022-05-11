// ENCM 335 Fall 2021 Lab 9 Exercise A
// Program to demonstrate use of the read_l9l function.

#include <stdio.h>
#include <stdlib.h>

#include "list_dbl_t.h"
#include "read_l9l.h"

void try_it(const char *filename)
{
  list_dbl_t ld_object;
  int rl9l_result;
  size_t i;
  rl9l_result = read_l9l(filename, &ld_object);
  if (rl9l_result == RL9L_SUCCESS) {
    printf("\nSuccess with file name %s.\n", filename);
    printf("List has %zd items ...\n", ld_object.len);
    for (i = 0; i < ld_object.len; i++)
      printf("  %.18g\n", ld_object.arr[i]);
  }
  else
    printf("\nFailure code %d with file name %s.\n", rl9l_result, filename);
}

int main(void)
{
  try_it("test9A-1.l9l");
  try_it("test9A-2.l9l");
  try_it("test9A-3.l9l");
  try_it("test9A-4.l9l");
  try_it("test9A-5.l9l");
  try_it("test9A-6.l9l");
  return 0;
}
