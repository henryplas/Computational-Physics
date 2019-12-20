//Henry Plaskonos
//ex7.1
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
    int points;
    double y;
    double a = 1;
    double b = 2;

    printf("Please enter the amount of points to evaluate the integral > ");
    ni = scanf("%d", &points);
    y = trapezoidIntegral(a, b, points, f);
    printf("area = %lf\n", y);
    
    return(0);

}

double f(double n)
{
    return sin(n) * n;
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
