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

int __pow(int i, int n);
/*main*/

int main(void) {


	printf("5^3  = %d\n",__pow(5,3));
	printf("2^10 = %d\n",__pow(2,10));
	printf("2^16 = %d\n",__pow(2,16));
	printf("10^3 = %d\n",__pow(10,3));
	return(0);
}


int __pow(int i, int n){
	if(n==1){return i;}
	else{return(__pow(i,n-1)*i);}
}
