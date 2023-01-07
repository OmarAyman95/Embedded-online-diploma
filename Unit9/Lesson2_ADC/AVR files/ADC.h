/* 
 * File:   ADC.h
 * Author: OMAR
 *
 * Created on January 7, 2023, 8:17 PM
 */

#ifndef ADC_H
#define	ADC_H

#include "ATMGA32MCU.h"
#include "GPIO_MEGA32.h"
#include <avr/interrupt.h>
typedef struct
{
    uint8_t             ADC_Chanel_Select;          //@ref CHANNELS
    uint8_t             ADC_Interrupt_Enable;       //@ref Interrupt_States
    uint8_t             ADC_Reference_Voltage;      //@ref REFs
    uint8_t             ADC_Trigger_Source;         //@ref Trigger_Sources
    uint8_t             ADC_Prescaler_Factor;       //@ref PRESCALERS
    uint8_t             ADC_RIGHT_LEFT_Adjust;      //@ref RIGHT_LEFT_Adjust   
}ADC_config;

// CHANNELS 
#define ADC_CH0                     (0U)//ADMUX
#define ADC_CH1                     (1U)//ADMUX  
#define ADC_CH2                     (2U)//ADMUX
#define ADC_CH3                     (3U)//ADMUX
#define ADC_CH4                     (4U)//ADMUX
#define ADC_CH5                     (5U)//ADMUX
#define ADC_CH6                     (6U)//ADMUX
#define ADC_CH7                     (7U)//ADMUX

// RIGHT_LEFT_Adjust
#define ADC_LEFT_ADJUST                 (1U<<5)//ADMUX
#define ADC_RIGHT_ADJUST                (0U<<5)//ADMUX

// REFs
#define ADC_REF_AREF                    ((0U<<7) | (0U<<6))//ADMUX
#define ADC_REF_AVCC                    ((0U<<7) | (1U<<6))//ADMUX
#define ADC_REF_VREF                    ((1U<<7) | (0U<<6))//ADMUX
#define ADC_REF_INTERNAL_2_56V          ((1U<<7) | (1U<<6))//ADMUX

// Interrupt_States
#define ADC_INTERRUPT_ENABLE            (1U<<3)//ADCSRA
#define ADC_INTERRUPT_DISABLE           (0U<<3)//ADCSRA

// PRESCALERS
#define ADC_PRESCALER2              ((0U<<2) | (0U<<1) |(0U<<0))//ADCSRA
//#define ADC_PRESCALER2              ((0U<<2) | (0U<<1) |(1U<<0))//ADCSRA
#define ADC_PRESCALER4              ((0U<<2) | (1U<<1) |(0U<<0))//ADCSRA
#define ADC_PRESCALER8              ((0U<<2) | (1U<<1) |(1U<<0))//ADCSRA
#define ADC_PRESCALER16             ((1U<<2) | (0U<<1) |(0U<<0))//ADCSRA
#define ADC_PRESCALER32             ((1U<<2) | (0U<<1) |(1U<<0))//ADCSRA
#define ADC_PRESCALER64             ((1U<<2) | (1U<<1) |(0U<<0))//ADCSRA
#define ADC_PRESCALER128            ((1U<<2) | (1U<<1) |(1U<<0))//ADCSRA

// Trigger_Sources
#define ADC_FREE_RUNNING_TRIGGER                        ((0U<<7) | (0U<<6) |(0U<<5))//SFIOR
#define ADC_ANALOG_COMPARATOR_TRIGGER                   ((0U<<7) | (0U<<6) |(1U<<5))//SFIOR
#define ADC_EXTERNAL_INTERRUPT_REQUEST_TRIGGER          ((0U<<7) | (1U<<6) |(0U<<5))//SFIOR
#define ADC_TIMER0_COMPARE_MATCH_TRIGGER                ((0U<<7) | (1U<<6) |(1U<<5))//SFIOR
#define ADC_TIMER0_OVERFLOW_TRIGGER                     ((1U<<7) | (0U<<6) |(0U<<5))//SFIOR
#define ADC_TIMER1_COMPARE_MATCH_TRIGGER                ((1U<<7) | (0U<<6) |(1U<<5))//SFIOR
#define ADC_TIMER1_OVERFLOW_TRIGGER                     ((1U<<7) | (1U<<6) |(0U<<5))//SFIOR
#define ADC_TIMER1_CAPTURE_EVENT_TRIGGER                ((1U<<7) | (1U<<6) |(1U<<5))//SFIOR



//Global interrupts vector
#define GLOBAL_INTERRUPT_ENABLE()      SREG_REG->I =1
#define GLOBAL_INTERRUPT_DESABLE()     SREG_REG->I =0

//START CONVERSION - TURN ADC_ON/OFF
#define ADC_START_CONVERSION()        ADCSRA_REG->ADSCbit = 1       
#define ADC_ON()                      ADCSRA_REG->ADENbit = 1 
#define ADC_OFF()                     ADCSRA_REG->ADENbit = 0       

//prototypes 

void ADC_init(ADC_config *ADCx);
uint16_t ADC_READ(uint8_t ADC_CHx);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

