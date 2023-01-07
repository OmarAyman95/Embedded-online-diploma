/*
 * main.c
 *
 *  Created on: Sep 12, 2022
 *      Author: OMAR_AYMAN
 */

/*libraries*/
#include"stdio.h"
#include"stdint.h"
#include"string.h"
/*macros*/
#define FLUSH fflush(stdin);fflush(stdout)
/*variables*/
/*prototypes*/
void reverse_text(void);
/*main*/
int main(void) {
    printf("Enter the sentence you want to reverse it then click enter : ");
    FLUSH;
    reverse_text();
	return(0);
}
void reverse_text(void){
	char ch ;
	scanf("%c",&ch);
	if(ch!='\n')
	{
		reverse_text();
		printf("%c",ch);
	}
}

