//Henry Plaskonos
//ex 3.8
// 9/13/2018
//modification of 3.5, reads in data to an array, then does temperature math from data in array


#include <stdio.h>
#include <stdlib.h> /* Needed for exit() */
#include <math.h>
#include "comphys.h"
#include "comphys.c"

double planck1(double wave, double T);

int main()
{

    double T;
    double result;
    int ni;
    char outfile[80];
    double *wave;
    wave = dvector(0, 24);
    double i;
    int j = 0;
    FILE *in, *out;

    if((in = fopen("inputwave.dat","r")) == NULL) 
    {
        printf("\nCannot open file for input\n");
        exit(1);
    }


    printf("\nEnter the temperature in Kelvin > ");
    ni = scanf("%lf",&T);
    printf("\nEnter the name of the output file > ");
    ni = scanf("%s",outfile);
    

    if((out = fopen(outfile,"w")) == NULL) 
    {
        printf("\nCannot open %s for writing\n",outfile);
        exit(1);
    }

    while(fscanf(in,"%lf",&i) != EOF) 
    {
        wave[j] = i;
        j++;
    }

    j = 0;
    while (wave[j] != 0.0)
    {   
        result = planck1(wave[j] , T);
        fprintf(out,"%7.1f  %e\n",wave[j],result);
        j++;
    }

    fclose(in);
    fclose(out);
    free_dvector(wave,0,24);
    return(0);
}



double planck1(double wave, double T)
{
    static double p = 1.19106e+27;
    double p1;
    p1 = p/(pow(wave,5.0)*(exp(1.43879e+08/(wave*T)) - 1.0));
    return(p1);
}

