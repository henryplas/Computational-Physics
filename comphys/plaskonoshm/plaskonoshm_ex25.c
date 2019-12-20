#include <stdio.h>
#include <math.h>



//vars



int main()
{

  double x = 1;
  double x1 = 0;
  double pi = 2 + sqrt(2);
    
  while(fabs(x - x1) > 1.0e-7)
    {
      x = x1;
      x1 = 5.0 + 2.0/x;
      printf("x = %lf\n", x1);
      
      
    }

  return(0);

}
