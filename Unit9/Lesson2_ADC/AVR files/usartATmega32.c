#include"usartATmega.h"


static void (*GptrToISRInApp)(void);

/******************************USART_Initialization****************************/
static uint32_t USART_Get_UBRR(uint32_t baud)
{
    //UBRR = ((F_CPU/(8*BAUD))-1)
   return ((uint32_t)(F_CPU/(8*baud))-1);   
}
void USART_init(USART_config_t *USARTobj)
{
 //disable all interrupts 
    GLOBAL_INTERRUPT_DESABLE();
    USART_TRANSMITTER_COMPLETE_INTERRUPT_DISABLE();
    USART_BUFFER_CLEAR_INTERRUPT_DISABLE();
    USART_RECEIVER_INTERRUPT_DISABLE();
// Set baud rate
  USART_REGs->UCSRA_R.U2Xbit = 1 ;//Double rate transfer <U2X = 1>   
  uint32_t UBRR_val =(uint32_t)USART_Get_UBRR(USARTobj->USART_baudRate);
  if(UBRR_val<=255)
  {
      USART_REGs->UBRRL_R = (uint8_t)UBRR_val;
  }
  else if (UBRR_val>255)
  {
    /*the address is sharable between UCSRC & UBRRH,
     * so we have to select between them
     *  by writing to URSELbit .
     1 : select UCSRC
     0 : select UBRRH
     */
    USART_REGs->UBRRH_UCSRC_R.URSELbit = 0;
    USART_REGs->UBRRH_UCSRC_R._UBRRH_UCSRC =(uint8_t)(UBRR_val>>8);
    USART_REGs->UBRRL_R = (uint8_t)UBRR_val;
  }
//  Enable receiver and transmitter 
     if (USARTobj->USART_mode == USART_TX_ONLY) {USART_REGs->UCSRB_R._UCSRB |= USART_TX_ONLY;}
else if (USARTobj->USART_mode == USART_RX_ONLY) {USART_REGs->UCSRB_R._UCSRB |= USART_RX_ONLY;}
else if (USARTobj->USART_mode == USART_TX_RX)   {USART_REGs->UCSRB_R._UCSRB |= USART_TX_RX;}
else{}
//Set frame format: 8data, 1stop bit ,parity
USART_REGs->UBRRH_UCSRC_R.URSELbit = 1 ;//If URSEL is one, the UCSRC setting will be updated
USART_REGs->UBRRH_UCSRC_R.UMSELbit = 0 ;//Async
//parity bit
         if(USARTobj->USART_parity == USART_NO_PARITY){USART_REGs->UBRRH_UCSRC_R._UBRRH_UCSRC &=(USART_NO_PARITY);}
    else if(USARTobj->USART_parity == USART_EVEN_PARITY){USART_REGs->UBRRH_UCSRC_R._UBRRH_UCSRC |=USART_EVEN_PARITY;}
    else if(USARTobj->USART_parity == USART_ODD_PARITY){USART_REGs->UBRRH_UCSRC_R._UBRRH_UCSRC |= USART_ODD_PARITY;}
    else {}
//Stop bits
         if(USARTobj->USART_stopbits == USART_1BIT_STOP){USART_REGs->UBRRH_UCSRC_R.UBRR11bit_USBSbit=0; } //1stop bit}
    else if(USARTobj->USART_stopbits == USART_2BIT_STOP){USART_REGs->UBRRH_UCSRC_R.UBRR11bit_USBSbit=1;} //2stop bits}
    else{}
//Data bits format
         if(USARTobj->USART_payloadLenght == USART_5BITS_DATA_FORMAT){USART_REGs->UBRRH_UCSRC_R._UBRRH_UCSRC &= USART_5BITS_DATA_FORMAT;}
    else if(USARTobj->USART_payloadLenght == USART_6BITS_DATA_FORMAT){USART_REGs->UBRRH_UCSRC_R._UBRRH_UCSRC |= USART_6BITS_DATA_FORMAT;}
    else if(USARTobj->USART_payloadLenght == USART_7BITS_DATA_FORMAT){USART_REGs->UBRRH_UCSRC_R._UBRRH_UCSRC |= USART_7BITS_DATA_FORMAT;}
    else if(USARTobj->USART_payloadLenght == USART_8BITS_DATA_FORMAT){USART_REGs->UBRRH_UCSRC_R._UBRRH_UCSRC |= USART_8BITS_DATA_FORMAT;}
    else{} 
    //interrupts
    if(USARTobj->USART_interrupts == USART_ISR_EN && USARTobj->USART_mode == USART_TX_ONLY)
    {
    //enable global interrupt
    GLOBAL_INTERRUPT_ENABLE(); 
    //enable transmitter UART interrupt
    USART_BUFFER_CLEAR_INTERRUPT_ENABLE();
    USART_TRANSMITTER_COMPLETE_INTERRUPT_ENABLE();
    }
    else if(USARTobj->USART_interrupts == USART_ISR_EN && USARTobj->USART_mode == USART_RX_ONLY)
    {
     //enable global interrupt
    GLOBAL_INTERRUPT_ENABLE(); 
    //enable Receiver UART interrupt
    USART_RECEIVER_INTERRUPT_ENABLE();
    }
    else if(USARTobj->USART_interrupts == USART_ISR_EN && USARTobj->USART_mode == USART_TX_RX)
    {
    //enable global interrupt
    GLOBAL_INTERRUPT_ENABLE();
    //enable Receiver UART interrupt
    USART_RECEIVER_INTERRUPT_ENABLE();
    //enable transmitter UART interrupt
  //  USART_BUFFER_CLEAR_INTERRUPT_ENABLE();
    USART_TRANSMITTER_COMPLETE_INTERRUPT_ENABLE();
    }
    else{}
    //PTR To ISR in APP layer
    GptrToISRInApp = USARTobj->USARTptrTofunction;
   
}
/*******************************POOLING**********************************/
void USART_Transmit_Char( unsigned char data )
{
    USART_REGs->UCSRA_R.TXCbit = 0 ;
/* Wait for empty transmit buffer */
    while ( !( USART_REGs->UCSRA_R._UCSRA & (1U<<5)) );
/* Put data into buffer, sends the data */
    UDR_REG = data;
}
void USART_Transmit_Text(char *data )
{
    uint16_t i = 0 ;
    while(data[i]!='\0')
    {
    USART_REGs->UCSRA_R.TXCbit = 0 ;
    /* Wait for empty transmit buffer */
        while ( !( USART_REGs->UCSRA_R._UCSRA & (1U<<5)) );
    /* Put data into buffer, sends the data */
    UDR_REG = *(data+i);
    i++;
    }
}
char USART_Receive( void )
{
/* Wait for data to be received */
while ( !(UCSRA_REG->_UCSRA & (1<<7)) );
/* Get and return received data from buffer */
return UDR_REG;
}
/**************************T_x using Interrupts******************************/
void USART_Send_Char(char data)
{
      /* Wait for empty transmit buffer 
       The UDRE Flag indicates if the transmit 
        * buffer (UDR) is ready to receive new data. 
        * If UDRE is one, the buffer is
        empty, and therefore ready to be written
       */
    while(USART_REGs->UCSRA_R.UDREbit==0); 
    USART_TRANSMITTER_COMPLETE_INTERRUPT_ENABLE();
    USART_BUFFER_CLEAR_INTERRUPT_ENABLE();
    UDR_REG=data;
}
/***********************************ISRs***************************************/
/* USART, Tx Complete */
ISR(USART_TXC_vect)
{
GptrToISRInApp();
}
/* USART, Rx Complete */
ISR(USART_RXC_vect)
{
GptrToISRInApp();
}
/* USART Data Register Empty */
ISR(USART_UDRE_vect)
{ 
GptrToISRInApp();
}















