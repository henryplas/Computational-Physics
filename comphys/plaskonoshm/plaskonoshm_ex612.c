//Henry Plaskonos
//ex6.12
//11 oct 2018
//Uses powell to find max value of 3-d function.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

const float pi = 3.1415926;

float V(float x[]);
float xi1, xi2;

int main()
{
	float *p,**xi,fret;
	int iter=0;
	float x0,y0;
	int i,j;

	int ni;

	p = vector(1,2);
	xi = matrix(1,2,1,2);
	xi1 = 0.51;


	while (xi1 > 0.5 || xi1 < 0)
	{
		printf("Please enter a value for Xi1 (xi1 <= 0.5) > ");
		ni = scanf("%f", &xi1);
	}

	xi2 = xi1 - 1;

	x0 = cos(pi / 3);
	y0 = sin(pi / 3);

	p[1] = x0;
	p[2] = y0;

	for(i=1;i<=2;i++) {
		for(j=1;j<=2;j++) {
			if(i == j) xi[i][j] = 1.0;
			else xi[i][j] = 0.0;
		}
	}

	powell(p,xi,2,0.001,&iter,&fret,V);

	printf("\nThe mmaximum is found at x = %f, y = %f",p[1],p[2]);
	printf("\nThe value of f at the maximum is %f\n",fret);


	return(0);
}

float V(float x[])
{
	return -1 * ( (xi2 / pow((pow(x[1] - xi1, 2) +  x[2]*x[2]), 0.5)) - 
	(xi1 / pow((pow(x[1] - xi2, 2) +  x[2]*x[2]), 0.5)) -
	(0.5 * (x[1] * x[1] + x[2] * x[2])));
}