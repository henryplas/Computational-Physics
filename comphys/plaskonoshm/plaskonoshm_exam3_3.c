
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
float X5(float t);

float pi = 3.141592654;

int main()
{
	float (*func[5])(float) = {X1,X2,X3,X4,X5};	
    float x[1000];
    float y[1000];
    float **A;
    float **b;
    float *error;
    float chi2 = 0;
    int m, k, j, l, ni;
    int i, q, N;
    float s, sum = 0;
   
    FILE *in;

    m = 5;

    A = matrix(1,m,1,m);
    b = matrix(1,m,1,1);
    error = vector(1, m);

    if((in = fopen("scatter.dat","r")) == NULL) 
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
            if(i == j) error[i] = sqrt(A[i][j])) * s;
        }
    }

    printf("Chi2 = %f\n",chi2);
    for (i = 1; i <= m; i ++)
    {
        printf("a[%d] = %f +/- %f\n", (i - 1), b[i][1], error[i]);
    }
    return(0);


}

float X1(float x) //does nothing with pass by variable
{
	return(1);
}

float X2(float x)
{
	return(x);
}

float X3(float x)
{
	return(x*x);
}

float X4(float x)
{
	return(bessj0(2*pi*x));
}

float X5(float x)
{
	return(bessj1(pi*x));
}


















