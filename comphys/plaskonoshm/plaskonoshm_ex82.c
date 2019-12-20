//Henry Plaskonos
//ex82
//Enhanced euler method

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    double x1,y1,yp2,x2,y2;
    double dx = 0.0000001;

    /* initial conditions */
    x1 = 0.0;
    y1 = 1.0;
    printf("x = %f y = %f\n",x1,y1);

    /* Integrate using Improved Euler from x=0 to x=1 */
    while(x1 < 1.0) {
        yp2 = y1 + (x1 - 1)*y1*y1*dx;
        y2 = y1 + 0.5*((x1 - 1)*y1*y1 + ((x1+dx) - 1)*yp2*yp2)*dx; 
        x2 = x1 + dx;
        if(x2 > 1.0) break;
        printf("x = %f y = %f\n",x2,y2);
        x1 = x2;
        y1 = y2;
    }

    return(0);
}
