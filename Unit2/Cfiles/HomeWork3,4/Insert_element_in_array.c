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
	int arr[20];
	volatile int n,i;
	int New_e,New_e_location;

	printf("Enter no of elements :");
	FLUSH;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		arr[i]=i+1;
		printf("%d  ",arr[i]);
	}
	printf("\n");
	printf("Enter the element to be inserted :");
	FLUSH;
	scanf("%d",&New_e);
	printf("Enter the location :");
	FLUSH;
	scanf("%d",&New_e_location);
	for(i=0;i<=n;i++){
		if(i!=n)arr[i]=i+1;
		else arr[i]=New_e;
	}
	/*R_arrange*/
	for(i=0;i<=n;i++){
		if(i<New_e_location)arr[i]=i+1;
		else if (i==New_e_location){arr[i]=New_e;}
		else arr[i]=i;
		printf("%d  ",arr[i]);
	}
	return(0);

}
