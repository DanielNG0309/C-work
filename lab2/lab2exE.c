// ENCM 335 Fall 2021 Lab 2 Exercise E

#include <math.h>
// The above directive will read many function prototypes, including ...
//
//     double sin(double x);
//
// for the sine function.  It's assumed that the units for the argument 
// value are radians, not degrees.

// Note to Linux users: You might need to build the executable like this ...
//   gcc -Wall lab1exF.c -lm
// ... in order to link in the sin function.  Mac and Cywgin users won't
// have to put -lm at the end of the command.

#include <stdio.h>

// For now, just trust that the following #define directives properly
// sets up a useful constant.  How it works will be explained
// later in the course.
#define PI 3.14159265358979323846


double deg2rad(double degrees);

int main(void)
{
    int row,i,j;
    
    printf("degrees");
    for (i=0;i<10;i++){
		printf("     +%d",i);
	} 
    printf("\n");
    for (row = 0; row < 90; row += 10) {
		printf("%7d ", row);
        for (j=0;j<10;j++){
			printf("%.4f ",sin(deg2rad(row+j)));
			
		}
		printf("\n");
    }
    return 0;
}

double deg2rad(double degrees)
{
    return (PI / 180.0) * degrees;
}
