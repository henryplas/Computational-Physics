//Henry Plaskonos
//dec 3 2018
//ex10.2
/* Computes the h(t) using Fourier Series*/

#include <stdio.h>
#include <math.h>
#include "comphys.c"
#include "comphys.h"
#define pi 3.141592653589793

double trap(double l,double u,int m,int N); // Use trapezoidal method
double integrand(double x, int m); // This is the integrand of the bms
double w=1.0; //omega (here - w-2pi/Period where Period=2pi)
int main()
{
   FILE *out,*rsp;
   int m = 0; // Index of the b coefficients
   int M=5; // Number of coeeficients to compute - **change this**
   int T=201;  // Number of time steps (200 is sufficient to resolve)
   int t; // This is a counter to keep track of the h(t) function to plot
   double *a,*h,j,dj;
   double ll,ul;
   double a0;
   a=dvector(0,M);  // coefficients
   h=dvector(1,T);  // function built from Fourier terms
   ll=-pi;  // lower time limit
   ul=pi;   // upper time limit

// Prepare to write for plotting
   //printf("\nBrute force complex Fourier transform algorithm");
   if ((out=fopen("fs.out","w"))==NULL) {
      printf("\nCannot open file for output\n");
      getchar();
      return(0);  		
   }

// Loop through the wave numbers    
   a[0] = (0.5/pi) * trap(ll,ul,m,T); //calculate a_0
   printf("\na[0]=%f",a[0]);
   for (m=1;m<=M;m++)
   { 

      a[m]=(1.0/pi)*trap(ll,ul,m,T);
      printf("\na[%d]=%f",m,a[m]);

// Build the h(t) function as we go
      t=0;
      dj=(ul-ll)/(double)T;
      for (j=ll;j<=ul;j+=dj)
      {
         t++;
         h[t]+=a[m]*cos((double)m*w*j);
      }
   }
   t=0;
   for(j=ll;j<=ul;j+=dj)
   {
     t++;
     h[t]+=a[0];
   } 

// Write out for plotting
   t=0;
   for (j=ll;j<=ul;j+=dj)
   {
      t++;
      fprintf(out,"%f %f\n",j,h[t]);
   }

   fclose(out);

    if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
        printf("\nCannot open gnuplot.rsp for writing\n");
        exit(1);
    }

    fprintf(rsp,"plot \"fs.out\" using 1:2 with lines\n");
    fprintf(rsp,"pause mouse\n");
    fprintf(rsp,"replot\n");
    fclose(rsp);

    if(system("gnuplot gnuplot.rsp") == -1) {
        printf("\nCommand could not be executed\n");
        exit(1);
    }




   printf("\nProgram complete without known error.\n");
   return(0);
}

double trap(double l, double u, int m, int N)
{
   double x,integral,dx;
   int i;

   if (u==l) return (0.0);
   dx=(u-l)/(double)(N-1);

   integral=0.0;
   integral+=0.5*(integrand(u,m)-integrand(l,m));
   x=l+dx;
   for (i=1;i<N;i++)
   {
       integral += integrand(x,m);
       x+=dx;
   }
   integral*=dx;
   return(integral);
}

double integrand(double x, int m)
{
   if (m == 0)
   {
   	if (x < 0) return 1 + (x/pi);
   	else return 1 - (x/pi);
   }
   if (x<0) return ((1 + (x/pi)) * cos((double)m*w*x));
   else return((1 - (x/pi)) * cos((double)m*w*x));
}

