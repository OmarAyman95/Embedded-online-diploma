/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Omar Ayman
 * @brief          : Main program body
*/


#include "lcd16.h"
#include "keyPad.h"
#include "GPIOSTM32.h"
#include "EXTI.h"


void delay_ms(int x)
{
	int i,j;
	for(i=0;i<x;i++){
	for(j=0;j<530;j++){}
	}
}


void IRQ14(void)
{
	for(int i = 0;i<=6;i++)
	{
	GPIO_Toggle_Pin(GPIOB,GPIO_PIN14);
	delay_ms(100);
	}
	GPIO_Reset_Pin_Atomic(GPIOB,GPIO_PIN14);
}
void IRQx(void)
{

}

void IRQ15(void)
{
	for(int i = 0;i<=6;i++)
	{
	GPIO_Toggle_Pin(GPIOB,GPIO_PIN15);
	delay_ms(100);
	}
	GPIO_Reset_Pin_Atomic(GPIOB,GPIO_PIN15);
}
void clock_init(void)
{
	RCC->APB2ENR |=(IOPAEN | IOPBEN | AFIOEN |IOPCEN |IOPDEN);
}

void port_init(void)
{

    GPIO_Init_All_Output(GPIOB,OUTPUT_PUSH_PULL_2MHZ_ALL);
    GPIO_Init_Output_Pin(GPIOC,GPIO_PIN13,OUTPUT_PUSH_PULL_2MHZ);
    GPIO_Init_Output_Pin(GPIOC,GPIO_PIN14,OUTPUT_PUSH_PULL_2MHZ);
	GPIO_Init_Output_Pin(GPIOC,GPIO_PIN15,OUTPUT_PUSH_PULL_2MHZ);



}
char text[]={"STM32F103C6 SOC"};
int main(void)
{

	clock_init();
	delay_ms(100);
  	port_init();


	lcd_INIT(_40DOTS,_2LINE,_8BIT);
    lcd_Send_Command(LCD_CURS_OFF_COMMAND | LCD_BLINK_OFF_COMMAND | LCD_DATA_ON_COMMAND);
	lcd_WRITE_TEXT(text);


	lcd_Send_Command(LCD_CURSOR_POS_2ND_LINE_COMMAND);
	lcd_WRITE_TEXT("External Line");


	External_Interrupt_Reset();

	Software_Interrupt_Trigger(GPIO_PIN3,IRQ15);

  	External_Interrupt_Init(GPIOA,GPIO_PIN0,FALLING_EDGE,IRQ14);
    External_Interrupt_Init(GPIOA,GPIO_PIN1,FALLING_EDGE,IRQx);
    External_Interrupt_Init(GPIOA,GPIO_PIN2,RISING_EDGE,IRQx);
  	External_Interrupt_Init(GPIOA,GPIO_PIN3,FALLING_EDGE,IRQx);
  	External_Interrupt_Init(GPIOA,GPIO_PIN4,RISING_EDGE,IRQx);
  	External_Interrupt_Init(GPIOA,GPIO_PIN5,RISING_EDGE,IRQx);
  	External_Interrupt_Init(GPIOA,GPIO_PIN6,FALLING_EDGE,IRQx);
  	External_Interrupt_Init(GPIOA,GPIO_PIN7,FALLING_EDGE,IRQx);


  	External_Interrupt_Init(GPIOB,GPIO_PIN8,RISING_EDGE,IRQx);
  	External_Interrupt_Init(GPIOB,GPIO_PIN9,RISING_EDGE,IRQx);
  	External_Interrupt_Init(GPIOB,GPIO_PIN10,FALLING_EDGE,IRQx);
  	External_Interrupt_Init(GPIOB,GPIO_PIN11,FALLING_EDGE,IRQx);
  	/*External_Interrupt_Init(GPIOB,GPIO_PIN12,RISING_EDGE);
  	External_Interrupt_Init(GPIOB,GPIO_PIN13,RISING_EDGE);
  	External_Interrupt_Init(GPIOB,GPIO_PIN14,FALLING_EDGE);
  	External_Interrupt_Init(GPIOB,GPIO_PIN15,FALLING_EDGE);*/


  	External_Interrupt_Init(GPIOD,GPIO_PIN0,FALLING_EDGE,IRQ14);
  	External_Interrupt_Init(GPIOD,GPIO_PIN1,BOTH_EDGES,IRQx);


    /* Loop forever */

	for(;;)
	{



	switch(External_Interrupt_Line)
	{
	case 0:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("0 ");break;
	case 1:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("1 ");break;
	case 2:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("2 ");break;
	case 3:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("3 ");break;
	case 4:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("4 ");break;
	case 5:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("5 ");break;
	case 6:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("6 ");break;
	case 7:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("7 ");break;
	case 8:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("8 ");break;
	case 9:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("9 ");break;
	case 10:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("10");break;
	case 11:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("11");break;
	case 12:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("12");break;
	case 13:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("13");break;
	case 14:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("14");break;
	case 15:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("15");break;
	default:lcd_SET_CURSOR_POSITION(2,14);External_Interrupt_Line = -1 ; lcd_WRITE_TEXT("--");break;
	}
	delay_ms(200);

	}

	return 0;
}

