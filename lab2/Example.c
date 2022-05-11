// ENCM 335 Fall 2021 Lab 2 Exercise D

#include <stdio.h>




int main(void)
{
  call_is_valid_time(-1, 0, 0);
  call_is_valid_time(0, -1, 0);
  call_is_valid_time(0, 0, -1);

  call_is_valid_time(24, 0, 0);
  call_is_valid_time(0, 60, 0);
  call_is_valid_time(0, 0, 60);

  call_is_valid_time(0, 0, 0);
  call_is_valid_time(23, 59, 59);

  printf("\n");

  describe(0, 0, 0);
  describe(3, 12, 27);
  describe(5, 29, 59);
  describe(5, 30, 0);
  describe(10, 3, 58);
  describe(11, 59, 59);
  describe(12, 0, 0);
  describe(3, 0, 0);
  describe(17, 30, 19);
  describe(17, 30, 20);
  describe(17, 30, 21);
  describe(22, 59, 59);
  describe(23, 0, 0);
  describe(23, 0, 1);
  describe(23, 59, 59);

  return 0;
}

int is_valid_time(int hour, int min, int sec)
{
  // Obviously, this is often wrong ...
  return 1;
}

void call_is_valid_time(int hour, int min, int sec)
{
  // Note %02d says "print an int with at least 2 digits,
  // and fill with leading zeros if necessary.
  printf("%02d:%02d:%02d ", hour, min, sec);
  if (is_valid_time(hour, min, sec))
    printf("makes");
  else
    printf("does not make");
  printf(" sense as a time of day.\n");
}

void describe(int h, int min, int s)
{ 
  printf("%02d:%02d:%02d is in the ", h, min, s);
  
  // Obviously, this too is often wrong ...
  printf("wee hours.\n");
}
