/*
 * main.c
 *
 *  Created on: Sep 15, 2022
 *      Author: OMAR_AYMAN
 */

/*libraries*/
#include"stdio.h"
#include"stdint.h"
#include <stdlib.h>
/*macros*/
#define FLUSH fflush(stdin);fflush(stdout)
/*variables*/
typedef struct SstudentInfo{
	char name[20];
	int roll_number ;
	float marks;
}Sstudent;

/*prototypes*/

/*main*/

int main(void) {
Sstudent student1,*PTR;
printf("Enter Name : ");FLUSH;scanf("%s",student1.name);
printf("Enter roll_Number : ");FLUSH;scanf("%d",&student1.roll_number);
printf("Enter marks : ");FLUSH;scanf("%f",&student1.marks);

PTR = &student1;
printf("Displaying Information ............. \n");
printf("name : %s\nroll Number: %d\nmarks: %f",PTR->name,PTR->roll_number,PTR->marks);


	return(0);
}

