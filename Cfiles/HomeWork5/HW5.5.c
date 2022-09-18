/*
 * main.c
 *
 *  Created on: Sep 18, 2022
 *      Author: OMAR_AYMAN
 */

/*libraries*/
#include"stdio.h"
#include"stdint.h"
#include <stdlib.h>
/*macros*/
#define FLUSH fflush(stdin);fflush(stdout)
#define area(x) 3.141592654*x*x
/*variables*/

/*prototypes*/

/*main*/

int main(void) {
int r ;
loop:
printf("raduis = ");FLUSH;scanf("%d",&r);printf("area of %d radius is %lf\n",r,area(r));
goto loop;
	return(0);
}

