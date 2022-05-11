#include <stdio.h>
#include <stdlib.h>

int get_int_or_die(void);
// REQUIRES:
//    User has been prompted to enter an int.
// PROMISES:
//    Function tries to read an int using scanf and "%d"
//    On success, that int is echoed to the user,
//    and the int is the function return value.
//    On failure, and error message is printed and
//    exit is called with an argument of 1.

double get_double_or_die(void);
// Like get_int_or_die, but tries to read a double using "%lf".

void get_inputs(double *km_in,int *minutes_in,double *seconds_in);
// Get inputs, check if valid or not, then assign accordingly


int main(void)
{
  int minutes_in,avg_min_km,avg_min_mile;
  double km_in,seconds_in,avg_sec_km,avg_sec_mile;
  double mile_per_km = 1609.344/1000;
  
  get_inputs(&km_in,&minutes_in,&seconds_in);
  
  printf("Distance run: %f km.\n",km_in);
  printf("Time of run: %d minute(s), %f second(s).\n",minutes_in,seconds_in);
  
  //get the average minute(s) taken to run 1 km in type int.
  avg_min_km = minutes_in/km_in;
  
  //the total seconds is equal to the remaining decimals (from minutes_in/km_in)*60 + the number of seconds taken/distance in km
  avg_sec_km = (minutes_in/km_in-avg_min_km)*60+seconds_in/km_in;
  
  //same as above but convert to mile
  avg_min_mile = minutes_in/km_in*mile_per_km;
  avg_sec_mile = (minutes_in*mile_per_km/km_in-avg_min_mile)*60+seconds_in*mile_per_km/km_in;
  
  //Check if the average number of seconds exceed 60, if yes then update average minutes and seconds accordingly
  while (avg_sec_km>=60.0){
	  avg_sec_km-=60.0;
	  avg_min_km++;
  }
  while (avg_sec_mile>=60.0){
	  avg_sec_mile-=60.0;
	  avg_min_mile++;
  }
  
  printf("Average time for 1 km: %d minute(s), %f second(s).\n",avg_min_km,avg_sec_km);
  printf("Average time for 1 mile: %d minute(s), %f second(s).\n",avg_min_mile,avg_sec_mile);
  
  return 0;
}

int get_int_or_die(void)
{
  int result;
  if (1 != scanf("%d", &result)) {
    printf("I could not read an int. I am quitting.\n");
    exit(1);
  }
  printf("I read an int value of %d.\n", result);
  return result;
}

double get_double_or_die(void){

  double result;
  if (1 != scanf("%lf", &result)) {
    printf("I could not read an double. I am quitting.\n");
    exit(1);
  }
  printf("I read an double value of %f.\n", result);
  return result;
}

void get_inputs(double *km_in,int *minutes_in,double *seconds_in){
	printf("Please enter a distance in km, using type double.\n");
	*km_in=get_double_or_die();
	printf("Please enter a number of minutes, using type int.\n");
	*minutes_in=get_int_or_die();
	printf("Please enter a number of seconds, using type double.\n");
	*seconds_in=get_double_or_die();
}

