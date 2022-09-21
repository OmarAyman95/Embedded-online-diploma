/*
 * main.c
 *
 *  Created on: Sep 19, 2022
 *      Author: OMAR_AYMAN
 */
#include"stdio.h"
struct Semployee{
	char name[20];
	int ID ;
};

struct Semployee * ARR[5];
struct Semployee (*(*PtrToArrofPtrToStr)[5]);

int main(void){
	struct Semployee e1={"Alex",1002};
	struct Semployee *ptrToe1 = &e1;
	ARR[0]=ptrToe1;
	PtrToArrofPtrToStr=ARR;
	printf("Employee name:%s\nEmployee ID:%d\n",(**(PtrToArrofPtrToStr))->name,(**(PtrToArrofPtrToStr))->ID);
	return(0);
}
