// ENCM 335 Fall 2021 Lab 6 Exercise B

#include <stdio.h>

int foo(const int *a, int n);

int main(void)
{
  int i, j;
  int b[] = {50, 20, 40, 10, 30};
  int c[] = {100, 400, 300, 200};
  i = foo(b, sizeof(b) / sizeof(int));
  printf("1st result: %d.\n", i);
  j = foo(c, sizeof(c) / sizeof(int));
  printf("2nd result: %d.\n", j);
  return 0;
}

// This function was not written for easy readability!
// It's a drill exercise related to pointer arithmetic!
int foo(const int *a, int n)
{
  const int *max = a, *min = a + n - 1, *guard = a + n;
  const int *p, *q;
  for (p = a + 1; p != guard; p++) {
    if (*p > *max)
      max = p;
  }
  for (q = guard - 1; q != a; q--) {
    if (q[-1] < *min)
      min = q - 1;
  }

  // point one (after the 2nd loop has finished)

  return min - max;
}
