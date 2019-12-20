//Henry Plaskonos
//ex6.9
//8 Oct 2018
//This program invokes the Amoeba function to find the best values that fit a DE.
//Uses Chi^2 function as a parameter.

#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

float *t,*yi; //for imported values
int k; //loop iterating variable
float f(float x[]);

int main()
{
    float *p, **xi,fret;
    int i,j;
    int iter = 0;
    float A;
    float gam;
    float B;
    float C;
    FILE *in;
    xi = matrix(1,4,1,4);
    p = vector(1,4);
    t = vector(0,200); //external data
    yi = vector(0,200); //external data

    A = 9.0;
    B = 3.0;
    C = 0.5;
    gam = 0.18;

    p[1] = A;
    p[2] = B;
    p[3] = C;
    p[4] = gam;

    if ((in = fopen("decay.out","r")) == NULL) 
    {
        printf("\nCannot find input file\n");
        exit(1);
    }

    k = 0;
    while(fscanf(in,"%f %f",&t[k],&yi[k]) != EOF) 
        k++;
    fclose(in);

    //identity
    for(i=1;i<=4;i++) {
        for(j=1;j<=4;j++) {
            if(i == j) xi[i][j] = 1.0;
            else xi[i][j] = 0.0;
        }
    }

    powell(p,xi,4,0.001,&iter,&fret,f);

    printf("\nA = %f, B = %f C = %f gam = %f",p[1],p[2],p[3],p[4]);
    printf("\nThe value of f at the minimum is %f\n",fret);
    return(0);
}

float f(float x[])
{
    float y1,chi2;
    int i;
    chi2 = 0.0;

    for(i = 0; i < k; i++) 
    {
        y1 = x[1]*exp(-x[2]*t[i])*sin(x[3]*t[i] + x[4]);
        chi2 += (y1 - yi[i])*(y1 - yi[i]);
    }

    printf("\nchi2 = %f",chi2);
    return(chi2);
}


