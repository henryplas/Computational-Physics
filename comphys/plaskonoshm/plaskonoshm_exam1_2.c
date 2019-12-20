#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  double t;
  double signal1,signal2,signal3;
  double sig1Arr[100];
  double sig2Arr[100];
  double sig3Arr[100];
  double timeArr[100];
  double avg;
  int i = 0;
  FILE *in1,*in2,*in3,*out,*rsp;

  if((in1 = fopen("trial1.dat","r")) == NULL) {
    printf("Cannot open trial1 data file\n");
    exit(1);
  }

  if((in2 = fopen("trial2.dat","r")) == NULL) {
    printf("Cannot open trial2 data file\n");
    exit(1);
  }

  if((in3 = fopen("trial3.dat","r")) == NULL) {
    printf("Cannot open trial3 data file\n");
    exit(1);
  }

  if((out = fopen("plaskonoshm_signal.out","w")) == NULL) {
    printf("Cannot open out signal data file\n");
    exit(1);
  }

  
  while(fscanf(in1,"%lf %lf\n",&t,&signal1) != EOF) {
    sig1Arr[i] = signal1;
    timeArr[i] = t;
    i++;
  }
   
  i = 0;

  while(fscanf(in2,"%lf %lf",&t,&signal2) != EOF) {
    sig2Arr[i] = signal2;
    i++;
  }

  i = 0;

  while(fscanf(in3,"%lf %lf",&t,&signal3) != EOF) {
    sig3Arr[i] = signal3;
    i++;
  }

  timeArr[0] = 0.0; //Would not read in 0 for some reason, previous while loop/file had an unknown effect
  for (i = 0; i < 101; i++)
  {
    avg = (sig1Arr[i] + sig2Arr[i] + sig3Arr[i]) / 3;
    fprintf(out,"%lf %lf\n",timeArr[i],avg);
  }


  fclose(in1);
  fclose(in2);
  fclose(in3);
  fclose(out);

  // Plot results using gnuplot
  if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
    printf("\nCannot open gnuplot.rsp for writing\n");
    exit(1);
  }
  fprintf(rsp,"plot 'plaskonoshm_signal.out' using 1:2 with lines\n");
  fprintf(rsp,"pause mouse\n");
  fprintf(rsp,"replot\n");
  fclose(rsp);
  if(system("gnuplot gnuplot.rsp") == -1) {
    printf("\nCommand could not be executed\n");
    exit(1);
  }

  fclose(out);

  return(0);
} 
