//Henry Plaskonos
//dec 4 2018
//ex10.4
//Uses convolution method on RC DE, smooths out spikes
#include <stdio.h>
#include <math.h>
#include "comphys.c"
#include "comphys.h"
#define pi 3.141592653589793


int main()
{
	  FILE *out,*rsp;
	float *resp = vector(1,128);
	float *data = vector(1,128);
	float *ans = vector(1,256);
	float j;
	int i,m;
	long n = 128;

	if((out = fopen("output.out","w")) == NULL) 
	{
		printf("\nCannot open file for output\n");
	    exit(1);
	}

	j = 0;
	i = 1;
	while(j <= 6.4)
	{
		resp[i] = exp(-j / 1);
		j += 0.1;
		i++;
	}

	m = i;
	j = 0;
	i = m;
	while(j < 1.0) // array is preloaded with zeroes
	{
		data[i] = 1.0;
		j += 0.1;
		i++;
	}

	convlv(data, n, resp, n, 1, ans);

	j = -6.4;
	for(i = 1; i <= 128; i++)
  	{
    	fprintf(out,"%f %f\n", j, ans[i]);
    	j += 0.1;
  	}

  	fclose(out);
	
	if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
    	printf("\nCannot open gnuplot.rsp for writing\n");
    	exit(1);
  	}

  	fprintf(rsp,"plot \"output.out\" using 1:2 with lines\n");
  	fprintf(rsp,"pause mouse\n");
  	fprintf(rsp,"replot\n");
  	fclose(rsp);

  	if(system("gnuplot gnuplot.rsp") == -1) {
      	printf("\nCommand could not be executed\n");
      	exit(1);
  	}

  	printf("\nProgram complete without known error.\n");


	return(0);
}
