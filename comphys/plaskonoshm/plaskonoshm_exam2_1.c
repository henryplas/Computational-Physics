#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

double interpolate(double temp, double grainSize);

int main()
{

    double t,d,r;
	int ni;

	printf("Enter a temperature (0<t<20)> ");
	ni = scanf("%lf", &t);
	printf("Enter the grain diameter(0.01<d<0.05s) > ");

	ni = scanf("%lf", &d);
	r = interpolate(t,d);
	printf("The fall time is = %lf\n", r);



    return(0);
}


double interpolate(double temp, double grainSize)
{

	double fallTimes[21][5] = 
	{{1986.722, 496.681, 220.747, 124.170, 79.469},
    {1921.051, 480.263, 213.450, 120.066, 76.842},
    {1858.577, 464.644, 206.509, 116.161, 74.343},
    {1799.104, 449.776, 199.900, 112.444, 71.964},
    {1742.448, 435.612, 193.605, 108.903, 69.698},
    {1688.442, 422.111, 187.605, 105.528, 67.538},
    {1636.927, 409.232, 181.881, 102.308, 65.477},
    {1587.758, 396.940, 176.418, 99.235, 63.510},
    {1540.799, 385.200, 171.200, 96.300, 61.632},
    {1495.923, 373.981, 166.214, 93.496, 59.837},
    {1453.013, 363.253, 161.446, 90.813, 58.121},
    {1411.958, 352.990, 156.884, 88.247, 56.478},
    {1372.656, 343.164, 152.518, 85.791, 54.907},
    {1335.012, 333.753, 148.335, 83.438, 53.400},
    {1298.935, 324.734, 144.326, 81.184, 51.957},
    {1264.343, 316.086, 140.483, 79.021, 50.574},
    {1231.156,307.789, 136.795, 76.948, 49.246},
    {1199.301, 299.825, 133.256, 74.956, 47.972},
    {1168.710, 292.178, 129.857, 73.044, 46.748},
    {1139.318, 284.830, 126.591, 71.207, 45.573},
    {1111.065, 277.766, 123.452, 69.442, 44.443}};

	double te[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    double grain[5] = {0.01,0.02,0.03,0.04,0.05};

	int i;
	int j1,j2;
	double y1,y2,y3,y4,t,u,ret;
    
	for(i = 0 ; i < 20 ; i++) 
	{
		if(te[i] < temp && te[i + 1] >= temp) 
		{
			j1= i;
			break;
		}
	}

	for(i = 0 ; i < 4 ; i++) 
	{
		if(grain[i] < grainSize && grain[i + 1] >= grainSize) 
		{
			j2= i;
			break;
		}
	}

	y1 = fallTimes[j1][j2];
	y2 = fallTimes[j1 + 1][j2];
	y3 = fallTimes[j1 + 1][j2 + 1];
	y4 = fallTimes[j1][j2 + 1];
	t = (temp - te[j1]) / (te[j1 + 1] - te[j1]);
	u = (grainSize - grain[j2]) / (grain[j2 + 1] - grain[j2]);

	ret = (1 - t) * (1 - u) * y1 + t * (1 - u) * y2 + t * u * y3 + (1 - t) * u * y4;
	return(ret);

}
