#include "fifo.h"

static ELEMENT_TYPE temp=0,i;
static FIFO_BUF_t FIFO_UART;
static uint8_t UNUSED[8];

void addItems(uint32_t _start,uint32_t _end);
void getItems(uint32_t _start,uint32_t _end);
void FIFOstart(void);


int main(void)
{

		FIFOstart();

	    addItems(10,20);FIFO_Print(&FIFO_UART);
	
        getItems(1,3);FIFO_Print(&FIFO_UART);
		
		addItems(50,56);FIFO_Print(&FIFO_UART);
		
		getItems(1,12);FIFO_Print(&FIFO_UART);
		
		FIFOstart();

		addItems(100,106);FIFO_Print(&FIFO_UART);

	return(0);
}





void addItems(uint32_t _start,uint32_t _end)
{
	uint32_t i;
	for(i=_start;i<_end;i++)
	{

		printf("FIFO Add (%d):::",i);
		FIFO_status state = FIFO_Add_item(&FIFO_UART,i);
		if(state==FIFO_noERROR) 
			printf("\tAdd(%d) is done!{state : %u} \n",i,state);
		else 
			printf("\tAdd is failed! {state : %u} \n",state);
	}
}

void FIFOstart(void)
{
	if(FIFO_init(&FIFO_UART,uart_buf,WIDTH)==FIFO_noERROR) 
		printf("FIFO init is done! \n");
	else 
		printf("FIFO init is failed ! \n");
}

void getItems(uint32_t _start,uint32_t _end)
{
			for(i=_start;i<=_end;i++)
			{

			FIFO_status state = FIFO_Get_item(&FIFO_UART,&temp);
            if(state==FIFO_noERROR) 
			printf("\tGet %d is done {state : %u}  \n",temp,state);
			else
			printf("\tGet %d is failed {state : %u}  \n",temp,state);
			}
}