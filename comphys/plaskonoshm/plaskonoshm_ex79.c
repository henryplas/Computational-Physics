//Henry Plaskonos
//ex7.9
//8 Oct 2018
//Numerically integrates a double integral.


#include <stdio.h>
#include <math.h>

double trap(double a, double b, double (*func)(double), int N);
double integrand(double y);
double l1();
double l2();
double twoDtrap(double a, double b,int N);
double H(double y1, double y2);
double x;
int N;

const double pi = 3.141592653589793;

int main()
{
    double a = -1.0;
    double b = 1.0;
    double result;
    printf("\nEnter number of points for both x and y > ");
    scanf("%d",&N);
    result = twoDtrap(a,b,N);
    printf("\nIntegral = %e\n",result);
    return(0);
}

double twoDtrap(double a, double b, int N)
{
    double h,integral;
    int i;
    h = (b - a)/(double)(N-1);
    integral = 0.0;
    x = a;
    integral += 0.5 * H(-1 * pi / 2, pi / 2);
    x = b;
    integral += 0.5 * H(-1 * pi / 2, pi / 2);
    x = a + h;
    
    for(i = 2; i < N; i++) 
    {
        integral += H(-1 * pi / 2, pi / 2);
        x += h;
    }
    integral *= h;
    return(integral);
}

double H(double y1, double y2)
{
    return(trap(y1,y2,integrand,N));
}


double integrand(double y)
{
    return(x*x*cos(y));
}

double trap(double a, double b, double (*func)(double), int N)
{
    double h, integral, x;
    int i;
    if(a == b) return(0.0);
    h = (b - a) / (double)(N - 1);
    integral = 0.0;
    integral += 0.5 * ((*func)(a) + (*func)(b));
    x = a + h;
    h = (b - a) / (double)(N - 1);
    integral = 0.0;
    integral += 0.5 * ((*func)(a) + (*func)(b));
    x = a + h;
    for(i = 2; i < N; i++) 
    {
        integral += (*func)(x);
        x += h;
    }
    integral *= h;
    return(integral);
}






