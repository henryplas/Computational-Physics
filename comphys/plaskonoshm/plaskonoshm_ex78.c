//Henry Plaskonos
//ex7.8
//8 Oct 2018
//Numerically integrates a function with guass.

#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

double f(double n);
double gauss(double a, double b, double (*func)(double));

int main()
{
   
   double ans = gauss(298,500,f);
   printf("integral using gauss = %lf\n",ans);
   printf("7.2 = 6.586975\n");
   printf("7.4 = 6.588489\n");
    
    
    
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
