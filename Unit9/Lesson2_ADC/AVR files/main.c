/*
 * File:   main.c
 * Author: OMAR AYMAN
 *
 * Created on January 5, 2023, 21:34 PM
 */

#include "GPIO_MEGA32.h"
#include "delayT0.h"
#include "ADC.h"
#include <avr/io.h>
#include "usartATmega.h"


// ATmega32 Configuration Bit Settings

// 'C' source line config statements

FUSES = {
	.low = 0xE4, // LOW {SUT_CKSEL=INTRCOSC_8MHZ_6CK_64MS, BODEN=CLEAR, BODLEVEL=2V7}
	.high = 0x99, // HIGH {BOOTRST=CLEAR, BOOTSZ=2048W_3800, EESAVE=CLEAR, CKOPT=CLEAR, SPIEN=SET, JTAGEN=SET, OCDEN=CLEAR}
};

LOCKBITS = 0xFF; // {LB=NO_LOCK, BLB0=NO_LOCK, BLB1=NO_LOCK}

char Voltage[6];
char Decode(uint8_t number)
{
    switch(number)
    {
        case 0 : return '0';break;
        case 1 : return '1';break;
        case 2 : return '2';break;
        case 3 : return '3';break;
        case 4 : return '4';break;
        case 5 : return '5';break;
        case 6 : return '6';break;
        case 7 : return '7';break;
        case 8 : return '8';break;
        case 9 : return '9';break;
    }
    return '0';
}
char *ConvertDoubleToText(double Vin)
{
    uint8_t intPart=0x00,floatPart1=0x00,floatPart2=0x00;
    double tempDouble=0.0;
    intPart = (uint8_t)Vin;
    
    tempDouble = (double)((Vin - intPart) *10.0);
    floatPart1 = (uint8_t) tempDouble;
    
    tempDouble = (double)((tempDouble - floatPart1) *10.0);
    floatPart2 = (uint8_t) tempDouble;
    
    Voltage[0] = Decode(intPart);
    Voltage[1] = '.';
    Voltage[2] = Decode(floatPart1);
    Voltage[3] = Decode(floatPart2);
    Voltage[4] = 'V';
    return Voltage;
    
}
int main(void) {
    
    ADC_config ADCx=
    {
        ADC_CH0,
        ADC_INTERRUPT_DISABLE,
        ADC_REF_AVCC,
        ADC_FREE_RUNNING_TRIGGER,
        ADC_PRESCALER2,
        ADC_RIGHT_ADJUST
    };
    USART_config_t UARTx=
    {
        USART_TX_RX,
        USART_9600_BAUDRATE,
        USART_8BITS_DATA_FORMAT,
        USART_NO_PARITY,
        USART_1BIT_STOP,
        USART_ISR_DIS
    };
    /*LOOP FOREVER*/
    uint16_t buffer =0x0000 ;
    double Vin =0.0;
    PORT_init(GPIOA,INPUT_FLOATING_MODE,_PIN0);
    PORT_init(GPIOB,OUTPUT_MODE,ALL_PINS);
    PORT_init(GPIOC,OUTPUT_MODE,ALL_PINS);
    
    USART_init(&UARTx);
    USART_Transmit_Text("ADC Module");
    ADC_init(&ADCx);   
    
    
    while(1)
    {  
        buffer = ADC_READ(ADC_CH0);
        PORT_Write(GPIOB,(buffer & 0x00ff));
        PORT_Write(GPIOD,buffer >> 8);
        Vin = (double)(5.0 * buffer);
        Vin = (double)(Vin / 1024.0);
        USART_Transmit_Text(ConvertDoubleToText(Vin));
        USART_Transmit_Char('\r');
        USART_Transmit_Char('\n');
        delay_ms(500);
    }
    return 0;
}


