//Henry Plaskonos
//ex5.3
//5 oct 2018
//Program finds a temperature that correlates with the air viscosity value 
//of 20.1uPa given a cubic function

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

double nu(double t);

int main()
{
    float a;
    float b;

    float x1 = 100;
    float x0 = 0;

    a = 300;
    b = 400;
    while (1e-6 < fabs(x1 - x0))
    {
        x0 = x1;
        x1 = nu(((a + b) / 2));
        if (x1 < 20.1)
            a = ((a + b) / 2);
        else
            b = ((a + b) / 2);

    }

    printf("temperature is %lf\n", a);

    return(0);
}

double nu(double t)
{
    return 3.61111 * 1e-8 * t * t * t - 6.95238 * 1e-5 * t * t + 0.0805437 * t - 0.3;
}
