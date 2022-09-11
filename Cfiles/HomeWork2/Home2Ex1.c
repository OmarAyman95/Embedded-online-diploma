/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"

int main(void) {
	int no1;
	loop:
	printf("Enter a number to check : \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&no1);
	if(no1%2!=0)printf("%d is ODD\n",no1);
	else printf("%d is EVEN\n",no1);
	goto loop;

	return(0);
}

