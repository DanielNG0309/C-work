// ENCM 335 Fall 2021 Lab 9 Exercises A and B
// Type for managing variable-sized lists of doubles.

#ifndef LIST_DBL_T_H
#define LIST_DBL_T_H

#include <stdlib.h>

// Here we set the maximum length for a list managed by the list_dbl_t
// type.  It is an inconvenient limit--in a later exercise, we might
// modify the type to use dynamically allocated memory to allow
// lists of arbitrary length.
#define MAX_LENGTH 10

// Rules for use of this struct type:
//   len must be <= MAX_LENGTH, and represents the count of valid
//   elements in in the list.  For example, if len has a value of 3,
//   then arr[0], arr[1], and arr[2] hold the items belonging to the
//   list, and the other array elements do not contain valid data.
struct list_dbl {
  double arr[MAX_LENGTH];
  size_t len;
};
typedef struct list_dbl list_dbl_t;


#endif // #ifndef LIST_DBL_T_H
