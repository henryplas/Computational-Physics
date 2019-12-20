//Henry Plaskonos
//ex6.10
//11 oct 2018
//Uses amoeba to find max value of 3-d function.

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
	float **p,*y;
	int nfunk,i;
	float x0,y0;

	int ni;

	p = matrix(1,3,1,2);
	y = vector(1,3);
	xi1 = 0.51;


	while (xi1 > 0.5 || xi1 < 0)
	{
		printf("Please enter a value for Xi1 (xi1 <= 0.5) > ");
		ni = scanf("%f", &xi1);
	}

	xi2 = xi1 - 1;

	x0 = cos(pi / 3);
	y0 = sin(pi / 3);

	p[1][1] = x0;
	p[1][2] = y0;
	p[2][1] = x0 + 1.0;
	p[2][2] = y0;
	p[3][1] = x0;
	p[3][2] = y0 + 1.0;

	for(i=1;i<=3;i++) y[i] = V(p[i]);

	amoeba(p,y,2,0.001,V,&nfunk);

	x0 = (p[1][1]+p[2][1]+p[3][1])/3.0;
	y0 = (p[1][2]+p[2][2]+p[3][2])/3.0;

	printf("\nThe maximum is found at x0 = %f, y0 = %f\n",x0,y0);
	printf("The number of function evaluations is %d\n",nfunk);


	return(0);
}

float V(float x[])
{
	return -1 * ( (xi2 / pow((pow(x[1] - xi1, 2) +  x[2]*x[2]), 0.5)) - 
	(xi1 / pow((pow(x[1] - xi2, 2) +  x[2]*x[2]), 0.5)) -
	(0.5 * (x[1] * x[1] + x[2] * x[2])));
}