/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
int main(void) {
	int a;
	loop:
	printf("Enter the number to check if it is positive or negative: \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&a);
	if(a>0)
	printf("%d is positive \n",a);
	else if(a<0)
	printf("%d is negative \n",a);
	else
	printf("%d is zero \n",a);
	goto loop;

	return(0);
}

