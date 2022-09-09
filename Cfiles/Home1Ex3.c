/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
int main(void) {
	int no1,no2 ;
	printf("Enter two integers :\n ");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&no1,&no2);
	printf("%d + %d = [%d]",no1,no2,no1+no2);
	return(0);
}
