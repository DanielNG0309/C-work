//  lab2exC.c
//  ENCM 335 Fall 2021 Lab 3 Exercise C

#include <stdio.h>
#include <stdlib.h>

void to_dhms(int total_s, int *d, int *h, int *min, int *s);
//
// Converts a number of seconds into days, hours, minutes, and seconds.
// For example, 86403s is 1d, 0h, 0min, 3s.
// REQUIRES:
//   total_s >= 0.
//   Pointer parameters all point to appropriate variables.
// PROMISES:
//   *d contains number of days in conversion.
//   *h contains number of hours in conversion.
//   *min contains number of minutes in conversion.
//   *s contains number of seconds in conversion.

int main(void)
{
  int seconds_in, days, hours, minutes, seconds, scan_count;

  printf("Enter a number of seconds that is >= 0: ");
  scan_count = scanf("%d", &seconds_in);  
  if (scan_count != 1) {
    printf("Unable to convert your input to an int.\n");
    exit(1);
  } 
  if (seconds_in < 0) {
    printf("%d s is out of range!\n", seconds_in);
    exit(1);
  } 
  
  printf("Doing conversion for input of %d s ... \n", seconds_in);

  // MAKE A CALL TO to_dhms HERE.
  to_dhms(seconds_in,&days,&hours,&minutes,&seconds);

  printf("That is %d day(s), %d hours(s), %d minute(s), %d second(s).\n",
         days, hours, minutes, seconds);

  return 0;
}

// WRITE A DEFINITION FOR to_dhms HERE.
// Hint: / for integer division and % for integer remainder are useful here.
// Another hint: There are 86400 seconds in a day.
void to_dhms(int total_s, int *d, int *h, int *min, int *s){
	int remain_s1,remain_s2;
	
	*d=total_s/86400;
	remain_s1=total_s%86400;
	*h=remain_s1/3600;
	remain_s2=remain_s1%3600;
	*min=remain_s2/60;
	*s=remain_s2%60;
}

