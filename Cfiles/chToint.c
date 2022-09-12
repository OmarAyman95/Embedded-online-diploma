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
int charToint(char ch);
int getNumberint(char *ch);
int main(void) {
	char no1[10]; char no2[10];
	loop:
	printf("Enter the 1st number : ");FLUSH;scanf("%s",no1);
	printf("Enter the 2nd number : ");FLUSH;scanf("%s",no2);
	printf("%s + %s >>> %d\n",no1,no2,(getNumberint(no1)+getNumberint(no2)));
	goto loop;
	return(0);
}
int charToint(char ch){
	switch(ch){
	case '0':return(0);break;
	case '1':return(1);break;
	case '2':return(2);break;
	case '3':return(3);break;
	case '4':return(4);break;
	case '5':return(5);break;
	case '6':return(6);break;
	case '7':return(7);break;
	case '8':return(8);break;
	case '9':return(9);break;
	case '-':return(10);break;
	default :return(-1);break;
	}
}
int getNumberint(char *ch){
	int i,digit10 = 1,chToint = 0 ;
	for(i = 0;ch[i]!='\0';i++){}/* calculate size of number*/
	if(charToint(ch[0])==10)
	{
		for(i-=1;i>0;i--)
		{
			if(charToint(ch[i])==-1 || charToint(ch[i])==10){printf("E R R O R !\n");chToint=0;break;}
			chToint += charToint(ch[i])*digit10;
			digit10*=10;
		}

		chToint*=-1;
	}
	else
	{
		for(i-=1;i>=0;i--)
		{
			if(charToint(ch[i])==-1 || charToint(ch[i])==10){printf("E R R O R !\n");chToint=0;break;}
			chToint += charToint(ch[i])*digit10;
			digit10*=10;
		}
	}

	return (chToint);
}
