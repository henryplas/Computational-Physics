//Henry Plaskonos
//Fits data to custom function (harmonic sine in this case)
//ex95

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"
#include <math.h>

float X1(float t);
float X2(float t);
float X3(float t);
float X4(float t);

float pi = 3.141592654;

int main()
{
	//X[0](pi/2.0)

	float (*func[4])(float) = {X1,X2,X3,X4};	
    float x[100];
    float y[100];
    float **A;
    float **b;
    float *error;
    float chi2 = 0;
    int m, k, j, l, ni;
    int i, q, N;
    float s, sum = 0;
   
    FILE *in;

    m = 4;

    A = matrix(1,m,1,m);
    b = matrix(1,m,1,1);
    error = vector(1, m);

    if((in = fopen("data95.dat","r")) == NULL) 
    {
        printf("\nCannot open file for input\n");
        exit(1);						
    }
    
    l = 0;
    while(fscanf(in, "%f %f",&x[l], &y[l]) != EOF) 
    {
        for(k = 1; k <= m; k++)
        {
            b[k][1] += y[l] * func[k -1](x[l]);
            for(j = 1; j <= m; j++)
            {
                A[k][j] += func[j - 1](x[l]) * func[k - 1](x[l]);
                		
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
            sum += b[k][1] * func[k -1](x[i]);  
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




	return(0);
}

float X1(float x) //does nothing with pass by variable
{
	return(1);
}

float X2(float x)
{
	return(sin(pi * x));
}

float X3(float x)
{
	return(sin(2*pi*x));
}

float X4(float x)
{
	return(sin(3*pi*x));
}
