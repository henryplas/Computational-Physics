//Henry Plaskonos
//6 Oct 2018
//ex5.1
//Program finds root of function

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    float a = 3;
    float b = 4;

    float x1 = 100;
    float x0 = 0;

    while (1e-6 * fabs(a - b) < fabs(x1 - x0))
    {
        x0 = x1;
        x1 = 5 * ((a + b) / 2) * ((a + b) / 2) + 9 * ((a + b) / 2) - 80;
        if (x1 < 0)
            a = ((a + b) / 2);
        else
            b = ((a + b) / 2);

    }

    printf("%lf\n", a);




    return(0);
}
