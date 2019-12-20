#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"

int coinflip(long *idum);

int main()
{
    long idum = -1;
    time_t now;
    now = time(NULL);
    idum = -1*now;

    int i = 0;
    int j = 0;
    int sum = 0;
    double N;
    int flip[4];

    for (i = 0; i < 1000; i++)
    {
        sum = 0;
        for (j = 0; j < 4; j++)
        {
            flip[j] = coinflip(&idum);
            sum += flip[j];
        }
        if (sum == 3)
        {
            N++;
        }   
        
    }
    
    printf("Probability for 1h/3t after 1000 flips = %lf\n",N/1000.0);

    
    return(0);
}

int coinflip(long *idum)
{
    float x,rn;
    int y;
    
    rn = ran1(idum);
    x = ran1(idum);

    if (x < 0.5)
    {
        y = 0;
    }
    else
    {
        y = 1;
    }
    
    return(y);
}
