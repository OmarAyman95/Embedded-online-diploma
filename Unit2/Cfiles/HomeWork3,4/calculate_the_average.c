/*
 * main.c
 *
 *  Created on: Sep 11, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
#include"string.h"
#define FLUSH fflush(stdin);fflush(stdout)
int main(void) {
	float numbers [20],avg;
	int i,n;
	printf("Enter the numbers of data :");
	FLUSH;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the number : ");
		FLUSH;
		scanf("%f",numbers+i);
		avg+=*(numbers+i);
	}
	avg = (float)(avg/n);
	printf("average = %f",avg);
	return(0);

}
