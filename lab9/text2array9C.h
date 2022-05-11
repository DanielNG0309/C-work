// ENCM 335 Fall 2021 Lab 9 Exercise C
// Interface for a function to read an array of doubles from a file
// into a dynamically allocated array. It's expected that the numbers
// in the file are ASCII text separated by whitespace.

#ifndef TEXT2ARRAY_H
#define TEXT2ARRAY_H

#include "arr_dbl_t.h"

// Return values for text2array
#define T2A_SUCCESS      0
#define T2A_OPEN_FAIL   -1  // couldn't open file 
#define T2A_MALLOC_FAIL -2  // couldn't allocate enough memory
#define T2A_BAD_CHARS   -3  // invalid text in input file
#define T2A_CLOSE_FAIL  -4  // problem detected closing file

int text2array(const char *filename, arr_dbl_t *ad);
// REQUIRES:
//   filename points to the beginning of a string.
//   ad points to an appropriate object.
// PROMISES:
//   On success, ad->arr points to an dynamic array containing
//   the numbers from the input file, and ad->length and ad->cap
//   are set according to rules given in arr_dbl_t.h, and the
//   return value is T2A_SUCCESS.
//   On failure, members of *ad are all zeroed, and the return value
//   reflects the cause of failure.

#endif // #ifndef TEXT2ARRAY_H
