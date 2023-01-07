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
unsigned int factorial(unsigned int n);
/*main*/
int main(void) {

	printf("1! = %u\n",factorial(1));
	printf("4! = %u\n",factorial(4));
	printf("5! = %u\n",factorial(5));
	printf("8! = %u\n",factorial(8));
	printf("9! = %u\n",factorial(9));
	return(0);
}
unsigned int factorial(unsigned int n){
		if(n == 1)return 1 ;
		else return(factorial(n-1)*n);
	}