//static char ReadyToSendNewText=0;
//static char *DataBuffer=NULL;
//char USART_Sending_Text_Bussy(void)
//{
//    return(ReadyToSendNewText);
//}



//void USART_Send_text(char *textY)
//{
////   if(USART_Sending_Text_Bussy() == 0)
////   {
////    PORT_Toggle_pin(GPIOC,_PIN0);
////    ReadyToSendNewText=1;   
////    DataBuffer=textY; 
////    //enable global interrupt
////    GLOBAL_INTERRUPT_ENABLE(); 
////    //enable transmitter UART interrupt
////    USART_BUFFER_CLEAR_INTERRUPT_ENABLE();
////    USART_TRANSMITTER_COMPLETE_INTERRUPT_ENABLE();
////   }
//}


//void USART_timeTosend(char *text,USART_config_t *USARTobj)
//{
//   
    //variables
//    char ch[15],number[15];
//    uint32_t dev,rem,timeToSend,size,j,i,bitSizeinUS; 
//    
//    //calculate the time 
//    for(i=0;text[i]!='\0';i++); 
//    bitSizeinUS = (uint32_t)(1E7/USARTobj->USART_baudRate);
//    timeToSend=(uint32_t)(i*bitSizeinUS/1000);
//    dev=timeToSend;
//   
//    //convert time to string
//    for( i =0;dev!=0;i++)
//    {
//    rem=(uint32_t)(dev%10);
//    dev=(uint32_t)(dev/10);
//    switch(rem)
//    {
//        case 0 : ch[i]='0';break;   
//        case 1 : ch[i]='1';break;
//        case 2 : ch[i]='2';break;
//        case 3 : ch[i]='3';break;
//        case 4 : ch[i]='4';break;
//        case 5 : ch[i]='5';break;
//        case 6 : ch[i]='6';break;
//        case 7 : ch[i]='7';break;
//        case 8 : ch[i]='8';break;
//        case 9 : ch[i]='9';break;
//        default: ch[i]='!';break;  
//    }    
//    }
//    
//    //reverse the number because UART sends LSB first 
//    size=(uint32_t)i;j=(uint32_t)0; 
//    for(i =(uint32_t)size;i>0;i--)
//    number[j++]=ch[i-1]; 
//    
//    //add us unit to the string
//    i=(uint32_t)(size);
//    number[i++]=' ';
//    number[i++]='m';
//    number[i++]='s';
//    number[i++]='\r';
//    number[i]='\n';
//    number[i]='\0';
//    //send time via UART
//    
//   USART_Send_text(number);
   
//}
