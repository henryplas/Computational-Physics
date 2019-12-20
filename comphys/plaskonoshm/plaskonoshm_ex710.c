//Henry Plaskonos
//ex7.10
//8 Oct 2018
//Numerically integrates a double integral. Finds gravity at chosen location.

#include <stdio.h>
#include <math.h>

double trap(double a, double b, double (*func)(double), int N);
double integrand(double y);
double l1();
double l2();
double twoDtrap(double a, double b,int N);
double H(double y1, double y2);
double x;
double r;
int N;
double x_co;
double y_co;
int check = 1;

const double pi = 3.141592653589793;

int main()
{
    double a = -1.0;
    double b = 1.0;
    double result;
    printf("\nEnter number of points for both x and y > ");
    scanf("%d",&N);

    while(check)
    {
    	printf("Enter x coordinate (not on 2mx2m square over origin) >");
    	scanf("%lf",&x_co);
    	printf("Enter y coordinate (not on 2mx2m square over origin) >");
    	scanf("%lf",&y_co);
    	if(x_co > 1 || x_co < -1)
    		check = 0;
    	if (y_co > 1 || y_co < -1)
    		check = 0;
	}
   
   	r = sqrt(x_co*x_co + y_co*y_co);

    result = twoDtrap(a,b,N);
    printf("\nIntegral = %e\n J",result);
    return(0);
}

double twoDtrap(double a, double b, int N)
{
    double h,integral;
    int i;
    h = (b - a)/(double)(N-1);
    integral = 0.0;
    x = a;
    integral += 0.5 * H(-1,1);
    x = b;
    integral += 0.5 * H(-1,1);
    x = a + h;
    
    for(i = 2; i < N; i++) 
    {
        integral += H(-1,1);
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
	double G = 6.674084e-11;

    return -1 * G * y*y + x*x / r;
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







