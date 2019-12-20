//Henry Plaskonos
//ex8.5
//Simple pendulum, second order DE, runge kutte
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"
#include <math.h>

double func(double y);

const double pi = 3.14159265358979323846264;

int main()
{
	double x1,y1,z1,x2,y2,z2;
	double k1,k2,k3,k4,l1,l2,l3,l4;
	double dx = 0.1;


	/* initial conditions */
	x1 = 0.0;
	y1 = pi / 4;
	z1 = 0.0;


	while(x1 < 4 * pi) 
	{
		printf("x = %3.1f y = %f z = %f\n",x1,y1,z1);
		k1 = z1*dx;
		l1 = func(y1)*dx;
		k2 = (z1+0.5*l1)*dx;
		l2 = func(y1+0.5*k1)*dx;
		k3 = (z1+0.5*l2)*dx;
		l3 = func(y1+0.5*k2)*dx;
		k4 = (z1+l3)*dx;
		l4 = func(y1+k3)*dx;

		y2 = y1 + (k1 + 2.0*k2 + 2.0*k3 + k4)/6.0; 
		z2 = z1 + (l1 + 2.0*l2 + 2.0*l3 + l4)/6.0; 
		x2 = x1 + dx;
		x1 = x2;
		y1 = y2; 
		z1 = z2;
	}

return(0);
}

double func(double y)
{
	return -sin(y);
}
