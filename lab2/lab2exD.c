// ENCM 335 Fall 2021 Lab 2 Exercise D

#include <stdio.h>


int is_valid_time(int hour, int min, int sec)
{
// Returns 1 if the parameters describe a valid time of day
// between 00:00:00 and 23:59:59.
// Returns 0 otherwise.
  if ((hour>=0)&&(hour<24)){
	  if ((min>=0)&&(min<60)){
		  if ((sec>=0)&&(sec<60)){
			  return 1;
		  }
	  }
  }
  
  return 0;
  
		  
}

void call_is_valid_time(int hour, int min, int sec)
// Prints parameters within in a message stating whether
// the parameters make sense together as a time of day.

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
// Assumes that the parameters describe a valid time of day.
// Prints the time and a description of the time using terms
// such as "wee hours", "morning", etc., as describe in the Lab 1
// instructions.

printf("%02d:%02d:%02d is in the ", h, min, s);

if (h<5){
	printf("wee hours.\n");
}
else if (h==5){
	if (min<=29){
		printf("wee hours.\n");
	}
	else {
		printf("morning.\n");
	}
}
else if (h<=11){
	printf("morning.\n");
}
else if (h==12){
	printf("afternoon.\n");
}
else if (h<17){
	printf("afternoon.\n");
}
else if (h==17){
	if (min<=30){
		if (s<=19){
			printf("afternoon.\n");
		}
		else {
			printf("evening.\n");
		}
	}
	else {
		printf("evening.\n");
	}
}

else if (h<23){
	printf("evening.\n");
}
else if (h==23){
	if (min==0){
		if(s==0){
			printf("evening.\n");
		}
		else {
			printf("late night.\n");
		}
	}
	else {
		printf("late night.\n");
	}
	
}
else 
	printf("late night.\n");

}



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

