#include <stdio.h>

int add3(int a, int b, int c)
{
	return a+b+c;
}

int main(void)
{
	int i,j,k;
	i=2;
	j=3;
	k=5;
	printf("Sum of %d, %d, and %d is %d\n", i, j, k, add3(i,j,k));
	printf("Sum of %d, %d, and %d is %d\n", i, j, 7, add3(i,j,7));
	return 0;
}
