/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Omar Ayman
 * @brief          : Main program body
*/


#include "lcd16.h"
#include "keyPad.h"
#include "GPIOSTM32.h"


void delay_ms(int x)
{
	int i,j;
	for(i=0;i<x;i++){
	for(j=0;j<530;j++){}
	}
}

void clock_init(void)
{
	RCC->APB2ENR |=(IOPAEN | IOPBEN | AFIOEN |IOPCEN );
}

void port_init(void)
{

    GPIO_Init_All_Output(GPIOB,OUTPUT_PUSH_PULL_2MHZ_ALL);
    GPIO_Init_Output_Pin(GPIOC,GPIO_PIN13,OUTPUT_PUSH_PULL_2MHZ);
    GPIO_Init_Output_Pin(GPIOC,GPIO_PIN14,OUTPUT_PUSH_PULL_2MHZ);
	GPIO_Init_Output_Pin(GPIOC,GPIO_PIN15,OUTPUT_PUSH_PULL_2MHZ);


	GPIO_Init_Input_Pin(GPIOA,GPIO_PIN14,INPUT_PULL_UP_DOWN,DOWN);
	GPIO_Init_Input_Pin(GPIOA,GPIO_PIN15,INPUT_PULL_UP_DOWN,DOWN);

    GPIO_Init_Input_Pin(GPIOA,GPIO_PIN0,INPUT_PULL_UP_DOWN,DOWN);
    GPIO_Init_Input_Pin(GPIOA,GPIO_PIN1,INPUT_PULL_UP_DOWN,DOWN);
    GPIO_Init_Input_Pin(GPIOA,GPIO_PIN2,INPUT_PULL_UP_DOWN,DOWN);
    GPIO_Init_Input_Pin(GPIOA,GPIO_PIN3,INPUT_PULL_UP_DOWN,DOWN);

    GPIO_Init_Output_Pin(GPIOA,GPIO_PIN4,OUTPUT_PUSH_PULL_2MHZ);
    GPIO_Init_Output_Pin(GPIOA,GPIO_PIN5,OUTPUT_PUSH_PULL_2MHZ);
    GPIO_Init_Output_Pin(GPIOA,GPIO_PIN6,OUTPUT_PUSH_PULL_2MHZ);
    GPIO_Init_Output_Pin(GPIOA,GPIO_PIN7,OUTPUT_PUSH_PULL_2MHZ);

}
char text[]={"STM32F103C6 SOC"};
int main(void)
{

	clock_init();
	delay_ms(100);
  	port_init();

  	lcd_INIT(_40DOTS,_2LINE,_8BIT);
    lcd_Send_Command(LCD_CURS_OFF_COMMAND | LCD_BLINK_ON_COMMAND | LCD_DATA_ON_COMMAND);
	lcd_WRITE_TEXT(text);

	lcd_Send_Command(LCD_CURSOR_POS_2ND_LINE_COMMAND);
    /* Loop forever */
    char keyPressed;
	for(;;)
	{
		keyPressed = KeyPad_Scanning(GPIOA);

		if(keyPressed=='c')
		{
			lcd_Send_Command(LCD_SHIFT_CURS_R_COMMAND);
		}
		else if(keyPressed!=(0))
		{
			lcd_SET_CURSOR_POSITION(2,5);
			lcd_WRITE_CHAR(keyPressed);
		}

		else if(GPIO_Read_Pin(GPIOA,14))
		{
			while(GPIO_Read_Pin(GPIOA,14));
			GPIO_Toggle_Pin(GPIOB,13);
		}



	}

	return 0;
}

