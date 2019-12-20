//Henry Plaskonos
//ex7.3
//8 Oct 2018
//Numerically integrates a function with simpsons.

#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

double f(double n);
double simpson(double a, double b, int points, double (*func)(double));

int main()
{
    int ni;
    int points;
    double y;
    double a = 1;
    double b = 2;

    printf("Please enter the amount of points to evaluate the integral > ");
    ni = scanf("%d", &points);
    y = simpson(a, b, points, f);
    printf("area = %lf\n", y);
    
    return(0);

}

double f(double n)
{
    return sin(n) * n;
}

double simpson(double a, double b, int points, double (*func)(double))
{
    double x1;
    int i;
    double sum = 0;
    double h = (b - a) / ((double)points - 1); //I casted, per recommendation


    sum = 0.33333333333 * h * ((*func)(a) + (*func)(b));
    x1 = a + h;
    for (i = 2; i < points; i++)
    {
        if (i % 2 == 0)
        {
            sum += h * 1.3333333333 * (*func)(x1);
        }
        else
        {
            sum += h * 0.66666666666666 * (*func)(x1);
        }
        
        x1 += h;
    }    
    return sum;
}




