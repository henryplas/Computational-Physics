#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"
int ranwalk(long *idum);

int main()
{
  long idum = -1;
  int check = 0;
  int i,j;
  float x,rn;
  time_t now;

  // Initialize random number generator (once!)
  now = time(NULL);
  idum = -1*now;

  rn = ran1(&idum);

  // The 100000 random walks!

  for(i=0;i<1000;i++) {
    check += ranwalk(&idum);
  }

  printf("The probability that a particle will leave is %f\n",(float)check/1000.0);



  return(0);

}

// Computes a single random walk of 100 steps.  Returns the x position.
int ranwalk(long *idum)
{
  float x;
  int posx = 0;
  int posy = 0;
  int outside;

  while(1) 
  {
    x = ran1(idum);
    if (x < 0.1){
      outside = 0;
      break;
    }

    x = ran1(idum);
    if(x < 0.5)
    {
      x = ran1(idum);
      if (x < 0.5) posx--;
      else posx++;
    }
    else
    {
      x = ran1(idum);
      if (x < 0.5) posy--;
      else posy++;
    }

    if (sqrt(posx*posx + posy*posy) > 10) {
      outside = 1;
      break;
    }
    
  }

  return(outside);
}
