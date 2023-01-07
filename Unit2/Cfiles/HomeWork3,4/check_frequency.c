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
	int i,repeated=0 ;
	char txt[100],ch;
	loop:
	repeated=0;
	printf("enter a string :");
	FLUSH;
	gets(txt);
	printf("text is %s\n",txt);

	printf("enter a char to find frequency :");
	FLUSH;
	scanf("%c",&ch);

	for(i=0;txt[i]!='\0';i++){
		if(txt[i]==ch)repeated++;
	}
	printf("%c is repeated %d times \n\n",ch,repeated);
	goto loop;
	return(0);

}
