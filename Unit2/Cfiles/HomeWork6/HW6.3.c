/*
 * main.c
 *
 *  Created on: Sep 19, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"string.h"
#define FLUSH fflush(stdin);fflush(stdout)
char Arr[100];
char *ptrToArr = Arr;
int i = 0 ,j;
int main(void){
	printf("Input a string to reverse it (max 100) : ");
	FLUSH;
	gets(Arr);
	printf("the entered string : %s\n",Arr);
	printf("the string in reverse order is:");
	for(i=0;Arr[i]!='\0';i++){}
	ptrToArr=(char*)(Arr+i);
	for(j=0;j<=i;j++){printf("%c",*(ptrToArr-j));}
	return(0);
}
