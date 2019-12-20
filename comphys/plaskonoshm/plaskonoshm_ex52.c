//Henry Plaskonos
//ex5.2
//6 oct 2018
//Program finds the first two positive roots of the Bessel function (J_0)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

int main()
{
    float a = 2;
    float b = 3;

    float x1 = 1;
    float x0 = 0;

    while (1e-6 * fabs(a - b) < fabs(x1 - x0))
    {
        x0 = x1;
        x1 = bessj0(((a + b) / 2));
        if (x1 > 0)
            a = ((a + b) / 2);
        else
            b = ((a + b) / 2);


    }

    printf("%lf\n", a);
    
    a = 5;
    b = 7;
    x1 = 5;
    x0 = 0;

    while (1e-6 * fabs(a - b) < fabs(x1 - x0))
    {

        x0 = x1;
        x1 = bessj0(((a + b) / 2));
        if (x1 < 0)
            a = ((a + b) / 2);
        else
            b = ((a + b) / 2);

    }

    printf("%lf\n", a);




    return(0);
}
