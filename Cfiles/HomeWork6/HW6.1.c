/*
 * main.c
 *
 *  Created on: Sep 19, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"string.h"
int main(void){
	int m = 29 ;
	printf("the address of m is %x\n",&m);
	printf("value of m is %d\n",m);

	int *ab=&m;
	printf("the address which pointer ab points to is  %x\n",ab);
	printf("content of ab is %d\n",*ab);

	m = 9 ;
	printf("the address which pointer ab points to is  %x\n",ab);
	printf("content of ab is %d\n",*ab);

	*ab = 7 ;
	printf("the address of m is %x\n",&m);
	printf("value of m is %d\n",m);
	return(0);
}
