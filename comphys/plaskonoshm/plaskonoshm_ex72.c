//Henry Plaskonos
//ex7.2
//8 Oct 2018
//Numerically integrates a function with trapezoidal rule.

#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

double f(double n);

double trapezoidIntegral(double a, double b, int points, double (*func)(double));

int main()
{
    int ni;
    int points = 20;
    double y;
    double a = 298;
    double b = 500;

    y = trapezoidIntegral(a, b, points, f);
    printf("change in entropy = %lf J/K\n", y);
    
    return(0);

}

double f(double t)
{

    double c_p;
    double a = 16.86;
    double b = 4.77e-3;
    double c = 8.54e5;


    return (a + b * t - (c / (t * t))) / t;
} 

double trapezoidIntegral(double a, double b, int points, double (*func)(double))
{
    double x1;
    int i;
    double sum = 0;
    double h = (b - a) / ((double)points - 1); //I casted, per recommendation


    sum = 0.5 * h * ((*func)(a) + (*func)(b));
    x1 = a + h;
    for (i = 2; i < points; i++)
    {
        sum += h * (*func)(x1);
        x1 += h;
    }    
    return sum;
}
