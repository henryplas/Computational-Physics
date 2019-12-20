//Henry Plaskonos
//ex6.9
//8 Oct 2018
//This program invokes the Amoeba function to find the best values that fit a DE.
//Uses Chi^2 function as a parameter.

#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

float *t,*yi;
int k;
float f(float x[]);

int main()
{
    float **p,*y;
    int nfunk,i,q;
    float A;
    float gam;
    float B;
    float C;
    FILE *in;
    p = matrix(1,5,1,4);
    y = vector(1,5);
    t = vector(0,200);
    yi = vector(0,200);

    A = 9.0;
    B = 3.0;
    C = 0.5;
    gam = 0.18;

    p[1][1] = A;
    p[1][2] = B;
    p[1][3] = C;
    p[1][4] = gam;
    p[2][1] = A + 1.0;
    p[2][2] = B;
    p[2][3] = C;
    p[2][4] = gam;
    p[3][1] = A;
    p[3][2] = B + 1.0;
    p[3][3] = C;
    p[3][4] = gam;
    p[4][1] = A;
    p[4][2] = B;
    p[4][3] = C + 1.0;
    p[4][4] = gam;
    p[5][1] = A;
    p[5][2] = B;
    p[5][3] = C;
    p[5][4] = gam + 1.0;

    

    if ((in = fopen("decay.out","r")) == NULL) 
    {
        printf("\nCannot find input file\n");
        exit(1);
    }

    k = 0;
    while(fscanf(in,"%f %f",&t[k],&yi[k]) != EOF) 
        k++;
    fclose(in);

    for (q = 1; q < 6; q++)
        y[q] = f(p[q]);

    amoeba(p,y,4,0.001,f,&nfunk);

    A = (p[1][1]+p[2][1]+p[3][1]+p[4][1]+p[5][1]) / 5;
    B = (p[1][2]+p[2][2]+p[3][2]+p[4][2]+p[5][2]) / 5;
    C = (p[1][3]+p[2][3]+p[3][3]+p[4][3]+p[5][3]) / 5;
    gam = (p[1][4]+p[2][4]+p[3][4]+p[4][4]+p[5][4]) / 5;

    printf("\nA = %lf B = %lf C = %lf gam = %lf\n",A,gam,B,C);

    

}


float f(float x[])
{
    float y1,chi2;
    int i;
    chi2 = 0.0;

    for(i=0;i<k;i++) 
    {
        y1 = x[1]*exp(-x[2]*t[i])*sin(x[3]*t[i] + x[4]);
        chi2 += (y1 - yi[i])*(y1 - yi[i]);
    }

    printf("\nchi2 = %f",chi2);
    return(chi2);
}


