//Henry Plaskonos
//ex5.7
//6 oct 2018
//Program uses newton raphson method to find root of funtion starting at 200K

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"


double nu(double t);
double nuPrime(double t);


int main()
{
	float x1 = 200;
    float x0 = 0;
    float f;
    float fp;

    while (1e-6 < fabs(x1 - x0))
    {
        x0 = x1;
        f = nu(x1);
        fp = nuPrime(x1);
        
        x1 = x0 + ((20.1 - f )/ fp);

    }

    printf("%lf\n", x1);

    return(0);
}

double nu(double t)
{
    return 3.61111 * 1e-8 * t * t * t - 6.95238 * 1e-5 * t * t + 0.0805437 * t - 0.3;
}

double nuPrime(double t)
{
    return 2 * 3.61111 * 1e-8 * t * t - 2 * 6.95238 * 1e-5 * t + 0.0805437;
}


