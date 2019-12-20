//Henry Plaskonos
//Fits function with custom degree and data points
//ex94


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"
#include <math.h>


int main()
{
    float x[50];
    float y[50];
    float **A;
    float **b;
    float *error;
    float chi2 = 0;
    int m, k, j, l, ni;
    int i, q, N;
    float s, sum = 0;
   
    FILE *in;

    printf("Please enter in degree (M - 1) > ");
    ni = scanf("%d", &m);
    m++;

    A = matrix(1,m,1,m);
    b = matrix(1,m,1,1);
    error = vector(1, m);

    if((in = fopen("data94.dat","r")) == NULL) 
    {
        printf("\nCannot open file for input\n");
        exit(1);
    }
    
    l = 0;
    while(fscanf(in, "%f %f",&x[l], &y[l]) != EOF) 
    {
        for(k = 1; k <= m; k++)
        {
            b[k][1] += y[l] * pow(x[l], (float)(k-1));
            for(j = 1; j <= m; j++)
            {
                A[k][j] += pow(x[l], (float)(j-1)) * pow(x[l],(float)(k-1));
            }
        }
        l++;
    }

    fclose(in);
    N = l;
    gaussj(A, m, b, 1);

    for(i = 1; i <= m; i++) 
    {
        sum = 0.0;
        for (k = 1; k <= m; k++)
        {
            sum += b[k][1] * pow(x[i], (float)(k - 1)); 
        }

        chi2 += pow(y[i] - sum, 2);
    }

    s = sqrt(chi2 / (N - m));

    for(i=1; i <= m ;i++) 
    {
        for(j = 1; j <= m; j++) 
        {
            if(i == j) error[i] = A[i][j] * s;
        }
    }

    printf("Chi2 = %f\n",chi2);
    for (i = 1; i <= m; i ++)
    {
        printf("a[%d] = %f +/- %f\n", (i - 1), b[i][1], error[i]);
    }
    return(0);
}
