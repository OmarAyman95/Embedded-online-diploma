/*
 * main.c
 *
 *  Created on: Sep 12, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
#include"string.h"
#define FLUSH fflush(stdin);fflush(stdout)
int main(void) {
	int i,arr_length=0 ;
	char txt[100];
	loop:
	arr_length=0;
	printf("enter a string :");
	FLUSH;
	gets(txt);
	printf("text is %s\n",txt);
	for(i=0;txt[i]!='\0';i++){
		arr_length++;
	}
	printf("calculated length is : %d\n",arr_length);
	printf("from library length is : %d\n\n",strlen(txt));
	goto loop;
	return(0);

}
