//Henry Plaskonos
//Fits function with non-linearleast squares
//ex96


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"
#include <math.h>

#define NDATA 51
#define MA 4

void func(float x, float a[], float *y, float dyda[], int na);

int main()
{

	float *x,*y,*sig,**covar,**alpha,*a,chisq,ochisq,alambda;
	int *ia,ma;
	FILE *in;
	int i,k,ndata,ni;
	x = vector(1,NDATA);
	y = vector(1,NDATA);
	sig = vector(1,NDATA);
	a = vector(1,MA);
	covar = matrix(1,MA,1,MA);
	alpha = matrix(1,MA,1,MA);
	ia = ivector(1,MA);
	/* Datafile contains data which are to be fitted to a double
	Gaussian.  Initial parameters file contains rough estimate
	s
	of Gaussian parameters. */

	ma = MA;
	if((in = fopen("decay.out","r")) == NULL)
		nrerror("Cannot find input file");
	
	/* Reads in data from datafile.  Defines sigma errors by takin
	g
	square roots of y-values, as these are counts.  Adds a small
	number (0.1) so that zero values of y will not have 0 errors */
	k = 1;

	while(fscanf(in,"%f %f",&x[k],&y[k]) != EOF) 
	{
		sig[k] = sqrt(y[k]) + 0.1;
		k++;
	}
	fclose(in);

	ndata = k-1;
	/* Reads in initial estimates for parameters */
	a[1] = 9.0;
	a[2] = 3.0;
	a[3] = 0.5;
	a[4] = 0.18;

	/* We are fitting all parameters a[1] .. a[6], so we fill up all
	entries in ia[] with 1’s */

	for(i=1;i<=MA;i++) ia[i] = 1;

	/* Initializing mrqmin using a negative value of alambda.
	Note we are passing the function func to mrqmin.  See
	below. */

	alambda = -1.0;
	chisq = 0.0;
	mrqmin(x,y,sig,ndata,a,ia,ma,covar,alpha,&chisq,func,&alambda);
	ochisq = chisq + 2.0;

	/* Iterating with mrqmin until relative change in chisq is le
	ss
	than 0.001 */

	while(fabs((ochisq - chisq)/ochisq) > 0.001 ) 
	{
		ochisq = chisq;
		//mrqmin(x,y,sig,ndata,a,ia,ma,covar,alpha,&chisq,func,&alambda);
	}
	/* Here we run mrqmin one more time with alambda = 0.0 to get
	covariant matrix, in case we want the errors */

	alambda = 0.0;
	//mrqmin(x,y,sig,ndata,a,ia,ma,covar,alpha,&chisq,func,&alambda);

	/* Print out the results (the a’s) along with the errors (the
	squareroots of the diagonal members of the covariant matirx
	divided by the number of degrees of freedom). */
	
	printf("%f %f\n%f %f\n%f %f\n%f %f\n",
	a[1],sqrt(chisq*covar[1][1])/(float)(ndata-MA),
	a[2],sqrt(chisq*covar[2][2])/(float)(ndata-MA),
	a[3],sqrt(chisq*covar[3][3])/(float)(ndata-MA),
	a[4],sqrt(chisq*covar[4][4])/(float)(ndata-MA)
	);
	
	return(0);
	
}


	/* For a given value of x, and input parameters a[], this function
	returns the resulting value of y and the vector dyda[] which
	contains the derivatives of y with respect to all of the a[]
	parameters */
void func(float x, float a[], float *y, float dyda[], int na)
{
	int i;
	float fac,ex,arg;
	*y = a[1] * exp(-1*a[4]*x) * sin(a[2]*x + a[3]);
	dyda[1] = exp(-1*a[4]*x) * sin(a[2]*x + a[3]);
	dyda[2] = a[1] * x * exp(-1*a[4]*x) * cos(a[2]*x + a[3]);
	dyda[3] = a[1] * exp(-1*a[4]*x) * cos(a[2]*x + a[3]);  
	dyda[4] = -1 * a[4] *a[1] * exp(-1*a[4]*x) * sin(a[2]*x + a[3]);
}
