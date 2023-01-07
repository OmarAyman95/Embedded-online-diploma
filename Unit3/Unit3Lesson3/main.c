#include"bsp.h"
int main(void)
{
	/* initialization */
	RCC_APB2ENR |=IOPAEN;//Enable clock of GPIOA
	GPIOA_CRH&=~(0xffffffffU);
	GPIOA_CRH |=(0x22222222U);//General purpose output Open-drain
	GPIOA_CRL&=~(0xffffffffU);
	GPIOA_CRL |=(0x08000000U);//A6 as a digital input
	/* Loop forever */
	 int count,right=0,left=1;GPIOA_ODR&=~0xff00;//clear GPIO(bit15~bit08)
	for(;;)
	{
	count = RIGHT_LIMIT;
		while(count !=0)
		{
			for(;count<=LEFT_LIMIT && GPIOA_IDR_REG->IDR.IDR06==0 && left==1 && right==0;count<<=1)
			{
				GPIOA_ODR=count;
		       if(count==LEFT_LIMIT){left=0;right=1;count>>=1;}
			   else if(count!=LEFT_LIMIT){WAIT(50000);}
			}
		    for(;count>=RIGHT_LIMIT && GPIOA_IDR_REG->IDR.IDR06==0 && left==0 &&right==1;count>>=1)
			{
				
				GPIOA_ODR=count;
                if(count==RIGHT_LIMIT){left=1;right=0;count=0;}
				else if(count!=RIGHT_LIMIT){WAIT(50000);}
			}
		}
		
	}
	return 0;
}
