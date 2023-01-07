#include "UART.h"
unsigned char string_buffer[100]={"Learn_in_Depth < Omar Ayman>"};
const unsigned char string_buffer2[100]={"Learn_in_Depth < Omar Ayman>"};
void main(void)
	{
	  	uart_send_string(string_buffer);	
	}
