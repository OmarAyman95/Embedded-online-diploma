/*
 * main.c
 *
 *  Created on: Sep 18, 2022
 *      Author: OMAR_AYMAN
 */

/*libraries*/
#include"stdio.h"
#include"stdint.h"
#include <stdlib.h>
/*macros*/
#define FLUSH fflush(stdin);fflush(stdout)
/*variables*/
typedef struct {
	float real ;
	float Imaginary;
}Scomplex;
/*prototypes*/
Scomplex Addcomplex(Scomplex no1, Scomplex no2);
/*main*/
int main(void) {
	Scomplex no1,no2,result;
printf("no1 (REAL) : ");FLUSH;scanf("%f",&no1.real);
printf("no1 (IMGN) : ");FLUSH;scanf("%f",&no1.Imaginary);
printf("no2 (REAL) : ");FLUSH;scanf("%f",&no2.real);
printf("no2 (IMGN) : ");FLUSH;scanf("%f",&no2.Imaginary);
result = Addcomplex(no1,no2);
printf("Displaying adding result ............. \n");
printf("Sum is %f + %f i",result.real,result.Imaginary);
	return(0);
}
Scomplex Addcomplex(Scomplex no1, Scomplex no2)
{
	Scomplex result ;
	result.real = no1.real+no2.real;
	result.Imaginary = no1.Imaginary+no2.Imaginary;
	return result ;
}
