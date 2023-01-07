/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
int main(void) {
	char c;
	loop:
	printf("Enter a char to check if it is alphabet or not: \n");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);
	if((c>=65 && c<=90)||(c>=97 && c<=122))
		printf("%c is an alphabet \n",c);
	else
		printf("%c is not an alphabet \n",c);
	goto loop;

	return(0);
}

