//Henry Plaskonos
//ex42
//Sept 29, 2018
//This program linearly interpolates a value within an array of known values.
//



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double interpolate(double wavelength);

int main()
{	

	double x;
	int ni;
	double n;

	printf("Enter a value to interpolate > ");
	ni = scanf("%lf", &x);
	n = interpolate(x);
	printf("The value for n = %lf\n", n);


	return(0);
}

double interpolate(double wavelength)
{
	int waveArray[] = {3511,3638,4047,4358,4416,4579,4658,4727,4765,4800,
		4861,4880,4965,5017,5145,5320,5461,5876,5893,6328,6438,6563,6943,
		7860,8210,8300,8521,9040,10140,10600,13000,15000,15500,19701,23254};

	double nArray[] = {1.53894,1.53648,1.53024,1.52669,1.52611,1.52462,
		1.52395,1.52339,1.52310,1.52283,1.52238,1.52224,1.52165,1.52130,
		1.52049,1.51947,1.51872,1.51680,1.51673,1.51509,1.51472,1.51432,
		1.51322,1.51106,1.51037,1.51021,1.50981,1.50894,1.50731,1.50669,
		1.50371,1.50130,1.50068,1.49500,1.48929};
	int i;
	int j;
	double lambda1;
	double lambda2;
	double n1;
	double n2;
	double y;

	for(i = 0 ; i < 35 ; i++) 
	{
		if(waveArray[i] < wavelength && waveArray[i + 1] >= wavelength) 
		{
			j = i;

			break;
		}
	}

	lambda1 = waveArray[j];
	lambda2 = waveArray[j + 1];
	n1 = nArray[j];
	n2 = nArray[j + 1];

	y = (((lambda2 - wavelength) / (lambda2 - lambda1)) * n1) +
		(((wavelength - lambda1) / (lambda2 - lambda1)) * n2);



	return(y);




}