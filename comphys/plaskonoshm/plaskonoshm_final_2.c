#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.c"
#include "comphys.h"
#define pi 3.141592653589793

void diff(float beta);
float func(float x, float y, float z, float beta);
float fMax(float beta);

float *data,*t;

int main()
{
	float check;
	data = vector(1,16384);
  	t = vector(1,16384);

  	double a = 0.0001;
    double b = 50;
    double c = 1000.0;
    double x;
    double dif;

    dif = fabs(a - c);
    while(dif > 1e-5)
    {
        if (fabs(b - c) < fabs(a - b))
        {
            x = (a + b) / 2;
            if (fMax(b) > fMax(x))
            {
                c = b;
                b = x;
                
            }
            else
            {
                a = x;
            }
                
        }
        else
        {
            x = (c + b) / 2;
            if (fMax(b) > fMax(x))
            {
                a = b;
                b = x;
            }
            else
            {
                c = x;
            }       
        }
        
        dif = fabs(c - a);
    }

    printf("beta = %lf for resonance\n", x);



	return(0); 		


}

float func(float x, float y, float z, float beta)
{
	return 0.2 * cos(beta * x) - 2.5*y - 0.1*z;
}

void diff(float beta)
{

	double x1,y1,z1,x2,y2,z2;
	double k1,k2,k3,k4,l1,l2,l3,l4;
	int i = 1;
	float dx = 0.01;
	x1 = 0;
	y1 = 1;
	z1 = 0;
	while(i <= 16384) 
	{
		k1 = z1*dx;
		l1 = func(x1,y1,z1,beta)*dx;
		k2 = (z1+0.5*l1)*dx;
		l2 = func(x1+0.5*dx,y1+0.5*k1,z1+0.5*l1,beta)*dx;
		k3 = (z1+0.5*l2)*dx;
		l3 = func(x1+0.5*dx,y1+0.5*k2,z1+l2*0.5,beta)*dx;
		k4 = (z1+l3)*dx;
		l4 = func(x1+dx,y1+k3,z1+l3,beta)*dx;
		y2 = y1 + (k1 + 2.0*k2 + 2.0*k3 + k4)/6.0; 
		z2 = z1 + (l1 + 2.0*l2 + 2.0*l3 + l4)/6.0; 
		x2 = x1 + dx;
		x1 = x2;
		y1 = y2; 
		z1 = z2;
		data[i] = y1;
		t[i] = x1;
		i++;
	}
}

float fMax(float beta)
{
	int i;
	float check;
  	diff(beta);
	realft(data,16384,1);
	check = 0;
	for(i = 1; i <= 16383; i++)
	{
		if (fabs(data[i]) > check)
		{
			check = fabs(data[i]);
		}
	}
	return -check;

}

