#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"


int main()
{
    long idum = -1;
    time_t now;
    float x,rn;
    /* Use the time function to supply a different seed to the
    random number generator every time the program is run */
    now = time(NULL);
    idum = -1*now;
    /* Initialize random number generator */
    rn = ran1(&idum);
    
    /* Now you can generate any number of random numbers between 0
    .0
    and 1.0 with statements like the following: */
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    for (int i = 0; i < 1000; i++)
    {    
        x = ran1(&idum);

        if (x >= 0 && x < 0.25)
            count0++;
        else if (x >= 0.25 && x < 0.5)
            count1++;
        else if (x >= 0.5 && x < 0.75)
            count2++;
        else
            count3++;
    }

    printf("Bin1: %d Bin2: %d Bin3: %d Bin4: %d\n", count0, count1, count2, count3);



    return(0);

}

