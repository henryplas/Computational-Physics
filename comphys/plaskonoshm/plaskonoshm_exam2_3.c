#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"


float *t,*yi; //for imported values
int k; //loop iterating variable
float f(float x[]);
const float pi = 3.1415926;

int main()
{
    float *p, **xi,fret;
    int i,j;
    int iter = 0;
    float A1;
    float P1;
    float A2;
    float P2;
    FILE *in;
    xi = matrix(1,4,1,4);
    p = vector(1,4);
    t = vector(0,299); //external data
    yi = vector(0,299); //external data

    A1 = 3;
    P1 = 10;
    A2 = 3;
    P2 = 10;

    p[1] = A1;
    p[2] = P1;
    p[3] = A2;
    p[4] = P2;

    if ((in = fopen("SIM.dat","r")) == NULL) 
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

    printf("\nA1 = %f, P1 = %f A2 = %f P2 = %f",p[1],p[2],p[3],p[4]);


    return(0);
}

float f(float x[])
{
    float y1,chi2;
    int i;
    chi2 = 0.0;

    for(i = 0; i < k; i++) 
    {
        y1 = x[1]*sin((2*pi*t[i])/x[2]) + x[3]*sin((2*pi*t[i])/x[4]);
        chi2 += (y1 - yi[i])*(y1 - yi[i]);
    }

    printf("\nchi2 = %f",chi2);
    return(chi2);
}



