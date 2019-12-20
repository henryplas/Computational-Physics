#include <stdio.h>
#include <math.h>


void doit();
double T = 100.0;

int main()
{

  doit();
  
  printf("%lf \n", T);



  
  return(0);
}


void doit()
{
  T *= 2.5;

}
