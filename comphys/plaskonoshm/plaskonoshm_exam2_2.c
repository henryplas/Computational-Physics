#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys2.h"
#include "comphys2.c"


float a;
float b;

void findVals(float t);

int main()
{
    float x1 = 100;
    float x0 = 0;
    float aVal;
    int ni;
    
    printf("Please enter in a value for a (between 1 and 10) > ");
    ni = scanf("%f",&aVal);
    findVals(aVal);
    
    while (1e-6 * fabs(a - b) < fabs(x1 - x0))
    {
        x0 = x1;
        x1 = gammp(aVal,(a + b) / 2);
        if (x1 < 0.5)
            a = ((a + b) / 2);
        else
            b = ((a + b) / 2);
        //printf("%lf\n",a);
    }

    printf("P(0.5) where a is %f = %f\n",aVal,a);



    return(0);
}


void findVals(float aVal)
{
    double x1,x0;
    a = 0;
    x1 = a;
    x0 = 10;
    while (gammp(aVal,a) < 0.2) a += 0.1;
    x1 = a;
    while (fabs(gammp(aVal,x1) - gammp(aVal,x0)) > 0.001)
    {
        x0 = x1;
        x1 += 0.1;
    }

    b = x0;

}
