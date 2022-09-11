/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
int main(void) {
	char c;
	loop:
	printf("Enter a char to check if it vowel or consonant: \n");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);
	if(c =='a'|| c=='e' || c=='i'|| c=='o'|| c=='u' || c =='A'|| c=='E' || c=='I'|| c=='O'|| c=='U')
	printf("%c is Vowel\n",c);
	else
	printf("%c is Consonant\n",c);
	goto loop;

	return(0);
}

