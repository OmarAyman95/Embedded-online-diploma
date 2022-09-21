/*
 * main.c
 *
 *  Created on: Sep 19, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"string.h"
#define FLUSH fflush(stdin);fflush(stdout)

int main(void){
	char ch = 'A',i=0;
	char *ptrToch=&ch;
	while(i<=25)printf("%c ",(char)(*(ptrToch)+i++));

	return(0);
}
