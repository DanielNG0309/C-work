// ENCM 335 Fall 2021 Lab 5 Exercise C

#include <stdio.h>

void display_array(const char *label, const double *x, size_t n);
// REQUIRES
//    label points to the beginning of a string.
//    Elements x[0], ... x[n-1] exist.
// PROMISES
//    label is printed, followed by values of  x[0], ... x[n-1], all on
//    one line, using %4.2f format for the doubles. If n == 0, the line
//    of output points out that fact. 

void reverse(double *x, size_t n);
// REQUIRES
//     n > 0.
//     Array elements x[0] ... x[n - 1] exist.
// PROMISES
//     Order of elements x[0] ... x[n - 1] has been reversed.
//     (So the new x[0] value is the old x[n - 1] value, and so on.)

int increasing(const double *x, size_t n);
// REQUIRES
//     n > 0.
//     Array elements x[0] ... x[n - 1] exist.
// PROMISES
//     Return value is 1 if n == 1.
//     If n > 1, return value is 1 if all of a[0] < a[1] ... a[n-2] < a[n-1] 
//     are true, otherwise return value is 0.


// In Step 3, add a function prototype and function interface comment
// for max_element here.

double max_element(const double *x, size_t n);
// REQUIRES
//     n > 0.
//     Array elements x[0] ... x[n - 1] exist.
// PROMISES
//	   Return the maximum element in the array of doubles

int main(void)
{
  double test1[ ] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double test2[ ] = {-0.5, -1.0, -1.5, -2.0, -2.5, -3.0};

  printf("Some quick checks of display_array ...\n");
  display_array("  all of test1:", test1, 5);
  display_array("  none of test1:", test1, 0);
  display_array("  last 3 elements of test1:", &test1[2], 3);
  display_array("  all of test2:", test2, 6);

  printf("\nTwo tests of reverse ...\n");
  reverse(test1, 5);
  display_array("  test1 after reversing:", test1, 5);
  reverse(test2, 6);
  display_array("  test2 after reversing:", test2, 6);

  double test3[ ] = {1.5, 1.25, 2.5, 3.5, 4.5, 5.5, 5.25};
  double test4[ ] = {1.0, 2.0, 3.0, 3.0, 4.0, 5.0};
  int inc;
  printf("\nSome tests of increasing ...\n");
  display_array("  for these numbers:", test3, 6);
  inc = increasing(test3, 6);
  printf("  expected return value is 0, actual value is %d\n\n", inc);
  display_array("  for these numbers:", &test3[1], 5);
  inc = increasing(&test3[1], 5);
  printf("  expected return value is 1, actual value is %d\n\n", inc);
  display_array("  for these numbers:", &test3[1], 6);
  inc = increasing(&test3[1], 6);
  printf("  expected return value is 0, actual value is %d\n\n", inc);
  display_array("  for these numbers:", test4, 6);
  inc = increasing(test4, 6);
  printf("  expected return value is 0, actual value is %d\n\n", inc);

  // In Step 3, add some tests for max_element here.
  double test5[]={-3.2,-1.5,-4.7,-5.5,-2.2,-0.9};
  double test6[]={3.2,1.5,5.5,2.2,0.9};
  double test7[]={3.2,1.5,-4.7,-5.5,2.2,0.9};
  double test8[]={-3.2,1.5,-5.5,0.9,2.2};
  double max;
  
  printf("\nSome tests of max_element ...\n");
  display_array("  for these numbers:", test5, 6);
  max=max_element(test5, 6);
  printf("  expected return value is -0.90, actual value is %.2f\n\n", max);
  display_array("  for these numbers:", test6, 5);
  max=max_element(test6, 5);
  printf("  expected return value is 5.50, actual value is %.2f\n\n", max);
  display_array("  for these numbers:", test7, 6);
  max=max_element(test7, 6);
  printf("  expected return value is 3.20, actual value is %.2f\n\n", max);
  display_array("  for these numbers:", test8, 5);
  max=max_element(test8, 5);
  printf("  expected return value is 2.20, actual value is %.2f\n\n", max);
  
  return 0;
}

void display_array(const char *label, const double *x, size_t n)
{
  size_t i ;
  printf("%s", label);
  if (n == 0)
    printf("  [no contents to print]\n");
  else {
    for(i = 0; i < n ; i++)
      printf(" %4.2f", x[i] );
    printf("\n");
  }
}

void reverse(double *x, size_t n)
{
  // Replace this comment with your code.
  int i;
  double a;
  for (i=0;i<n/2;i++){
	  a=x[i];
	  x[i]=x[n-1-i];
	  x[n-1-i]=a;
  }
	  
}

int increasing(const double *x, size_t n)
{
  // Replace this comment with your code.
  int i,a;
  if (n==1)
	  return 1;
  else
	  for (i=0;i<n-1;i++)
		  if (x[i]<x[i+1])
			  a=1;
		  else{
			  a=0;
			  break;
		  }
  return a;
}

// In Coding Step 3, add a function definition for max_element here.
double max_element(const double *x, size_t n){
	int i;
	double max=x[0];
	for (i=0;i<n;i++){
		if (max<x[i])
			max=x[i];
	}
	return max;
}
