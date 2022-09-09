/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
int main(void) {
	float no1,no2 ;
	printf("Enter two numbers to multiply :\n ");
	fflush(stdin);fflush(stdout);
	scanf("%f%f",&no1,&no2);
	printf("%f * %f = [%f]",no1,no2,no1*no2);
	return(0);
}
