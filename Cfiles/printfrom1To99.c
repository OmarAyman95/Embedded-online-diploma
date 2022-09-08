/*
 * main.c
 *
 *  Created on: Sep 6, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
int main(void) {
     unsigned int summation = 0;
	for(unsigned int i = 1;i<=99;i++)
		summation+=i;
	printf("summation is = %d",summation);
	return(0);
}
