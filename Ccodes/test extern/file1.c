#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

/*==================Includes=======================*/


/*=====================MACRos======================*/

//#define main __main
/*===================prototypes====================*/

extern void fun1(void);
/*===================typeDefs======================*/


/*===================private variables=============*/

uint8_t Var1 ;


/*=========================main===================*/
int main(void)
{
	printf("%u\n",Var1);
	Var1 = 100;
	
	fun1();
	return 0;
}


