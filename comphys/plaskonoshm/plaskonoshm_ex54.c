//Henry Plaskonos
//6 oct 2018
//ex5.4
//Program uses both interpolation and bracketing/bisection to find the zero of a set of data. 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"


int main()
{
    double x[10] = {6.4,6.5,6.6,6.7,6.8,6.9,7.0,7.1,7.2,7.3};
    double y[10] = {0.022718,0.017866,0.013162,0.008598,0.004168,
        -0.000134,-0.004312,-0.008373,-0.012321,-0.016161};

    int i;
    int j;
    double x1,x2,x3,x4;
    double y1,y2,y3,y4;
    double a,b,c,d;
    float aPoint = 6;
    float bPoint = 7;
    float xBi0 = 6;
    float xBi1 = 7;

    for(i = 0 ; i < 10 ; i++) 
    {
        if(y[i] >= 0.0 && y[i + 1] < 0.0) 
        {
            j = i;
            break;
        }
    }

    x1 = x[j - 1];
    x2 = x[j];
    x3 = x[j + 1];
    x4 = x[j + 2];
    y1 = y[j - 1];
    y2 = y[j];
    y3 = y[j + 1];
    y4 = y[j + 2];



    while (1e-6 < fabs(xBi1 - xBi0))
    {
        xBi0 = xBi1;
        a = ((((aPoint + bPoint) / 2) - x2) * (((aPoint + bPoint) / 2) - x3) * 
        (((aPoint + bPoint) / 2) - x4)) / ((x1 - x2) * (x1 - x3) * (x1 -x4));
        b = ((((aPoint + bPoint) / 2) - x1) * (((aPoint + bPoint) / 2) - x3) * 
        (((aPoint + bPoint) / 2) - x4)) / ((x2 - x1) * (x2 - x3) * (x2 - x4));
        c = ((((aPoint + bPoint) / 2) - x1) * (((aPoint + bPoint) / 2) - x2) * 
        (((aPoint + bPoint) / 2) - x4)) / ((x3 - x1) * (x3 - x2) * (x3 - x4));
        d = ((((aPoint + bPoint) / 2) - x1) * (((aPoint + bPoint) / 2) - x2) * 
        (((aPoint + bPoint) / 2) - x3)) / ((x4 - x1) * (x4 - x2) * (x4 - x3));

        xBi1 =  a * y1 + b * y2 + c * y3 + d * y4;

        if (xBi1 > 0)
            aPoint = ((aPoint + bPoint) / 2);
        else
            bPoint = ((aPoint + bPoint) / 2);

    }

    printf("Density = %lf\n", aPoint);


    return (0);



}