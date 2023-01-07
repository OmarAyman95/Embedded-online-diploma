/*
 * File:   main.c
 * Author: OMAR
 *
 * Created on November 16, 2022, 4:26 PM
 */

#define F_CPU 1000000UL
#include"avr/io.h"
#include"util/delay.h"
#include <avr/interrupt.h>

ISR(INT0_vect)
{
      PORTB ^=(1U<<0);
      _delay_ms(1000);
}

ISR(INT1_vect)
{
      PORTB ^=(1U<<1);
      _delay_ms(1000);
      
}

ISR(INT2_vect)
{
      PORTB ^=(1U<<3);
      _delay_ms(1000);
}
void interrupt_init(void)
{
    SREG |= (1U<<7);
    GICR |= ((1U<<5) | (1U<<6) | (1U<<7));
    MCUCR |= ((1U<<0) | (1U<<2) | (1U<<3));
    MCUCR &= ~(1U<<1);
    MCUCSR &= ~(1U<<6);
    PORTB &= ~(1U<<0 | 1U<<1 | 1U<<3);
}


int main(void) {
    DDRB |= (1U<<0 | 1U<<1 | 1U<<3); //B0,1,3 as output
    DDRB &= ~(1U<<2);//B2 as input 
    DDRD &= ~(1U<<2);//D2 as input
    DDRD &= ~(1U<<3);//D3 as input
    interrupt_init();
    while(1)
    {
        PORTB &= ~(1U<<0 | 1U<<1 | 1U<<3);
//      while(!(PIND & (1U<<3)))
//      {
//      PORTB ^=(1U<<0);
//      _delay_ms(500);
//      }
    }
    return 0;
}
