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
typedef struct{
	char name[20];
	int roll_number ;
	float marks;
}Sstudent;

typedef struct{
	int feet;
	float inch;
}Sdistance;
/*prototypes*/
Sdistance CalcDist(Sdistance dist1,Sdistance dist2);
/*main*/

int main(void) {
	Sdistance dist1,dist2,distSum;
	printf("dist1 in feet : ");FLUSH;scanf("%d",&dist1.feet);
	printf("dist1 in inch : ");FLUSH;scanf("%f",&dist1.inch);
	printf("dist2 in feet : ");FLUSH;scanf("%d",&dist2.feet);
	printf("dist2 in inch : ");FLUSH;scanf("%f",&dist2.inch);
	distSum=CalcDist(dist1,dist2);
	printf("sum of the distances is : %d feet , %f inches",distSum.feet,distSum.inch);
	return(0);
}
Sdistance CalcDist(Sdistance dist1,Sdistance dist2)
{
	Sdistance distSum;

	int temp =(int)(dist1.inch+dist2.inch);
	temp=temp/12;
	distSum.feet = dist1.feet+dist2.feet+temp;

	if(temp)distSum.inch=((dist1.inch+dist2.inch)-(temp*12));
	else distSum.inch=dist1.inch+dist2.inch;

	return distSum;
}
