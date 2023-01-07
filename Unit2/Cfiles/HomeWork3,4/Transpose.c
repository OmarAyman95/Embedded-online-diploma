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
	int M1[20][20],M1_transpose[20][20];
	int i,j,rows,columns;

	printf("Enter rows and columns :");
	FLUSH;
	scanf("%d %d",&rows,&columns);

	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			printf("M1[%d][%d] : ",i,j);
			FLUSH;
			scanf("%d",&M1[i][j]);
		}
	}
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++)
			M1_transpose[j][i] = M1[i][j];
	}

	printf("M1 : \n");

	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			printf("%d  ",M1[i][j]);
		}
		printf("\n");
	}
	printf("Transpose_M1 : \n");
	for(i=0;i<columns;i++){
		for(j=0;j<rows;j++){
			printf("%d  ",M1_transpose[i][j]);
		}
		printf("\n");
	}



	return(0);

}
