//Henry Plaskonos
//ex6.1
//5 oct 2018
//Program uses bracketing and bisection to determine minimum of function.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double function(double x);

int main()
{
    
    double a = 11;
    double b = 15;
    double c = 20;
    double x;
    double dif = fabs(a - c);
    while(dif > fabs(c - a) * 1e-7)
    {
        if (fabs(b - c) < fabs(a - b))
        {
            x = (a + b) / 2;
            if (function(b) > function(x))
            {
                c = b;
                b = x;
                
            }
            else
            {
                a = x;
            }
                
        }
        else
        {
            x = (c + b) / 2;
            if (function(b) > function(x))
            {
                a = b;
                b = x;
            }
            else
            {
                c = x;
            }       
        }
        printf("Minimum is located at x = %lf\n", x);
        dif = fabs(c - a);
    }

    return(0);
}

double function(double x)
{   
    return x*x*x - 24*x*x + 6*x + 15;
}
