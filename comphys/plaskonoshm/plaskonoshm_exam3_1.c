#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"


int pos[81];
int bin[81];
void walk(long *idum);



int main()
{
  printf("here");
  int i, x;
  FILE *out,*rsp;
  printf("here");
  double rn;
  long idum = -1;
  time_t now;

  /* Use the time function to supply a constantly changing seed to the
     random number generator */
  now = time(NULL);
  printf("here");
  idum = -1*now;

  /* Initialize random number generator */
  rn = ran1(&idum);



  for (i = 0; i < 81; i++)
  {
    pos[i] = i - 40;
  } 
  
  walk(&idum);

  
  if((out = fopen("outfile.out","w")) == NULL) 
  {
    printf("\nCannot open %s for writing\n","outfile.out");
    exit(1);
  }

  for (i = 0; i < 81; i++)
  {
    fprintf(out,"%d %d\n",pos[i],bin[i]);
  }

  fclose(out);

  if((rsp = fopen("gnuplot.rsp","w")) == NULL) 
  {
    printf("\nCannot open gnuplot.rsp for writing\n");
    exit(1);
  }
  fprintf(rsp,"plot %s using 1:2 with lines\n","outfile.out");
  fprintf(rsp,"pause mouse\n");
  fprintf(rsp,"replot\n");
  fclose(rsp);

  if(system("gnuplot gnuplot.rsp") == -1) 
  {
    printf("\nCommand could not be executed\n");
    exit(1);
  }


  return(0);

}


void walk(long *idum)
{
  int j,x,i;
  double rn;
 
  for (i = 0; i < 100000; i++)
  {
     x = 0;
     for (j = 0; j < 100; i++)
     {
        rn = ran1(idum);
        if (rn < 0.5) rn = -1.0;
        else rn = 1.0;
        x += rn;
     }

     x += 40;
     bin[x]++;

  }

}

























