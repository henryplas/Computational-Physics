#include <stdio.h>
#include "comphys.h"
#include "comphys.c"


int main()
{
    int bin0 = 0;
    int bin1 = 0;
    int bin2 = 0;
    int bin3 = 0;
    int bin4 = 0;
    int bin5 = 0;
    int bin6 = 0;
    int bin7 = 0;
    int bin8 = 0;
    int bin9 = 0;
    float sum = 0;
    float average = 0;
    float SD = 0;
    float sigma = 0;

    float grain[50];
    int i,ni;

    for(i=0;i<50;i++) 
        ni = scanf("%f",&grain[i]);

    qsfloat(grain,0,49);


    
    for(i = 0 ; i < 50; ++i) 
    {
        printf("%f\n", grain[i]);

        if (grain[i] >= 1.0 && grain[i] < 1.1)
            bin0++;
        else if (grain[i] >= 1.1 && grain[i] < 1.2)
            bin1++;
        else if (grain[i] >= 1.2 && grain[i] < 1.3)
            bin2++;
        else if (grain[i] >= 1.3 && grain[i] < 1.4)
            bin3++;
        else if (grain[i] >= 1.4 && grain[i] < 1.5)
            bin4++;
        else if (grain[i] >= 1.5 && grain[i] < 1.6)
            bin5++;
        else if (grain[i] >= 1.6 && grain[i] < 1.7)
            bin6++;
        else if (grain[i] >= 1.7 && grain[i] < 1.8)
            bin7++;
        else if (grain[i] >= 1.8 && grain[i] < 1.9)
            bin8++;
        else
            bin9++;

        sum += grain[i];

        
    }

    average = sum/50.0;

    for(i = 0 ; i < 50; ++i) 
    {
        sigma += pow(grain[i] - average, 2);
    }

    SD = sqrt(0.02 * sigma);


        printf("1.0 - 1.1 > %d\n1.1 - 1.2 > %d\n1.2 - 1.3 > %d\n1.3 - 1.4 > %d\n1.4 - 1.5 > %d\n", 
            bin0, bin1, bin2, bin3, bin4);
        printf("1.5 - 1.6 > %d\n1.6 - 1.7 > %d\n1.7 - 1.8 > %d\n1.8 - 1.9 > %d\n1.9 - 2.0 > %d\n", 
            bin5, bin6, bin7, bin8, bin9);
        printf("Average > %f\n", average);
        printf("SD > %f\n", SD);

    return(0);
}