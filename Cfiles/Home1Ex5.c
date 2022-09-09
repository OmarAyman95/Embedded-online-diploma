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
	char c ;
	loop:
	printf("Enter a char : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);
	printf("ASCII value of [%c] is {%d}\n ",c,c);
	goto loop;
}
void swap(float *a,float *b){
	float temp = *a;
	*a = *b;
	*b = temp;
}
