
//Henry Plaskonos
//Ex 3.7
// 9/13/2018
//Code reads in co2 data and performs temperature calculations. creates output file 
// of years and temperatures. Creates graph with output file.



#include <stdio.h>
#include <stdlib.h> /* Needed for exit() */
#include <math.h>


int main()
{

    double co2;
    double temp;
    double year;
    int ni;
    FILE *in, *out, *rsp;

    if((in = fopen("vostok_co2.dat","r")) == NULL) 
    {
        printf("\nCannot open file for input\n");
        exit(1);
    }

    if((out = fopen("outfile.out","w")) == NULL) 
    {
        printf("\nCannot open %s for writing\n","vostok_co2.dat");
        exit(1);
    }

    while(fscanf(in,"%lf  %lf\n",&year, &co2) != EOF) 
    {
        temp = 2.5 * (co2 - 365.0) / 280.0;
        fprintf(out,"%lf  %lf\n", year, temp);
    }

    fclose(in);
    fclose(out);

    if((rsp = fopen("gnuplot.rsp","w")) == NULL) 
    {
        printf("\nCannot open gnuplot.rsp for writing\n");
        exit(1);
    }

    fprintf(rsp,"plot \"%s\" using 1:2 with lines\n", "outfile.out");
    fprintf(rsp,"pause mouse\n");
    fprintf(rsp,"replot\n");
    fclose(rsp);

    if(system("gnuplot gnuplot.rsp") == -1) 
    {
        printf("\nCommand could not be executed\n");
        exit(1);
    }

    return(0);
}
