#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"

int main()
{
    long idum = -1;
    time_t now;
    float x, y, rn;

    now = time(NULL);
    idum = -1*now;
    rn = ran1(&idum);

    for (int i = 0; i < 1000 ; i++)
    {
        x = 0.5 - ran1(&idum);
        y = 0.5 - ran1(&idum);
        
        if (sqrt(x*x + y*y) < 0.5)
            printf("%f %f\n", x, y);

    }

    return(0);

}
