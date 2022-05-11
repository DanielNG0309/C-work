// ENCM 335 Fall 2021 Lab 4 Exercise B

// This program is defective.

#include <stdio.h>

void time_diff(int earlier_h, int earlier_min, int later_h, int later_min,
	       int *diff_h, int *diff_min);
// Computes difference between two times in the same day. Assumes use of
// a 24-hour clock.

int main(void)
{
  int diff_h,diff_min;
  int later_h = 22, later_min = 35, earlier_h = 9, earlier_min = 47;
  int *p_h=&diff_h,*p_min=&diff_min;

  time_diff(earlier_h, earlier_min, later_h, later_min, p_h, p_min);

  printf("Elapsed time from %02d:%02d to %02d:%02d is ...\n",
	 earlier_h, earlier_min, later_h, later_min);
  printf("... %d hour(s) and %d minute(s).\n", *p_h, *p_min);

  return 0;
}

void time_diff(int earlier_h, int earlier_min, int later_h, int later_min,
	       int *diff_h, int *diff_min)
{
  if (later_min >= earlier_min) {
    *diff_h = later_h - earlier_h;
    *diff_min = later_min - earlier_min;
  }
  else {
    *diff_h = later_h - earlier_h - 1;
    *diff_min = later_min + 60 - earlier_min;
  }
}
