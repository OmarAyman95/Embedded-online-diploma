/*
 * File:   main.c
 * Author: OMAR AYMAN
 *
 * Created on January 5, 2023, 21:34 PM
 */

#include "GPIO_MEGA32.h"
#include "delayT0.h"
#include <avr/io.h>
#include "Timer0.h"
// ATmega32 Configuration Bit Settings

// 'C' source line config statements

FUSES = {
	.low = 0xE4, // LOW {SUT_CKSEL=INTRCOSC_8MHZ_6CK_64MS, BODEN=CLEAR, BODLEVEL=2V7}
	.high = 0x99, // HIGH {BOOTRST=CLEAR, BOOTSZ=2048W_3800, EESAVE=CLEAR, CKOPT=CLEAR, SPIEN=SET, JTAGEN=SET, OCDEN=CLEAR}
};

LOCKBITS = 0xFF; // {LB=NO_LOCK, BLB0=NO_LOCK, BLB1=NO_LOCK}

int main(void) {
    PORT_init(GPIOB,OUTPUT_MODE,_PIN7);
    PORT_init(GPIOB,OUTPUT_MODE,_PIN6);
    Timer0_config TMR0_config;
    
    TMR0_config.Timer0_Mode = TMR0_FAST_PWM_MODE;
    TMR0_config.Timer0_COM_Mode = TMR0_OCR_PIN_SET_AT_BOTTOM;
    TMR0_config.Timer0_Compare_Interrupt = TMR0_COMPARE_INTERRUPT_DISABLE;
    TMR0_config.Timer0_Interrupt = TMR0_INTERRUPT_ENABLE;       
    TMR0_config.Timer0_Clock_SRC = TMR0_INTERNAL_CLK_PS_8_SRC;

    TMR0_init(&TMR0_config);   
    TMR0_FAST_PWM_MODE_Init(1200,25);
    //TMR0_CTC_MODE_Init(2100);
    /*LOOP FOREVER*/
    while(1)
    {    
    }
    return 0;
}


