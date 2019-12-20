
//Henry Plaskonos
//Ex 3.9
// 9/13/2018
//Code reads in co2 data and stores year and co2 in arrays. Finds max, min, and average 
// co2 for two spans of time.



#include <stdio.h>
#include <stdlib.h> /* Needed for exit() */
#include <math.h>
#include "comphys.h"
#include "comphys.c"


int main()
{

    double co2[285];
    int year[285];
    double temp[285];
    double max;
    double min;
    double sum0;
    double sum1;

    double i, j;
    int k = 0;
    int l = 0;
    int m = 1;
    int n = 1;
    int yearHold0;
    int yearHold1;

    int ni;
    FILE *in;

    if((in = fopen("vostok_co2.dat","r")) == NULL) 
    {
        printf("\nCannot open file for input\n");
        exit(1);
    }

    while(fscanf(in,"%lf  %lf\n",&j, &i) != EOF) 
    {
        co2[k] = i;
        year[k] = j;
        k++;
    }

    max = co2[0];
    min = co2[0];
    for (l = 0; l < k ; l++)
    {
        if (co2[l] > max)
        {
            max = co2[l];
            yearHold0 = year[l];

        }
        if (co2[l] < min) 
        {
            min = co2[l];
            yearHold1 = year[l];
          
        }
        if (year[l] >= 112000 && year[l] <= 130000)
        {
            sum0 += co2[l];
            m++;

        }
        if (year[l] >= 138000 && year[l] <= 175000)
        {
            sum1 += co2[l];
            n++;
        }
    }


    printf("Max CO2 > %lf ppm %d years ago\n", max, yearHold0);
    printf("Min CO2 > %lf ppm %d years ago\n", min, yearHold1);
    printf("Avg CO2 (Eemian) > %lf ppm\n", (double)(sum0 / m));
    printf("Avg CO2 (Illionian) > %lf ppm\n", (double)(sum1 / n));
    

    fclose(in);
    return(0);
}
