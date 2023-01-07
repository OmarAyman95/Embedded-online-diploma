/*
 * File:   main.c
 * Author: OMAR
 *
 * Created on November 16, 2022, 4:26 PM
 */

#define F_CPU 1000000UL
#include"avr/io.h"
#include"util/delay.h"
#include "lcd16.h"
#include "keyPad.h"



void port_init(void)
{
    DDRB=0xff;
    DDRA=0xf0;
}
char text[]={"ATMEGA32 MCU"};
int main(void)
{
  	port_init();

  	lcd_INIT(_40DOTS,_2LINE,_4BIT);
    lcd_Send_Command(LCD_CURS_OFF_COMMAND | LCD_BLINK_ON_COMMAND | LCD_DATA_ON_COMMAND);
	lcd_WRITE_TEXT(text);

	lcd_Send_Command(LCD_CURSOR_POS_2ND_LINE_COMMAND);_delay_ms(500);
    lcd_Send_Command(LCD_SHIFT_DATA_R_COMMAND);_delay_ms(500);
    lcd_Send_Command(LCD_SHIFT_DATA_R_COMMAND);_delay_ms(500);
    
    lcd_Send_Command(LCD_SHIFT_DATA_L_COMMAND);_delay_ms(500);
    lcd_Send_Command(LCD_SHIFT_DATA_L_COMMAND);_delay_ms(500);
    
    /* Loop forever */
    char keyPressed;
	for(;;)
	{
		keyPressed = KeyPad_Scanning(&PORTA);

		if(keyPressed=='c')
		{
			lcd_Send_Command(LCD_SHIFT_CURS_R_COMMAND);
		}
		else if(keyPressed!=(0))
		{
			lcd_SET_CURSOR_POSITION(2,5);
			lcd_WRITE_CHAR(keyPressed);
		}
	}

	return 0;
}

