#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"
#include <math.h>


int main()
{
    float **a, **b;

    a = matrix(1,3,1,3);
    b = matrix(1,3,1,1);

    a[1][1] = 1.0;
    a[1][2] = 5.0;
    a[1][3] = 3.0;
    a[2][1] = 2.0;
    a[2][2] = 1.0;
    a[2][3] = 9.0;
    a[3][1] = 3.0;
    a[3][2] = 8.0;
    a[3][3] = 8.0;

    b[1][1] = 5.0;
    b[2][1] = 2.0;
    b[3][1] = 1.0;

    gaussj(a,3,b,1);
    printf("x = %f, %f, %f\n", b[1][1],b[2][1],b[3][1]);   
    return(0);
}
