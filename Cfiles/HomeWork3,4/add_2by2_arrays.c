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
	float _1stmatrix[2][2],_2ndmatrix[2][2],_sum[2][2];
	short row,col ;
	printf("Enter the element of 1st matrix :\n");
	for(row=0;row<=1;row++){
		for(col=0;col<=1;col++){
			printf("1st matrix %d,%d :",row,col);
			FLUSH;
			scanf("%f",&_1stmatrix[row][col]);
		}
	}

	printf("Enter the element of 2nd matrix :\n");
	for(row=0;row<=1;row++){
		for(col=0;col<=1;col++){
			printf("2st matrix %d,%d :",row,col);
			FLUSH;
			scanf("%f",&_2ndmatrix[row][col]);
		}
	}

		for(row=0;row<=1;row++){
			for(col=0;col<=1;col++){
				_sum[row][col]= _1stmatrix[row][col]+_2ndmatrix[row][col];
			}
		}

		printf("summation of 1st and 2nd matrices :\n");
				for(row=0;row<=1;row++){
					for(col=0;col<=1;col++){
						printf("%f         ",_sum[row][col]);
					}
					printf("\n");
				}
	return(0);

}
