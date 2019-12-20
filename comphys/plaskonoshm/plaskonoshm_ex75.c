//Henry Plaskonos
//ex7.5
//8 Oct 2018
//Numerically integrates a function with trapezoidal rule and advanced technique..

#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

double f(double n);

double trapezoidIntegral(double a, double b, int points, double (*func)(double));

int main()
{
    int ni;
    int points = 30 ;
    double y0,y1,x0,x1;
    double a = 1;
    double b = 2;
    double slope;
    double val;

    y0 = trapezoidIntegral(a, b, points, f);
    

    points = 80;
    y1 = trapezoidIntegral(a, b, points, f);
    
    x0 = 1/(pow(30,2)); //was having trouble with 30*30 and 80*80 respectively
    x1 = 1/(pow(80,2));

    slope = (y1 - y0)/(x1 - x0);
    val = y1 - slope * x1;

    printf("The final value is = %lf\n",val);
    printf("Deviation for N = 30 is = %lf\n",1.440422 - y0);
    printf("Deviation for N = 80 is = %lf\n",1.440422 - y1);
    printf("Deviation for N = INF is = %lf\n",1.440422 - val);







    
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
