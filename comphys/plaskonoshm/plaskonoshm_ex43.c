//Henry Plaskonos
//ex43
//Sept 29, 2018
//This program linearly interpolates a value within an array of known values.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double interpolate(double pressure);

int main()
{
	double x = 0;
	int ni;
	double p;
	printf("Enter a value to interpolate within [50, 2150] > ");
	while (x < 50 || x > 2150)
		ni = scanf("%lf", &x);
	p = interpolate(x);
	printf("The value for temperature = %lf\n", p);


	return(0);
}

double interpolate(double pressure)
{
	double pressureArray[] = {50,100,150,200,250,300,350,400,450,500,550,600,650,
		700,750,800,850,900,905,910 ,915 ,920,925,930,935,940 ,945,950,955,960,
		965,970,975,980,985,990,995,1000 ,1005,1010,1015 ,1020 ,1025 ,1030 ,
		1035 ,1040 ,1045,1050,1055 ,1060 ,1065 ,1070,1075 ,1080 ,1085 ,1090,
		1095,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,1650,1700,
		1750,1800,1850,1900,1950,2000,2100, 2150};
	double tempArray[] = {32.88,45.82,53.98,60.07,64.98,69.11,72.70,75.88,78.74,
		81.34,83.73,85.95,88.02,89.96,91.78,93.51,95.15,96.71,96.87,97.02,97.17,
		97.32,97.47,97.62,97.76,97.91,98.06,98.21,98.35,98.50,98.64,98.78,98.93,
		99.07,99.21,99.35,99.49,99.63,99.77,99.91,100.05,100.19,100.32,100.46,
		100.60,100.73,100.87,101.00,101.14,101.27,101.40,101.54,101.67,101.80,
		101.93,102.06,102.19,102.32,103.59,104.81,105.99,107.14,108.25,109.32,
		110.36,111.38,112.37,113.33,114.26,115.18,116.07,116.94,117.79,118.63,
		119.44,120.24,121.02,121.79,122.54};
	int i;
	int j;
	double p1;
	double p2;
	double t1;
	double t2;
	double y;

	for(i = 0 ; i < 79 ; i++) 
	{
		if(pressureArray[i] < pressure && pressureArray[i + 1] >= pressure) 
		{
			j = i;
			break;
		}
	}

	p1 = pressureArray[j];
	p2 = pressureArray[j + 1];
	t1 = tempArray[j];
	t2 = tempArray[j + 1];

	y = (((p2 - pressure) / (p2 - p1)) * t1) +
		(((pressure - p1) / (p2 - p1)) * t2);
	
	return(y);
}
