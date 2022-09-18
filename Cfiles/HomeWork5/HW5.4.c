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
Sstudent students[10],*PTR;
int i ;
for(i=0;i<10;i++)
{
printf("**************************student %d*************************\n");
printf("Enter Name : ");FLUSH;scanf("%s",students[i].name);
printf("Enter roll_Number : ");FLUSH;scanf("%d",&students[i].roll_number);
printf("Enter marks : ");FLUSH;scanf("%f",&students[i].marks);
printf("\n");
}
printf("************************Displaying Information*********************\n");
for(i=0;i<10;i++)
{
PTR = &students[i];
printf("student %d:....name : %s....roll Number: %d....marks: %f\n",i+1,PTR->name,PTR->roll_number,PTR->marks);
}

	return(0);
}

