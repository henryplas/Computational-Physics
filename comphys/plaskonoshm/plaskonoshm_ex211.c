#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"

int main()
{
    long idum = -1;
    time_t now;
    float x,rn,e;
    float S = 0;


    now = time(NULL);
    idum = -1*now;


    rn = ran1(&idum);

    for (int i = 0; i < 100; i++)
    {    
        e = 10 * ran1(&idum); //random value of epsilon

        if (e > 4.5553)
        {
            x = ran1(&idum); //finds random value for percent
            if (x > 0.354) //if in the 64.6% chance
            {
                S = 12.3925 + (4.9311 * (e - 4.5553)) - (1.02 * pow(e - 4.5553, 2));
            }

            else // if in the 35.4%
            {
                S = 12.3925 +   (e - 4.5553) + (0.23 * pow(e - 4.5553, 2));
            }

            printf("S = %f\n", S);
        }

    }

    return(0);

}