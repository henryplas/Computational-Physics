#include <stdio.h>
#include <math.h>


int main()
{
  double x = sqrt(2);
  double y = pow(2, 0.25);
  double pi = 2 + sqrt(2);
  int q = 0;


  for(int i = 0; i < 5; i++)
    {
        printf("x(%d) = %lf  y(%d) = %lf pi(%d) = %17.15lf\n",i,x,i,y,i,pi);
        x = 0.5 * (sqrt(x) + (1/(sqrt(x))));
        
        if (q >= 1)
            y = ((y * sqrt(x)) + (1/sqrt(x))) / (y + 1);
        q++;
        pi *= (x + 1)/(y + 1);
      
    }

  return(0);
}
