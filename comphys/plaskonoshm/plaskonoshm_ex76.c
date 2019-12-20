//Henry Plaskonos
//ex7.6
//8 Oct 2018
//Numerically integrates a function with simpsons. Finds sigma in BB

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
    double a = 1e-9;
    double b;

    printf("Please enter the amount of points to evaluate the integral > ");
    ni = scanf("%d", &points);

    printf("Please enter the upper limit > ");
    ni = scanf("%lf", &b);


    y = simpson(a, b, points, f);

    
    printf("sigma = %.9e\n", y / pow(3000,4));
    
    return(0);

}

double f(double lambda)
{
    double h = 6.626070040e-34;
    double c = 299792458;
    double k = 1.38064852e-23;
    double t = 3000;
    return (1 / (lambda * lambda * lambda * lambda * lambda  * (exp(h*c/(lambda * k * t)) - 1)));
}

double simpson(double a, double b, int points, double (*func)(double))
{
    double x1;
    int i;
    double sum = 0;
    double hp = 6.626070040e-34;
    double c = 299792458;
    double pi = 3.14159265359;
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
    return 2 * pi * hp * c * c * sum;
}




