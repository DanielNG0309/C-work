// ENCM 335 Fall 2021 Lab 9 Exercise C
// Type for managing dynamically allocated arrays of doubles.

#ifndef ARR_DBL_T_H
#define ARR_DBL_T_H

// Rules for use of this struct type:
//   arr should point to an array obtained with malloc.
//   cap should be the number of elements in the array.
//   length must be <= cap, and should represent the number
//     of elements that are in use.  For example, if cap is 8
//     and len is 5, arr[0] ... arr[4] are in use, but
//     arr[5] ... arr[7] are space for future growth.

struct arr_dbl {
  double *arr;
  size_t len;
  size_t cap;
};
typedef struct arr_dbl arr_dbl_t;


#endif // #ifndef ARR_DBL_T_H
