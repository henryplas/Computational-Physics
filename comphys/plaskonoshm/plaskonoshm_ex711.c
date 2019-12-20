//Henry Plaskonos
//ex711
//Finds double integral of function with MC.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"


const double pi = 3.14159265358979323846264;

int main()
{
	int N,ni;
	float x,y,rn,r2,f,integral,V,sum,av,sum2,av2;
	float error;
	long i;
	long idum = -1;
	time_t now;


	printf("Please enter the amount of points for Monte Carlo > ");
	ni = scanf("%d",&N);


	now = time(NULL);
	idum = -1*now;

	rn = ran1(&idum);

	V = 2 * pi;
	sum = 0.0;
	sum2 = 0.0;

	for(i = 0; i < N ; i++) 
	{

		x = ran1(&idum) - 1.0;
		y = pi * ran1(&idum) - (pi / 2);
		

		if(x <= 1 && x >= -1 && y <= pi / 2 && y >= -1 * pi / 2) f = (x*x) * cos(y);
		else f = 0.0;
		/* Evaluate sums */
		sum += f;
		sum2 += f*f;
	}

	/* Calculate Integral and error */
	av = sum/(float)N;
	av2 = sum2/(float)N;
	integral = av*V;
	error = V*sqrt((av2-av*av)/(float)N);
	printf("\nIntegral = %f +/- %f\n",integral,error);
	return(0);
}

