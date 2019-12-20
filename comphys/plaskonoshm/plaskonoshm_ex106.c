//Henry plaskonos
//Dec 4 2018
//ex10.6
//Uses correlation method to find correlation between two data sets
//and the correlation between the same data set.
#include <stdio.h>
#include <math.h>
#include "comphys.c"
#include "comphys.h"
#define pi 3.141592653589793


int main()
{
	FILE *in0, *in1,*out,*rsp;
	float *data0 = vector(1,1024);
	float *data1 = vector(1,1024);
	float *ans = vector(1,2048);
	char name0[15];
	char name1[15];
	int *x0 = ivector(1,1024);
	int *x1 = ivector(1,1024);


	float j;
	int i,m,ni;
	long n = 1024;


	printf("Please enter the name of the first file (use cdata2.dat) > \n");
	ni = scanf("%s", name0);
	printf("Please enter the name of the second file (use cdata3.dat) > \n");
	ni = scanf("%s", name1);

	if((in0 = fopen(name0,"r")) == NULL) 
	{
	    printf("\nCannot open file for input\n");
		exit(1);
	}

	if((in1 = fopen(name1,"r")) == NULL) 
  	{
	    printf("\nCannot open file for input\n");
	    exit(1);
	}

	if((out = fopen("output.out","w")) == NULL) 
	{
		printf("\nCannot open file for output\n");
	    exit(1);
	}

	i = 1;
  	while(fscanf(in0, "%d %f", &x0[i], &data0[i]) != EOF) i++;

  	i = 1;
  	while(fscanf(in1, "%d %f", &x1[i], &data1[i]) != EOF) i++;

	correl(data0, data1, n, ans);

	for(i = 1; i <= 1024; i++)
  	{
    	fprintf(out,"%d %f\n", x0[i], ans[i]);
  	}

  	
	
	if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
    	printf("\nCannot open gnuplot.rsp for writing\n");
    	exit(1);
  	}

  	fprintf(rsp,"plot \"output.out\" using 1:2\n");
  	fprintf(rsp,"pause mouse\n");
  	fprintf(rsp,"replot\n");
  	fclose(rsp);

  	if(system("gnuplot gnuplot.rsp") == -1) {
      	printf("\nCommand could not be executed\n");
      	exit(1);
  	}

  	correl(data0, data0, n, ans);

	for(i = 1; i <= 1024; i++)
  	{
    	fprintf(out,"%d %f\n", x0[i], ans[i]);
  	}

  	printf("Autocorrelation has been sent to screen for first file.\n");

  	if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
    	printf("\nCannot open gnuplot.rsp for writing\n");
    	exit(1);
  	}

  	fprintf(rsp,"plot \"output.out\" using 1:2\n");
  	fprintf(rsp,"pause mouse\n");
  	fprintf(rsp,"replot\n");
  	fclose(rsp);

  	if(system("gnuplot gnuplot.rsp") == -1) {
      	printf("\nCommand could not be executed\n");
      	exit(1);
  	}

  	printf("\nProgram complete without known error.\n");



  	free_ivector(x0,1,1024);
  	free_ivector(x1,1,1024);
  	free_vector(data0,1,1024);
  	free_vector(data1,1,1024);
  	free_vector(ans,1,2048);
  	fclose(in0);
  	fclose(in1);
  	fclose(out);


	return(0);
}
