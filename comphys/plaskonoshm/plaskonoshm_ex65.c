//Henry Plaskonos
//ex6.5
//11 oct 2018
//Program uses bracketing and bisection to determine minimum of function.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double function(double x);
double fPrime(double x);
void minDeri(double a, double b, double c, double (*func)(double), double (*func1)(double));

int main()
{
    
    double a = 11;
    double b = 15;
    double c = 20;
    minDeri(a, b, c, function, fPrime);

    
    return(0);
}

double function(double x)
{   
    return x*x*x - 24*x*x + 6*x + 15;
}

double fPrime(double x)
{
    return 3*x*x - 48*x + 6;
}

void minDeri(double a, double b, double c, double (*func)(double), double (*func1)(double))
{
	double x1 = 100;
    double x0 = 0;



    while(fabs(x1 - x0) > 1e-6)
    {
    	x0 = x1;
        if ((*func1)(b) > 0)
		{
			x1 = b - ((*func1)(b) * (c - b) ) / ((*func1)(c) - (*func1)(b));
			c = b;
			b = x1;
		}
		else
		{
			x1 = a - ((*func1)(a) * (b - a)) / ((*func1)(b) - (*func1)(a) );
			a = b;
			b = x1; 
		}
    
        
    }
    printf("Minimum is located at x = %lf\n", x1);


}