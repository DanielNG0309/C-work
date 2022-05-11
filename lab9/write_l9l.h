// ENCM 335 Fall 2021 Lab 9 Exercise B
// Interface for a function to write an array of doubles to a file
// in the .l9l format, which is specified in the Exercise B instructions.

#ifndef WRITE_L9L_H
#define WRITE_L9L_H

// Return values for write_l9l
#define WL9L_SUCCESS      0
#define WL9L_OPEN_FAIL   -1  // couldn't open file 
#define WL9L_CLOSE_FAIL  -2  // problem detected closing file

// Required first four bytes of header, first four bytes of trailer.
#define L9L_FIRST_4  "L9li"

int write_l9l(const char *filename, const double* a, size_t n);
// REQUIRES:
//   filename points to the beginning of a string.
//   Array elements a[0] ... a[n-1] exist.
// PROMISES:
//   On success, the array has been saved in the .l9l format to the
//   file specified by filename, and the return value is WL9L_SUCCESS.
//   On failure, the return value reflects the cause of failure.

#endif // #ifndef WRITE_L9L_H
