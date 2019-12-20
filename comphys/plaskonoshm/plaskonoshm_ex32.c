#include <stdio.h>
#include <math.h>


void doit(double t);


int main()
{
  double T = 100.0;
  doit(T);
  
  printf("%lf \n", T);



  
  return(0);
}


void doit(double t)
{
  t *= 2.5;

}
