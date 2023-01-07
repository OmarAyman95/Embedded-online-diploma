/* 
 * File:   Timer0.h
 * Author: OMAR AYMAN
 *
 * Created on November 30, 2022, 7:57 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H

#include <avr/interrupt.h>
#include "ATMGA32MCU.h"
#include "GPIO_MEGA32.h"

#define Fclk_CPU                        16000000UL
#define GLOBAL_INTERRUPT_ENABLE()      SREG_REG->I =1
#define GLOBAL_INTERRUPT_DESABLE()     SREG_REG->I =0

#define TIMER0_STOP                     TCCR0_REG->_TCCR0 &= ~(0xffU)



//modes of timer0
#define TIMER0_NORMAL_MODE_1PS                      (0x01U)
#define TIMER0_NORMAL_MODE_8PS                      (0x02U)
#define TIMER0_NORMAL_MODE_64PS                     (0x03U)
#define TIMER0_NORMAL_MODE_256PS                    (0x04U)
#define TIMER0_NORMAL_MODE_1024PS                   (0x05U)  
#define TIMER0_NORMAL_MODE_EXTERNAL_FALLING         (0x06U)  
#define TIMER0_NORMAL_MODE_EXTERNAL_RISING          (0x07U)



#define TIMER0_CTC_MODE_1PS                         (0x19U)
#define TIMER0_CTC_MODE_8PS                         (0x1AU)
#define TIMER0_CTC_MODE_64PS                        (0x1BU)
#define TIMER0_CTC_MODE_256PS                       (0x1CU)
#define TIMER0_CTC_MODE_1024PS                      (0x1DU)
#define TIMER0_CTC_MODE_EXTERNAL_FALLING            (0x1EU)
#define TIMER0_CTC_MODE_EXTERNAL_RISING             (0x1FU)



#define TIMER0_FAST_NONINV_PWM_MODE_1PS                 (0x69U)
#define TIMER0_FAST_NONINV_PWM_MODE_8PS                 (0x6AU)
#define TIMER0_FAST_NONINV_PWM_MODE_64PS                (0x6BU)
#define TIMER0_FAST_NONINV_PWM_MODE_256PS               (0x6CU)
#define TIMER0_FAST_NONINV_PWM_MODE_1024PS              (0x6DU)
#define TIMER0_FAST_NONINV_PWM_MODE_EXTERNAL_FALLING    (0x6EU)
#define TIMER0_FAST_NONINV_PWM_MODE_EXTERNAL_RISING     (0x6FU)

#define TIMER0_FAST_INV_PWM_MODE_1PS                    (0x79U)
#define TIMER0_FAST_INV_PWM_MODE_8PS                    (0x7AU)
#define TIMER0_FAST_INV_PWM_MODE_64PS                   (0x7BU)
#define TIMER0_FAST_INV_PWM_MODE_256PS                  (0x7CU)
#define TIMER0_FAST_INV_PWM_MODE_1024PS                 (0x7DU)
#define TIMER0_FAST_INV_PWM_MODE_EXTERNAL_FALLING       (0x7EU)
#define TIMER0_FAST_INV_PWM_MODE_EXTERNAL_RISING        (0x7FU)


//interrupt status 
#define EN_T0_interrupt                             (1U)
#define DIS_T0_interrupt                            (0U)



/**================================================================
* TMR0_init
* this function initializes TIMER0, selects the mode of operation from 
 * 3 modes available : Normal, CTC, FAST PWM (this driver does NOT
 * support phase correct PWM mode)
* INPUTS : it takes 3 arguments :
* 1. Timer0_mode      >>>> 3 basic modes (normal has 7 options, CTC has 7,
 *                          FAST PWM has 14 options to choose) according to 
 *                          @ref  : (modes of timer0).
* 2. interrupt_state  >>>>  according to @ref : (interrupt status).
* 3. ocr0             >>>>  value from (0~255) according to your application. 
 *                          note that : you do NOT need to care about this 
 *                                      argument in Normal mode, so you can 
 *                                      set it any value you want, it doe not matter
* it returns nothing !
**/
void TMR0_init(uint8_t Timer0_mode,uint8_t interrupt_state,uint8_t ocr0);  

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TIMER0_H */

