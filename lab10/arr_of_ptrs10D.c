// ENCM 335 Fall 2021 Lab 10 Exercise D

#include <stdio.h>
#include <string.h>

#define COUNT(x) (sizeof(x) / sizeof(x[0]))

void sort_doubles(double *a, int n);
// REQUIRES
//   n >= 2. Array elements a[0] ... a[n-1] exist.
// PROMISES
//   Array elements have been sorted in order from smallest to largest. 

void sort_strings(char **s, int n);
// REQUIRES
//   n >= 2.
//   Array elements s[0] ... s[n-1] exist, and each points to the
//   start of a C string.
// PROMISES
//   Array elements have been sorted in increasing order, where
//   "smaller" and "larger" are decided by the library function strcmp.

double d_one[ ] = {-2.0, 3.0, -4.0, 0.0};
double d_two[ ] = {10.0, 9.5, 10.5, 8.5, 9.0, 10.25, 8.25, 9.75};

char *s_one[ ] = {"baz", "bar", "bat", "bart", "barb", "back"};
char *s_two[ ] = {"9", "10", "1", "7", "71", "123", "85", "1111"};

int main(void)
{
  int i;

  printf("d_one before sort:");
  for (i = 0; i < COUNT(d_one); i++)
    printf(" %g", d_one[i]);
  sort_doubles(d_one, COUNT(d_one));
  printf("\nd_one after sort: ");
  for (i = 0; i < COUNT(d_one); i++)
    printf(" %g", d_one[i]);
  printf("\n\n");

  printf("d_two before sort:");
  for (i = 0; i < COUNT(d_two); i++)
    printf(" %g", d_two[i]);
  sort_doubles(d_two, COUNT(d_two));
  printf("\nd_two after sort: ");
  for (i = 0; i < COUNT(d_two); i++)
    printf(" %g", d_two[i]);
  printf("\n\n");

  printf("s_one before sort:");
  for (i = 0; i < COUNT(s_one); i++)
    printf(" %s", s_one[i]);
  sort_strings(s_one, COUNT(s_one));
  printf("\ns_one after sort: ");
  for (i = 0; i < COUNT(s_one); i++)
    printf(" %s", s_one[i]);
  printf("\n\n");

  printf("s_two before sort:");
  for (i = 0; i < COUNT(s_two); i++)
    printf(" %s", s_two[i]);
  sort_strings(s_two, COUNT(s_two));
  printf("\ns_two after sort: ");
  for (i = 0; i < COUNT(s_two); i++)
    printf(" %s", s_two[i]);
  printf("\n\n");

  return 0;
}

void sort_doubles(double *a, int n)
{
  // The sort algorithm used here is called insertion sort.  It's
  // simple, and reasonably efficient for small arrays, say, with 20
  // elements or fewer.  For larger arrays, other algorithms such as
  // quicksort, heapsort, mergesort are recommended.

  int outer = 1;     // index to control outer loop
  double eti;        // short for "element to insert"
  int i;             // index to control inner loop
  while (outer < n) {
    eti = a[outer];
    i = outer;
    while (i != 0 && a[i - 1] > eti) {
      a[i] = a[i - 1];
      i--;
    }
    a[i] = eti;
    outer++;
  }
  
}

void sort_strings(char **s, int n)
{
  // Replace this comment with code that uses insertion sort
  // to properly rearrange the elements of an array of pointers.
  int outer = 1;     // index to control outer loop
  char *eti;         // short for "element to insert"
  int i;             // index to control inner loop
  while (outer < n) {
    eti = s[outer];
    i = outer;
    while (i != 0 && (strcmp(s[i - 1],eti)>0)) {
      s[i] = s[i - 1];
      i--;
    }
    s[i] = eti;
    outer++;
  }
  
}
