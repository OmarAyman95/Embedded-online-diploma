/*
 * main.c
 *
 *  Created on: Sep 19, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#define FLUSH fflush(stdin);fflush(stdout)


int Arr[15];
int *ptrToArr = Arr;
int i = 0 ,n;

int main(void){
	printf("Input the number of elements to store in the array (max 15) : ");
	FLUSH;
	scanf("%d",&n);
	printf("Input 5 number of elements in the array :\n");
	for(i=0;i<n;i++)
	{
		printf("element - %d : ",i+1);FLUSH;scanf("%d",(ptrToArr+i));
	}
	printf("The elements of array in reverse order are :\n");
	for(i-=1;i>=0;i--)
	{
		printf("element - %d : %d\n",i+1,*(ptrToArr+i));
	}
	return(0);
}
