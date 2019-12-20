//Henry Plaskonos
//ex6.3
//6 oct 2018
//Uses bracketing and busection to find first minimum of J_0 Bessel function.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

void graph();

int main()
{
    
    double a;
    double b;
    double c;
    double x;
    double dif;
    int ni;
    


    graph(); 

	printf("Enter an initial triplet of points (seperated by spaces)\nto search for minimum of J_0 Bessel> ");
	
	ni = scanf("%lf %lf %lf", &a, &b, &c);
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
    printf("Minimum is located at x = %lf\n", x);

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