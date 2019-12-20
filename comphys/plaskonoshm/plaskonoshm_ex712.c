//Henry Plaskonos
//ex712
//Finds double integral of function with MC

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"

float ro(float x, float y);

const double pi = 3.14159265358979323846264;

int main()
{
	int N,ni;
	float x,y,rn,r2,f,integral,V,sum,av,sum2,av2,M,X_pos,Y_pos;
	float error;
	long i;
	long idum = -1;
	time_t now;


	printf("Please enter the amount of points for Monte Carlo > ");
	ni = scanf("%d",&N);

	now = time(NULL);
	idum = -1*now;

	rn = ran1(&idum);

	V = 1;
	sum = 0.0;
	sum2 = 0.0;

	for(i = 0; i < N ; i++) 
	{
		x = ran1(&idum);
		y = 2 * ran1(&idum);
		
		if(y <= -2 *x + 2) f = ro(x, y);
		else f = 0.0;
		/* Evaluate sums */
		sum += f;
		sum2 += f*f;
	}

	/* Calculate Integral and error */
	av = sum/(float)N;
	M = av*V;

	sum = 0.0;
	sum2 = 0.0;

	for(i = 0; i < N ; i++) 
	{
		x = ran1(&idum);
		y = 2 * ran1(&idum);

		if(y <= -2 * x + 2) f = x * ro(x, y);
		else f = 0.0;
		/* Evaluate sums */
		sum += f;
		sum2 += f*f;
	}

	/* Calculate Integral and error */
	av = sum/(float)N;
	X_pos =(1/M) * av*V;

	sum = 0.0;
	sum2 = 0.0;

	for(i = 0; i < N ; i++) 
	{
		x = ran1(&idum);
		y = 2 * ran1(&idum);
		
		if(y <= -2 *x + 2) f = y * ro(x, y);
		else f = 0.0;
		/* Evaluate sums */
		sum += f;
		sum2 += f*f;
	}

	/* Calculate Integral and error */
	av = sum/(float)N;
	Y_pos = (1/M) * av*V;


	
	printf("Center of mass position = (%f, %f)\n",X_pos, Y_pos);
	return(0);
}

float ro(float x, float y)
{
	return y * sin(x * x) + 2;
}
