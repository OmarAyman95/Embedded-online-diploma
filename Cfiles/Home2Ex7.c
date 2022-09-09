/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
int main(void) {
	int n,factorial;
	loop:
	factorial=1;
	printf("Enter a number to calculate factorial: \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	if(n==0 || n==1)
		printf("factorial of n is : 1 \n");
	else if (n>1)
	{
		for(int i =1;i<=n;i++)
			factorial*=i;
		printf("factorial of %d = [%d]\n",n,factorial);
	}
	else
		printf("factorial of negative numbers is undefined");
	goto loop;
	return(0);
}

