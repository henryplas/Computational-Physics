//Henry Plaskonos
//ex6.3
//6 oct 2018
//Uses bracketing and bisection to find the maximum of function

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

void graph();

double line(double t);

int main()
{
    
    double a = 7000;
    double b = 10000;
    double c = 12000;
    double x;
    double dif;
    int ni;

    dif = fabs(a - c);
    while(dif > 1e-5)
    {
        if (fabs(b - c) < fabs(a - b))
        {
            x = (a + b) / 2;
            if (bessj0(b) > bessj0(x))
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
            if (bessj0(b) > bessj0(x))
            {
                a = b;
                b = x;
            }
            else
            {
                c = x;
            }       
        }
        
        dif = fabs(c - a);
    }
    printf("Maximum is located at T = %lf\n", x);

    return(0);
}

void graph()
{
	FILE *rsp;
	if((rsp = fopen("gnuplot.rsp","w")) == NULL) 
	{
		printf("\nCannot open gnuplot.rsp for writing\n");
		exit(1);
	}

	fprintf(rsp,"set xrange[0:15]\n");
	fprintf(rsp,"plot besj0(x)\n");
	fprintf(rsp,"pause mouse\n");
	fprintf(rsp,"replot\n");
	fclose(rsp);


	if(system("gnuplot gnuplot.rsp") == -1) 
	{	
		printf("\nCommand could not be executed\n");
		exit(1);
	}
}

double line(double t)
{
    double g = 8;
    double N = 1e14;
    double h = 6.626196 * 1e-27;
    double E_n = 10.2;
    double k_ev = 8.617 * 1e-5;
    double pi = 3.14159;
    double m = 9.109558 * 1e-28;
    double k = 1.380622 * 1e-16;
    double E_i = 13.6;
    double U = 2;


    return -1 * (g * N * h * h * h * exp(-1 * E_n /(k_ev * t)))/
        (2 * pow(2 * pi * m * k * t, 1.5) * exp(-1 * E_i / (k_ev * t)) + N * h * h * h * U);

}
