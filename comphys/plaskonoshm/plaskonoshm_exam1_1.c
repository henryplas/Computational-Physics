#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  double t = 0;
  double g = 9.8;
  double v0x,v0y,v;
  double x,x0,y;
  double y0 = 0;
  FILE *out;

  if((out = fopen("plaskonoshm_ball.out","w")) == NULL) {
    printf("Cannot open ball file\n");
    exit(1);
  }

  int ni;

  printf("Enter an initial x position > ");
  ni = scanf("%lf",&x0);
  
  while (y0 <= 0.0){
    printf("Enter an initial y position (greater than 0) > ");
    ni = scanf("%lf",&y0);
    }

    printf("Enter an initial x velocity > ");
    ni = scanf("%lf",&v0x);

    printf("Enter an initial y velocity > ");
    ni = scanf("%lf",&v0y);
    

            
  //do while would be better. But I'm a maniac and hav two test cases.
  while(y >= 0.0) {
    printf("x = %f y = %f\n",x,y);
    x = x0 + v0x * t;
    y = y0 + v0y * t - (0.5) * g * t * t;
    t += 1.0;
    if (y >= 0.0)
        {
            fprintf(out,"x = %f y = %f\n",x,y);
        }
  }

  return(0);
}
