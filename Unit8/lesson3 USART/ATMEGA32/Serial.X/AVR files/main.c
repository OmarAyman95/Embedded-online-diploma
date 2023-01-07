/*
 * File:   main.c
 * Author: OMAR
 *
 * Created on November 16, 2022, 4:26 PM
 */

#include <avr/io.h>
#include"ATMGA32MCU.h"
#include"GPIO_MEGA32.h"
#include "delayT0.h"
#include"EXTI.h"
#include"usartATmega.h"
#include "Timer0.h"

// ATmega32 Configuration Bit Settings
// 'C' source line config statements
FUSES = {
	.low = 0xFF, // LOW {SUT_CKSEL=EXTHIFXTALRES_16KCK_64MS, BODEN=CLEAR, BODLEVEL=2V7}
	.high = 0x99, // HIGH {BOOTRST=CLEAR, BOOTSZ=2048W_3800, EESAVE=CLEAR, CKOPT=CLEAR, SPIEN=SET, JTAGEN=SET, OCDEN=CLEAR}
};
LOCKBITS = 0xFF; // {LB=NO_LOCK, BLB0=NO_LOCK, BLB1=NO_LOCK}

/*global char to receive date which is coming to USART module */
char gReceiver;
/*$$$$$Password Check variables$$$$$$$$$$*/
static const char gfirst_message[]="Password::\r\n\0";
static const char gnameSaved[20]="Omar Mohammed";
enum NUMPassword_Status{WRONG_PASSWORD,WAIT_PASSWORD,SUCCESS_PASSWORD};
char gnameEntered[20];

void USART_ISR(void)
{
/*This flag bit is set when the entire frame in the transmit 
 * Shift Register has been shifted out and there are no new
data currently present in the transmit buffer (UDR). */
    if(USART_REGs->UCSRA_R.TXCbit==1 )
    {
       USART_TRANSMITTER_COMPLETE_INTERRUPT_DISABLE();
       /*put your ISR here*/
       PORT_Toggle_pin(GPIOC,_PIN2);
    }
/*The UDRE Flag indicates if the transmit 
 * buffer (UDR) is ready to receive new data. 
 * If UDRE is one, the buffer is
empty, and therefore ready to be written
        *** NOTE : we add "USART_REGs->UCSRA_R.RXCbit==0" 
        * because there is unpredictable interrupt will occur
        * when receiver receives a char,
        * at this time we have already read the buffer,
        * RXCbit will clear by hardware, 
        * so the buffer will be empty,therfore 
        * this will generate unwanted interrupt, 
        * so what we tell the code here,
        * if this situation happens, do NOT enter here               
 */   
    else if(USART_REGs->UCSRA_R.UDREbit==1 && USART_REGs->UCSRA_R.RXCbit==0)
    {
       USART_BUFFER_CLEAR_INTERRUPT_DISABLE();
       /*put your ISR here*/
       PORT_Toggle_pin(GPIOC,_PIN4);     
    }
/*This flag bit is set when there are unread data in the receive 
 * buffer and cleared when the receive buffer is empty
(that is, does not contain any unread data). */
    else if(USART_REGs->UCSRA_R.RXCbit==1)
    {
        /*put your ISR here*/      
        PORT_Toggle_pin(GPIOC,_PIN1); 
        gReceiver = UDR_REG;  
        /*$$$$$Password Check$$$$$$$$$$*/
        static uint8_t counter =0;
        static enum NUMPassword_Status Passwoord_Status=WAIT_PASSWORD ;
        if(Passwoord_Status != SUCCESS_PASSWORD)
        {  
            gnameEntered[counter] = gReceiver; 
            if(gnameEntered[counter]!=gnameSaved[counter] || counter>12)
            {
                char *textX = "\r\nWRONG Password\r\n\0";
                uint8_t i=0; while(textX[i]!='\0'){USART_Send_Char(*(textX+i));i++;}         
                counter =0;
                Passwoord_Status=WRONG_PASSWORD;
                i=0; while(gfirst_message[i]!='\0'){USART_Send_Char(*(gfirst_message+i));i++;}
            }
            else if(counter==12)
            {
                char *textY = "\r\n<<<<<<<<<<<<<<<<<<<Hello Omar>>>>>>>>>>>>>>>>>\r\n\0";
                uint8_t j=0; while(textY[j]!='\0'){USART_Send_Char(*(textY+j));j++;}
                Passwoord_Status=SUCCESS_PASSWORD;
            }
            counter++;
            if(Passwoord_Status==WRONG_PASSWORD){ counter=0;Passwoord_Status=WAIT_PASSWORD;}
        }
    }
    else{}
}

int main(void) {
    USART_config_t USART1 = 
    {
        USART_TX_RX,
        USART_9600_BAUDRATE,
        USART_8BITS_DATA_FORMAT,USART_NO_PARITY,USART_1BIT_STOP,
        USART_ISR_EN,&USART_ISR
    };
    
    PORT_init(GPIOC,OUTPUT_MODE,ALL_PINS);
    USART_init(&USART1);    
    
    uint16_t  i=0; 
    while(gfirst_message[i]!='\0'){USART_Send_Char(*(gfirst_message+i));i++;}
    /*LOOP FOREVER*/
    while(1)
    {   
       asm("SLEEP");
    }
    return 0;
}