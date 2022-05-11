// ENCM 335 Fall 2021 Lab 9 Exercise A
// Interface for a function to read a list of doubles from a file
// in the .l9l format, which is specified in the Exercise B instructions.

#ifndef READ_L9L_H
#define READ_L9L_H

#include "list_dbl_t.h"

// Return values for read_l9l
#define RL9L_SUCCESS      0
#define RL9L_OPEN_FAIL   -1  // couldn't open file 
#define RL9L_WONT_FIT    -2  // list in input file is too long
#define RL9L_CLOSE_FAIL  -3  // problem detected closing file
#define RL9L_BAD_HEADER  -4  // invalid .l9l header
#define RL9L_TOO_SHORT   -5  // not enough data in file
#define RL9L_BAD_TRAILER -6  // invalid .l9l trailer

// Required first four bytes of header, first four bytes of trailer.
#define L9L_FIRST_4  "L9li"

int read_l9l(const char *filename, list_dbl_t *ad);
// REQUIRES:
//   filename points to the beginning of a string.
//   ad points to an appropriate object.
// PROMISES:
//   On success, ad->len holds the length of the list and ad->arr[0]
//   to ad->arr[arr->len - 1] hold the items of the list and the
//   return value is T2A_SUCCESS.
//   On failure,ad->len is set to 0 and the return value reflects the
//   cause of failure.

#endif // #ifndef READ_L9L_H
