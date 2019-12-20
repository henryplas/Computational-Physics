//Henry Plaskonos
//ex714
//Uses monte carlo to simulate quantum system.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"


//const double pi = 3.14159265358979323846264;

float energy(int arr[]);

int main()
{
	int N,ni;
	float rn;
	long i;
	int j;
	long idum = -1;
	time_t now;
	float T;
	int arr[50];
	float E0, E1, R, E_old;
	FILE *out, *rsp;

	if((out = fopen("output.out","w")) == NULL) 
	{
		printf("\nCannot open file for output\n");
		exit(1);
	}


	printf("Please enter the desired temperature for the system > ");
	ni = scanf("%f",&T);

	now = time(NULL);
	idum = -1*now;
	rn = ran1(&idum);

	for(i = 0; i < 50; i++)
	{
		rn = ran1(&idum);
		if(rn <= 0.5)
			arr[i] = 1;
		else
			arr[i] = -1;
	}

	E1 = energy(arr);

	for(i = 1; i <= 5000; i++)
	{
		E_old = E0; //save old values just in case it reverts back
		E0 = E1;	
		j = (int)(49.99999999999 * ran1(&idum)); //integer rounding 0 - 49
		arr[j] *= -1;
		E1 = energy(arr);
		if (E1 > E0)
		{
			R = exp(-1 * (E1 - E0) / (0.001 * T));
			rn = ran1(&idum);	
			if(R < rn)
			{
				E1 = E0;
				E0 = E_old;
			}
		}

		fprintf(out,"%ld %f\n",i, E1);
	}

	fclose(out);

	if((rsp = fopen("gnuplot.rsp","w")) == NULL) 
	{
		printf("\nCannot open gnuplot.rsp for writing\n");
		exit(1);
	}

	fprintf(rsp,"plot \"output.out\" using 1:2 with lines\n");
	fprintf(rsp,"pause mouse\n");
	fprintf(rsp,"replot\n");
	fclose(rsp);

	if(system("gnuplot gnuplot.rsp") == -1) 
	{
		printf("\nCommand could not be executed\n");
		exit(1);
	}

	return(0);
}

float energy(int arr[])
{
	int i;
	float e;

	for(i = 0; i < 49; i++)
	{
		e += arr[i] * arr[i + 1];
	}
	return 2.0 * e;

}

	
