//Henry plaskonos
//Ex 3.4
//9/13/2018
//program function getp is modified for exp(x)


#include <stdio.h>
#include <stdlib.h>
#include<math.h>


double getp(int i, double x);
double geterror(double p, double pstar);
double factorial(int i);

const double pi = 3.141592653589793;

int main(int argc, char const *argv[])
{
    int i, N, ni;
    int M = 50;
    double tolerance = 0.0;
    double error = 0.0;
    double p = 0.0;
    double pstar;
    double x;

    x = pi / 4.0;

    while (tolerance <= 0.0)
    {
        if (argc != 2) 
        {
            ("\nEnter the tolerance (scientific notation, e.g. 1.5e-13) > ");
            ni = scanf("%le",&tolerance);
        }
        else 
            tolerance=atof(argv[1]);

        if (tolerance == 0.0)
        {
            printf("\nTolerance can not be zero or negative, try again...\n\n");
            return (0);
        }
    }

    pstar = exp(x);

    for (i = 1; i <= M; i++)
    {
        p=p+getp(i,x);
        error = geterror(p,pstar);
        printf("%d %le\n",i,error);
        if (error<tolerance)
            break;
        if (i==M)
        {
            printf("\nThe number of iterations exceeds allowable maximum, retry\n");
            printf("\nwith new tolerance or change max limit.\n");
            break;
        }

    }
    return 0;
}


double getp(int i, double x)
{
    double term0;
    double term1;

    term0 = pow(x, i -1);
    term1 = (double)factorial(i - 1);
    return(term0 / term1);

}

double geterror(double p, double pstar)
{
    return ( fabs(pstar-p) );
}

double factorial(int i)
{


    int j;
    double result = 1.0;
    if (i==0)
    {
        return (1.0);
    }

    else
    {
        for (j = 1; j <= i ; j++)
        {
            result = result * (double)j;

        }
    }
    return(result);
}

