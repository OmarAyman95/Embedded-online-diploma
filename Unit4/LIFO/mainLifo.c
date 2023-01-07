#include "lifo.h"
#include "stdio.h"

int main(void)
{
	ELEMENT_TYPE i, temp;
	LIFO_Buf_t lifo_uart;
	if(LIFO_init(&lifo_uart,buf1,WIDTH)!=LIFO_noERROR)
		printf("LIFO init Error !");
	else
	{
		for(i=0;i<18;i++)
		{
			if(LIFO_push(&lifo_uart,i)==LIFO_noERROR)
				printf("pushing [%d] to stack buf1 is done !\n",i);
			else
				printf("pushing Error !\n",i);
		}
		for(i=0;i<11;i++)
		{
			if(LIFO_pop(&lifo_uart,&temp)==LIFO_noERROR)
				printf("popping [%d] from stack buf1 is done !\n",temp );
			else
				printf("popping Error !\n",i);
		}
	}

	return(0);
}