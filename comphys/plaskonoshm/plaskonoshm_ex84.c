//Henry Plaskonos
//ex8.4
//Adaptive stepsize RK

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"
#include <math.h>

double rk4(double(*f)(double, double), double dx, double x, double y);
double func(double x, double y);
 
int main()
{
	double x_;
	double y_;
	double y1;
	double y2;
	double y = 1, x = 0;
	double dx = 0.1, b, m;

	double eps0 = 0.000001, eps;

	while(x <= 1.0)
	{
		x_ = x;
		y_ = y;
		y1 = rk4(func, dx, x, y);
		y2 = rk4(func, dx/2, x + dx/2, rk4(func, dx/2, x, y));
		eps = fabs(y2 - y1);
		dx = dx * pow(eps0/eps, 0.2);
		y = rk4(func, dx, x, y);
		x += dx;
		if (x > 1) break;
		printf("x = %lf\ty = %lf\t\n", x, y);
	}
 
 	m = (y_ - y)/(x_ - x);
 	b = y - m * x;
 	y = m + b;
 	printf("x = %lf\ty = %lf\t\n", 1.0, y);
	return 0;
}

double rk4(double(*f)(double, double), double dx, double x, double y)
{
	double	k1 = dx * f(x, y),
			k2 = dx * f(x + dx / 2, y + k1 / 2),
			k3 = dx * f(x + dx / 2, y + k2 / 2),
			k4 = dx * f(x + dx, y + k3);
	return y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}
 
double func(double x, double y)
{
	return (x - 1) * y * y;
}