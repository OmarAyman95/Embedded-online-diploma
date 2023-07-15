#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

/*==================Includes=======================*/


/*=====================MACRos======================*/

//#define main __main
/*===================prototypes====================*/
float squareRoot(float n);
float squareRootX(float n);
/*===================typeDefs======================*/


/*===================private variables=============*/

int main(int argc, char const *argv[])
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		printf("Square rootX of %d is %0.3f\n", n, squareRootX(n));
		printf("Square  root of %d is %0.3f\n", n, squareRoot(n));
		fflush(stdin);fflush(stdout);
	}
	return 0;
}
float squareRoot(float n)
{
	/*We are using n itself as initial approximation
This can definitely be improved */
	float x = n;
	float y = 1;
	float e = 0.0001; /* e decides the accuracy level*/
	while (x - y > e) {
		x = (x + y) / 2;
		y = n / x;
	}
	return x;
}

//my method
float squareRootX(float n)
{
    int i = 1; 
    float tempX;
    float e = 0.0001; /* e decides the accuracy level*/
    float L=0.0;
    for(;tempX<n;i++)
        tempX = i*i;
    if(i>=2)
        L = i - 2 ;
    //printf("L = %f\n",L);
    tempX = 0;
    while(tempX < n)
    {
       tempX = L*L;
       //printf("L2: %f\ntempX: %f\n",L2,tempX);
       L+=e;
    }
    return L ;
}