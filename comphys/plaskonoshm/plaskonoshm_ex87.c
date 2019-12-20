//Henry Plaskonos
//Uses a-b-m routine on 2nd order DE
//ex87


#include <stdio.h>
#include <math.h>
double yfunc(double x);
double yderiv(double x);
double y2der(double x);
/* Implements the Adams-Bashforth-Moulton routine */
int main()
{
	double xm2,xm1,x0,x1,ym2,ym1,y0,y1;
	double zm2,zm1,z0,z1;
	double ypm2,ypm1,yp0,yp1;
	double zpm2,zpm1,zp0,zp1;
	double dx = 0.1;

	/* Prime the Pump! */
	ym2 = yfunc(0.0);
	ypm2 = yderiv(0.0);
	zm2 = ypm2;
	zpm2 = y2der(0.0);
	ym1 = yfunc(0.1);
	ypm1 = yderiv(0.1);
	zm1 = ypm1;
	zpm1 = y2der(0.1);
	y0 = yfunc(0.2);
	yp0 = yderiv(0.2);
	z0 = yp0;
	zp0 = y2der(0.2);
	xm2 = 0.0;
	xm1 = 0.1;
	x0 = 0.2;
	x1 = 0.3;
	y1 = 8;

	printf("x = %3.1f y = %f\n",xm2,ym2);
	printf("x = %3.1f y = %f\n",xm1,ym1);
	printf("x = %3.1f y = %f\n",x0,y0);

	while(y1 > 0) 
	{
		/* Predictor step */
		z1 = z0 + (23.0*zp0 - 16.0*zpm1 + 5.0*zpm2)*dx/12.0;
		y1 = y0 + (23.0*z0 - 16.0*zm1 + 5.0*zm2)*dx/12.0;

		/* Calculate yp1 */

		yp1 = z1;
		zp1 = -1*2*z1/x1 - y1*y1*y1;

		/* Corrector step */
		z1 = z0 + (5.0*zp1 + 8.0*zp0 - zpm1)*dx/12.0;
		y1 = y0 + (5.0*z1 + 8.0*z0 - zm1)*dx/12.0;

		/* Recalculate yp1 - this step is optional! */
		yp1 = z1;
		zp1 = -1*2*z1/x1 - y1*y1*y1;

		printf("x = %3.1f y = %f\n",x1,y1);
		if(y1 == 0.0) break;
		/* Update variables */
		xm2 += dx;
		xm1 += dx;
		x0 += dx;
		x1 += dx;
		ym2 = ym1;
		ym1 = y0;
		y0 = y1;
		ypm2 = ypm1;
		ypm1 = yp0;
		yp0 = yp1;
		zm2 = zm1;
		zm1 = z0;
		z0 = z1;
		zpm2 = zpm1;
		zpm1 = zp0;
		zp0 = zp1;
	}
	return(0);
}

double yfunc(double x)
{
	
	return 1 - (x*x / 6) + (3*x*x*x*x/120) + ((5*3 - 8*3*3)*(pow(x,6.0)/(3*5040)));
}

double yderiv(double x)
{
	return -1*(x/3) + (3*4*x*x*x/120) + ((5*3 - 8*3*3)*6*(pow(x,5.0)/(3*5040)));
}

double y2der(double x)
{
	return -1/3 + (3*4*3*x*x/120) + ((5*3 - 8*3*3)*6*5*(pow(x,4.0)/(3*5040)));
}
