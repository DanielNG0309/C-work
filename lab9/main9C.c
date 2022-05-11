// ENCM 335 Fall 2021 Lab 9 Exercise C
// Program to demonstrate use of the text2array function.

#include <stdio.h>
#include <stdlib.h>

#include "arr_dbl_t.h"
#include "text2array9C.h"

void try_it(const char *filename)
{
  arr_dbl_t a_of_d;
  int t2a_result;
  size_t i;
  t2a_result = text2array(filename, &a_of_d);
  if (t2a_result == T2A_SUCCESS) {
    printf("\nSuccess with file name %s.\n", filename);
    printf("Array has %zd elements ...\n", a_of_d.len);
    for (i = 0; i < a_of_d.len; i++)
      printf("  %.18g\n", a_of_d.arr[i]);

    // Avoid memory leak.
    free(a_of_d.arr);
  }
  else
    printf("\nFailure code %d with file name %s.\n", t2a_result, filename);
}

int main(void)
{
  try_it("test9C-1.txt");
  try_it("test9C-2.txt");
  try_it("test9C-3.txt");
  try_it("no-such-dir/no-such-file.txt");
  return 0;
}
