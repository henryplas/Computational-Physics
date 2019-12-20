//Henry Plaskonos
//ex 3.5
//9/13/2018
//modified code reads in data rather than using increments of 500 in while loop


#include <stdio.h>
#include <stdlib.h> /* Needed for exit() */
#include <math.h>

double planck(double wave, double T);

int main()
{

    double wave,T;
    double result;
    int ni;
    char outfile[80];
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

    while(fscanf(in,"%lf",&wave) != EOF) 
    {
        result = planck(wave,T);
        fprintf(out,"%7.1f  %e\n",wave,result);
    }

    fclose(in);
    fclose(out);
    return(0);
}



double planck(double wave, double T)
{
    static double p = 1.19106e+27;
    double p1;
    p1 = p/(pow(wave,5.0)*(exp(1.43879e+08/(wave*T)) - 1.0));
    return(p1);
}

