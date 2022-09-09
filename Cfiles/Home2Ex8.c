/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
int main(void) {
	float a,b;
	char op;
	loop:
	a=0.0;b=0.0;
	printf("Enter an operator (+,-,*,/) : \n");
	fflush(stdin);fflush(stdout);
	scanf("%c",&op);
	printf("Enter two numbers : \n");
	fflush(stdin);fflush(stdout);
	scanf("%f%f",&a,&b);
	if(op=='/' && b==0.0)
		printf("ERROR : its not possible dividing by zero!\n");
	else
	{
		switch(op)
		{
		case '+':
			printf("%f %c %f = %f\n",a,op,b,a+b);
			break;
		case '-':
			printf("%f %c %f = %f\n",a,op,b,a-b);
			break;
		case '*':
			printf("%f %c %f = %f\n",a,op,b,a*b);
			break;
		case '/':
			printf("%f %c %f = %f\n",a,op,b,a/b);
			break;
		default:
			printf("%c is not acceptable operator !\n" );
			break;
		}
	}
	goto loop;
	return(0);
}

