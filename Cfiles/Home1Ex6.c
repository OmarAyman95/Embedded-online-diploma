/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
void swap(float *a,float *b);
int main(void) {
	float no1,no2 ;
	printf("Enter two float to swap them : \n");
	fflush(stdin);fflush(stdout);
	scanf("%f%f",&no1,&no2);
	printf(" before : \n no1 = %f\n no2 = %f\n",no1,no2);
	swap(&no1,&no2);
	printf(" after  : \n no1 = %f\n no2 = %f\n",no1,no2);
	return(0);
}
void swap(float *a,float *b){
	float temp = *a;
	*a = *b;
	*b = temp;
}
