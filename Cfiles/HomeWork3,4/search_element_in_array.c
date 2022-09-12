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
	int arr[20];
	volatile int n,i;
	int searched_e;
loop:
	printf("Enter no of elements :");
	FLUSH;
	scanf("%d",&n);

	for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
	}
	printf("\n");
	printf("Enter the element to be searched :");
	FLUSH;
	scanf("%d",&searched_e);

	for(i=0;i<n;i++){
		if(arr[i]==searched_e)break;
		else continue;
	}
	printf("number found at location : %d\n\n",i+1);
	goto loop;
	return(0);

}
