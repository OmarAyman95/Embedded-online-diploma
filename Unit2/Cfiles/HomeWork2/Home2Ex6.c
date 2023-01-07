/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
int main(void) {
	int n,summation;
	loop:
	summation=0;
	printf("Enter a number to check to calculate summation: \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	if(n<1)
		printf("%d is not a natural number \n",n);
	else
	{
		for(int i =1;i<=n;i++)
		summation+=i;
		printf("summation from 1 to %d = [%d]\n",n,summation);
	}
	goto loop;

	return(0);
}

