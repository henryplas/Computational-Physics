//Henry Plaskonos
//Linear least squares, basic
//ex91


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"
#include <math.h>


int main()
{
    double x[100];
    double y[100];
    int i,q;
    double S,Sx,Sy,Sxx,Sxy,a,b,det,sig_a,sig_b,chi2,s_,error_a,error_b;

    FILE *in;

    if((in = fopen("data91.dat","r")) == NULL) 
    {
        printf("\nCannot open file for input\n");
        exit(1);
    }
    
    i = 0;
    while(fscanf(in, "%lf %lf",&x[i], &y[i]) != EOF) i++;

    fclose(in);
    
    for(q = 0; q < i; q++)
    {
        S += 1;
        Sx += x[q];
        Sy += y[q];
        Sxx += x[q]*x[q];
        Sxy += x[q]*y[q];
    }

    det = S*Sxx - Sx*Sx;
    a = (Sxx*Sy - Sx*Sxy) / det;
    b = (S*Sxy - Sx*Sy) / det;

    sig_a = sqrt(Sxx / det);
    sig_b = sqrt(S / det);

    for(q = 0; q < i; q++)
    {
        chi2 += (y[q] - a - x[q]*b) * (y[q] - a - x[q]*b);
    }

    s_ = sqrt(chi2 / (i - 2));

    error_a = s_ * sig_a;
    error_b = s_ * sig_b;

    printf("Chi2 = %lf\na = %lf +/- %lf\nb = %lf +/- %lf\n",chi2,a,error_a,b,error_b);

    return(0);
}
