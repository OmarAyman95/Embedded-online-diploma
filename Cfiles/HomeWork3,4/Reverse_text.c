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
	int i=0,j=0,arr_length=0 ;
	char txt[100],reversed_txt[100];
	loop:
	arr_length=0;i=0;j=0;
	for(i=0;i<100;i++){txt[i]='\0';reversed_txt[i]='\0';}
	printf("enter a string :");
	FLUSH;
	gets(txt);
	printf("text is %s\n",txt);
	for(i=0;txt[i]!='\0';i++){
		arr_length++;
	}
	for(i=arr_length-1;i>=0;i--){
		reversed_txt[i]=txt[j];
		j++;
		}
	printf("reversed text is %s\n",reversed_txt);
	goto loop;
	return(0);

}
