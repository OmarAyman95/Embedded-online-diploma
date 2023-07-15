#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

/*

this code will gen compiler error 
because its impossible to use recursive with inline function 
*/

/*==================Includes=======================*/


/*=====================MACRos======================*/

//#define main __main
/*===================prototypes====================*/

static  inline void fun1(char *arr)__attribute__((always_inline));;
/*===================typeDefs======================*/


/*===================private variables=============*/


int main(int argc, char const *argv[])
{
	char arr[]="My name is Omar Ayman" ;
	fun1(arr);
	return 0;
}

static inline void fun1(char *arr)
{
	static int i = 0 ;
	if(++i < 10)
	{
		printf("%s\n",arr );
		fun1(arr+1);
	}
}

