//Henry Plaskonos
//dec 3 2018
//ex10.3
/*Uses FFT to find noise. Low pass filters noise, 
then inverse FFTs the data*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.c"
#include "comphys.h"
#define pi 3.141592653589793


int main()
{
  FILE *in,*out,*rsp;
  float *signal,*time,*f;
  long i,N;

  N = 512;
  signal = vector(1,N);
  time = vector(1,N);
  f = vector(1,N);

  if((in = fopen("signal.dat","r")) == NULL) 
  {
    printf("\nCannot open file for input\n");
    exit(1);
  }

  if((out = fopen("output.out","w")) == NULL) {
    printf("\nCannot open file for output\n");
    exit(1);
  }

  i = 1;
  while(fscanf(in, "%f %f", &time[i], &signal[i]) != EOF) i++;

  realft(signal, N, 1);

  for(i = 1; i <= N; i++)
  {
    f[i] = (float)i/12.0;
  }

  for(i = 1; i <= N; i++)
  {
    if (f[i] <= 5) signal[i] *= 1;
    else signal[i] *= 0;
  }

  realft(signal, N, -1);

  for(i = 1; i <= N; i++)
  {
    fprintf(out,"%f %f\n", time[i], signal[i]*(2.0/(float)N));
  }

  fclose(out);
  fclose(in);
  free_vector(signal,1,N);
  free_vector(time,1,N);
  free_vector(f,1,N);

  if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
    printf("\nCannot open gnuplot.rsp for writing\n");
    exit(1);
  }

  fprintf(rsp,"plot \"output.out\" using 1:2 with lines\n");
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

