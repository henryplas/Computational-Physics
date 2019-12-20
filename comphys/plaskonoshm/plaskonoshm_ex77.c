//Henry Plaskonos
//ex7.7
//8 Oct 2018
//Numerically integrates a function guass.

#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

double f(double n);
double gauss(double a, double b, double (*func)(double));

int main()
{
   
   double ans = gauss(1,2,f);
   printf("integral using gauss = %lf\n",ans);
    
    
   return(0);
}

double f(double n)
{
    return sin(n) * n;
}

double gauss(double a, double b, double (*func)(double))
{
    double sum = 0;
    int i;
    double x[5] = {-0.90618,-0.538469,0.0,0.538469,0.90618};
    double w[5] = {0.236927,0.478629,0.568889,0.478629,0.236927};

    for(i = 0; i < 5; i++)
    {
        sum += w[i] * (*func)(((b + a) / 2) + ((b - a) / 2) * x[i]);    
    }

    return ((b - a) / 2) * sum;
}
