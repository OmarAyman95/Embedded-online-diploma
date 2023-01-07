#include <stdint.h>
void Pin_init(void);
void delay(uint32_t iter);

#define WAIT(x) delay(x*50000)

#define LED_GREEN  (1U << 3)
#define LED_RED    (1U << 1)
#define PORTF_CLK  (1U << 5)
#define GPIOF_BASE 0x40025000
#define RCC_BASE   0x400FE000

#define RCGCGPIOF  (*((volatile uint32_t*)(RCC_BASE+0x608U)))
#define GPIOF_DATA (*((volatile uint32_t*)(GPIOF_BASE+0x3FCU)))
#define GPIOF_DIR  (*((volatile uint32_t*)(GPIOF_BASE+0x400U)))
#define GPIOF_DEN  (*((volatile uint32_t*)(GPIOF_BASE+0x51CU)))

int REDon = 0x02;


int main(void) {
	Pin_init(); 

	while(1)
		{
		    GPIOF_DATA |= REDon;
			WAIT(1);
            GPIOF_DATA &= ~REDon;
            WAIT(8);       

         }
    //return 0;
}

void delay(uint32_t iter) {
    volatile uint32_t  counter;
    counter = 0;
    while (counter < iter) 
    {  
        ++counter;
    }
}


void Pin_init(void){
  	RCGCGPIOF |= PORTF_CLK; /* enable Run mode for GPIOF */
    WAIT(1);
	GPIOF_DIR |= REDon;
    GPIOF_DEN |= REDon;
}



