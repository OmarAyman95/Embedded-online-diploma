/*
 * main.c
 *
 *  Created on: Sep 10, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
#define FLUSH fflush(stdin);fflush(stdout)
int main(void) {
	int n,i,result,remainder,nPrint;
	loop:
	result = remainder = i = 1 ;
	printf("Enter the number :\n ");
	FLUSH;
	scanf("%d",&n);
    nPrint=n;
    if (n==3) printf(" %d is power of 3 (3^0) =1 \n",nPrint);
    else if(n!=3){
		while(!(result==3 && remainder==0))
	{
		result = n/3;
		remainder = n%3;
		if(remainder!=0)break;
		i++;
		n=result;
	}
	if(remainder!=0)
		printf(" %d is not power of 3 ! please try another number \n",nPrint);
	else
		printf(" %d is power of 3 (3^%d) = %d\n",nPrint,i,nPrint);
	}
     goto loop;
	return(0);
}

