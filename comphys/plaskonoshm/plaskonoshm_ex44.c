//Henry Plaskonos
//ex44
//Sept 29, 2018
//This program finds a value by checking between linear int. and the actual value.
//Updates until the distance between the actual value and interpolated value are close.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double interpolate(double pressure);

const double pi = 3.14159;

int main()
{
	double x = 0;
	int ni;
	double a;

	printf("Enter a distance from the point beneath the mirror > ");
	ni = scanf("%lf", &x);

	a = interpolate(x);

	printf("The angle is = %lfrad or %lfdegrees\n", a, a * 180/pi);


	return(0);
}

double interpolate(double xf)
{
	double y;
	double a;
	double b;
	double theta0, theta1, theta2;
	double x0, x1, x2;
	double dif;

	x0 = 0;
	x1 = tan(pi/2.0 - pi/36.0);
	theta0 = pi/4.0;
	theta1 = pi/36.0;
	dif = fabs(x1 - x0);

    if (xf > 0)
    {
		while (dif >= 1e-7)
		{
			a = (x1 - xf)/(x1 - x0);
			b = (xf - x0)/(x1 - x0);
			theta2 = a * theta0 + b * theta1;
			x2 = tan(pi/2.0 - (theta2 * 2));
			dif = fabs(x2 - xf);

			x0 = x1;
			x1 = x2;
			theta0 = theta1;
			theta1 = theta2;

			while(theta0 > pi/2.0) theta0 -= pi/2.0;
			while(theta1 > pi/2.0) theta1 -= pi/2.0;
			while(theta0 < 0) theta0 += pi/2.0;
			while(theta1 < 0) theta1 += pi/2.0;
		}
	}

	else
	{
		while (dif >= 1e-7)
		{
			a = (x1 - xf)/(x1 - x0);
			b = (xf - x0)/(x1 - x0);
			theta2 = a * theta0 + b * theta1;
			x2 = tan((theta2 * 2) - pi/2.0);
			dif = fabs(x2 - xf);

			x0 = x1;
			x1 = x2;
			theta0 = theta1;
			theta1 = theta2;

			while(theta0 > pi/2.0) theta0 -= pi/2.0;
			while(theta1 > pi/2.0) theta1 -= pi/2.0;
			while(theta0 < 0) theta0 += pi/2.0;
			while(theta1 < 0) theta1 += pi/2.0;
		}



	}


	y = theta2;


	
	return(y);
}
