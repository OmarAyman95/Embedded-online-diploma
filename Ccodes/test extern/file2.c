#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

/*==================Includes=======================*/


/*=====================MACRos======================*/


/*===================prototypes====================*/


/*===================typeDefs======================*/


/*===================private variables=============*/
uint8_t Var1 = 109;

void fun2(void)
{
	#define PRINT printf
}

void fun1(void)
{
	PRINT("%u\n",Var1);
}