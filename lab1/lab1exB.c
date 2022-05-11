#include <stdio.h>

double mult3(double a, double b, double c)
{
	return a*b*c;
}

int main(void)
{
	double i,j,k;
	i=0.5;
	j=1.5;
	k=2.5;
	printf("Product of %f, %f, and %f is %f\n", i, j, k, mult3(i,j,k));
	printf("Product of %f, %f, and %f is %f\n", i, j, 3.5, mult3(i,j,3.5));
	return 0;
}
