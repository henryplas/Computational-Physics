//Henry Plaskonos
//ex5.9
//6 oct 2018
//Program uses newton raphson method to find root of bessel function J_0 and J_1
//Uses the fact that J_1 is the first derivative of J_0.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

int main()
{
	float x1 = 2;
    float x0 = 0;
    float f;
    float fp;

    while (1e-8 < fabs(x1 - x0))
    {
        x0 = x1;
        f = bessj0(x1);
        fp = -1 * bessj1(x1);
        
        x1 = x0 - (f / fp);

    }


    printf("%lf\n", x1);

    x1 = 5;
    x0 = 0;
    
    while (1e-8 < fabs(x1 - x0))
    {
        x0 = x1;
        f = bessj0(x1);
        fp = -1 * bessj1(x1);
        
        x1 = x0 - (f / fp);

    }

    printf("%lf\n", x1);

    return(0);
}