/*
 * main.c
 *
 *  Created on: Sep 6, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
#include"stdint.h"
int main(void) {
	for(int j = 0;j<=9;j++){
		for(int i=j;i<=9;i++)
			printf("%d  ",i);
		printf("\n");
	}

}
