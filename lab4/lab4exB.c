// ENCM 335 Fall 2021 Lab 4 Exercise B

// IMPORTANT REMARK
//
//   For the most part in ENCM 335 we'll avoid using array syntax
//   to declare function parameters, because doing so is misleading
//   about types.  In other words, this is preferred ...
//
//       void foo(int *a, int n);
//
//   ... and this is not recommended ...
//
//       void foo(int a[], int n);
//
//   But in this exercise we'll use array syntax, just to emphasize
//   the fact that with a function parameter, asking for an array
//   type gets you a pointer type.

#include <stdio.h>

void fail2copy(double dest[], double src[]);

void copy(double dest[], const double src[], size_t n);

double bad_sum(const double x[3]);

int main(void)
{
  double foo[3] = {0.5, 1.25, 2.125};
  double bar[3];
  double sum_foo;
  size_t size_foo;

  size_foo = sizeof(foo);
  printf("The number of elements in the array foo is %zd.\n",
	 size_foo / sizeof(double));

  // point one

  sum_foo = bad_sum(foo);
  printf("This program thinks that the sum of the "
	 "elements in foo is %f.\n", sum_foo);

  fail2copy(bar, foo); 
  copy(bar, foo, 3);
  return 0;
} 

void fail2copy(double dest[], double src[])
{
  // If you don't know C well, you might think this
  // function copies an array.  IT DOES NOT!

  dest = src;

  // point three

  return;
}

void copy(double dest[], const double src[], size_t n)
{
  size_t i;
  for (i = 0; i < n; i++)
    dest[i] = src[i];

  // point four

  return;
}

double bad_sum(const double x[3])
{
  // ATTENTION: Putting 3 between the square brackets beside arg does
  // NOTHING to change the type of x--the type of arg is
  // pointer-to-const-double.  The 3 is simply ignored by the C
  // compiler.  This style is even worse than declaring a function
  // parameter with empty square brackets!

  size_t size_x, element_count, i;
  double sum = 0.0;

  // BAD AND WRONG attempt to find the number of array elements ...
  // (Recent versions of gcc and clang will give a warning about the problem.)
  size_x = sizeof(x);
  element_count = size_x / sizeof(double);

  for (i = 0; i < element_count; i++)
    sum += x[i];

  // point two

  return sum;
}
