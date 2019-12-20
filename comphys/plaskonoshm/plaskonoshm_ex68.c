//Henry Plaskonos
//ex6.8
//11 oct 2018
//Uses bracketing with derivatives to find max values for planck function.
//Uses gnuplot to fit points to 1/x line.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

float maxDeri(float a, float b, float c, float t, float (*func1)(float, float));
void findVals(float t);
float plankPrime(float x,float t);

float a,b,c;

int main()
{
    FILE *out, *rsp;
    float point0, point1, point2, point3, point4;


    if((out = fopen("data.dat","w")) == NULL) {
        printf("\nCannot open file for output\n");
        exit(1);
    }

    
    findVals(2000);
    point0 = maxDeri(a,b,c,2000,plankPrime);
    findVals(5000);
    point1 = maxDeri(a,b,c,5000,plankPrime);
    findVals(8000);
    point2 = maxDeri(a,b,c,8000,plankPrime);
    findVals(11000);
    point3 = maxDeri(a,b,c,11000,plankPrime);
    findVals(14000);
    point4 = maxDeri(a,b,c,14000,plankPrime);

    fprintf(out,"2000 %f\n", point0);
    fprintf(out,"5000 %f\n", point1);
    fprintf(out,"8000 %f\n", point2);
    fprintf(out,"11000 %f\n", point3);
    fprintf(out,"14000 %f\n", point4);

    fclose(out);

    if((rsp = fopen("gnuplot.rsp","w")) == NULL) 
    {
        printf("\nCannot open gnuplot.rsp for writing\n");
        exit(1);
    }

    fprintf(rsp,"plot 'data.dat' using 1:2\n");
    fprintf(rsp,"f(x) = a / x \n");
    fprintf(rsp,"fit f(x) 'data.dat' using 1:2 via a\n");
    fprintf(rsp,"replot f(x)\n");
    fprintf(rsp,"pause mouse\n");
    fclose(rsp);
    /*while(system("gnuplot gnuplot.rsp") != -1)
    {
        sleep();
    }
    */
    if(system("gnuplot gnuplot.rsp") == -1) 
    {
        printf("\nCommand could not be executed\n");
        exit(1);
    }


    return(0);

    
}

float plankPrime(float x,float t)
{
    double h = 6.626070040e-34;
    double c = 299792458;
    double k = 1.38064852e-23;
    double a1 = (h*c) / k;

    return (float) -1 * (-5/(x*x*x*x*x*x))*(1/(exp((a1)/(x*t)) - 1)) + 
    (1/(x*x*x*x*x)) * (-1*exp(a1/(x*t))*(a1/t)*(-1/(x*x))) *(1/pow(exp(a1/(x*t)) - 1, 2));
}

float maxDeri(float a1, float b1, float c1, float t, float (*func1)(float, float))
{
	double x1 = 100;
    double x0 = 0;

    while(fabs(x1 - x0) > 1e-6)
    {
    	x0 = x1;
        if ((*func1)(b1, t) > 0)
		{
			x1 = b1 - ((*func1)(b1, t) * (c1 - b1) ) / ((*func1)(c1, t) - (*func1)(b1, t));
			c = b;
			b = x1;
		}
		else
		{
			x1 = a1 - ((*func1)(a1, t) * (b1 - a1)) / ((*func1)(b1, t) - (*func1)(a1, t) );
			a1 = b1;
			b1 = x1; 
		}
    }

    return x1;
}

void findVals(float t)
{
    double x1,x0;
    a = 1500;
    x1 = a;
    x0 = 10;

    while (planck(x1,t) > planck(x0,t))
    {
        x0 = x1;
        x1 += 100;
    }

    b = x0;
    c = b + 1000;

}