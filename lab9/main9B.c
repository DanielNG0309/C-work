// ENCM 335 Fall 2021 Lab 9 Exercise B 
// Program to test use of the write_l9l function.

#include <stdio.h>
#include <stdlib.h>

#include "write_l9l.h"
#include "list_dbl_t.h"
#include "read_l9l.c"

int main(void)
{
  double x[ ] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5};
  double y[ ] = {-4.5, -3.5, -2.5, -1.5, -0.5, 0.5, 1.5, 2.5, 3.5, 4.5};
  
  int wl9l_result;
  list_dbl_t ld_object;
  size_t i;
  
  wl9l_result = write_l9l("test9B-1.l9l", x, sizeof(x) / sizeof(x[0]));
  // INSTRUCTIONS: Replace this comment with code to check the value
  // of wl9l_result and print an appropriate message.
  
  if (wl9l_result == WL9L_SUCCESS) {
	read_l9l("test9B-1.l9l", &ld_object);
    printf("\nSuccess with file name %s.\n", "test9B-1.l9l");
    printf("List has %zd items ...\n", ld_object.len);
    for (i = 0; i < ld_object.len; i++)
      printf("  %.18g\n", ld_object.arr[i]);
  }
  else
    printf("\nFailure code %d with file name %s.\n",wl9l_result,"test9B-1.l9l");
  

  wl9l_result = write_l9l("test9B-2.l9l", y, sizeof(y) / sizeof(y[0]));
  // INSTRUCTIONS: Replace this comment with code to check the value
  // of wl9l_result and print an appropriate message.
  
  if (wl9l_result == WL9L_SUCCESS) {
	read_l9l("test9B-2.l9l", &ld_object);
    printf("\nSuccess with file name %s.\n", "test9B-2.l9l");
    printf("List has %zd items ...\n", ld_object.len);
    for (i = 0; i < ld_object.len; i++)
      printf("  %.18g\n", ld_object.arr[i]);
  }
  else
    printf("\nFailure code %d with file name %s.\n",wl9l_result,"test9B-2.l9l");

  wl9l_result = write_l9l("noSuchDir/noSuchFile.l9l", 
                          y, sizeof(y) / sizeof(y[0]));
  // INSTRUCTIONS: Replace this comment with code to check the value
  // of wl9l_result and print an appropriate message.
  
  if (wl9l_result == WL9L_SUCCESS) {
	read_l9l("noSuchDir/noSuchFile.l9l", &ld_object);
    printf("\nSuccess with file name %s.\n", "noSuchDir/noSuchFile.l9l");
    printf("List has %zd items ...\n", ld_object.len);
    for (i = 0; i < ld_object.len; i++)
      printf("  %.18g\n", ld_object.arr[i]);
  }
  else
    printf("\nFailure code %d with file name %s.\n",wl9l_result,"noSuchDir/noSuchFile.l9l");
  
  return 0;
}
