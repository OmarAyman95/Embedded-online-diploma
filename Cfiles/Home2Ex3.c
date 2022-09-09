/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
int main(void) {
	int a,b,c;
	loop:
	printf("Enter three numbers to check the largest: \n");
	fflush(stdin);fflush(stdout);
	scanf("%d%d%d",&a,&b,&c);
	if(a>=b)
	{
		if(a>=c)printf("The largest number is a : %d\n",a);
		else    printf("The largest number is c : %d\n",c);
	}
	else
	{
		if(b>=c)printf("The largest number is b : %d\n",b);
		else    printf("The largest number is c : %d\n",c);
	}
	goto loop;

	return(0);
}

