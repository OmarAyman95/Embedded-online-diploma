/*
 * keyPad.h
 *
 *  Created on: Nov 22, 2022
 *      Author: OMAR
 */

#ifndef SRC_KEYPAD_H_
#define SRC_KEYPAD_H_

#include"avr/io.h"


//MCAL MACROs
#define KEYPAD_PIN_HIGH(port,pin)   	PORTA |=(1U<<pin)
#define KEYPAD_PIN_LOW(port,pin)   		PORTA &= ~(1U<<pin)
#define KEYPAD_PORT_HIGH(port,data) 	PORTA |=(data)
#define KEYPAD_PORT_LOW(port,data) 		PORTA &= ~(data)
#define KEYPAD_PORT_CLR(port) 			PORTA=0x00;
#define KEYPAD_PORT_READ(port)       	(*(port-2))

char KeyPad_Scanning(volatile unsigned char  *PORT);
#endif /* SRC_KEYPAD_H_ */
