/*
 * main.c
 *
 *  Created on: Sep 15, 2022
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
int prime(int n);
/*main*/
int main(void) {
	int limit1,limit2, m ;
	loop:
	printf("Enter two limits to show u prime numbers which live between them : ");
	FLUSH;
	scanf("%d %d",&limit1,&limit2);
	printf("prime numbers which live between %d and %d is : \n ",limit1,limit2);
    for(m=limit1;m<=limit2;m++){
    if(prime(m) == 1)printf("%d  ",m);
    }
    printf("\n",m);
    goto loop;
	return(0);
}

int prime(int n){
	int prime=0,i ;
	if(n>1){
	for(i=1;i<=n;i++){
		if(n%i==0){++prime;if(prime>2)return -1;}
	}
	return 1;
	}
	else
	return -1;
}
