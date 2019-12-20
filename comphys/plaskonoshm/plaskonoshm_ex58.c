//Henry Plaskonos
//ex5.8
//6 oct 2018
//Program uses newton raphson method to find root of funtion. Plots function beforehand.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

double number(double n);
double numberPrime(double n);
void graph();


int main()
{
	
	int ni;
	double x1;
	double x0 = 0;
	double f,fp;

	
	graph();

	printf("Enter an initial guess to search for the halflife. > ");
	
	ni = scanf("%lf", &x1);

	while (1e-8 < fabs(x1 - x0))
    {
        x0 = x1;
        f = number(x1);
        fp = numberPrime(x1);
        
        x1 = x0 + ((50 - f )/ fp);

    }

    printf("%lf\n", x1);

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

	fprintf(rsp,"f(x) = 50.0 * (exp(-x/5.697) + exp(-x/9.446))\n");
	fprintf(rsp,"set xrange[0:15]\n");
	fprintf(rsp,"plot f(x)\n");
	fprintf(rsp,"pause mouse\n");
	fprintf(rsp,"replot\n");
	fclose(rsp);


	if(system("gnuplot gnuplot.rsp") == -1) 
	{	
		printf("\nCommand could not be executed\n");
		exit(1);
	}
}


double number(double x)
{
	return 50.0 * (exp(-x/5.697) + exp(-x/9.446));
}

double numberPrime(double x)
{

	return 50.0 * ((-1 / 5.697) * exp(-x/5.697) + (-1 / 9.446) * exp(-x/9.446));
}
