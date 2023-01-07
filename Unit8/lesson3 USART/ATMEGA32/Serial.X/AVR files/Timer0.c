#include "Timer0.h"
#include "delayT0.h"


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

void TMR0_init(uint8_t Timer0_mode,uint8_t interrupt_state,uint8_t ocr0)
{  
    TCCR0_REG->_TCCR0 = Timer0_mode;
    if(((Timer0_mode & 0x0e) == 0x0e) | ((Timer0_mode & 0x0f) == 0x0f ))
      {
        PORT_init(GPIOB,INPUT_FLOATING_MODE,_PIN0);  
      }
    //Normal Mode 
    if((Timer0_mode >= TIMER0_NORMAL_MODE_1PS) && (Timer0_mode <= TIMER0_NORMAL_MODE_EXTERNAL_RISING))
    {
        TCNT0_REG = 0 ;
        PORT_init(GPIOB,INPUT_FLOATING_MODE,_PIN3);
        if(interrupt_state== EN_T0_interrupt)
        {
         GLOBAL_INTERRUPT_ENABLE();
          TIMSK_REG->TOIE0bit = 1;
          TIMSK_REG->OCIE0bit = 0;
        }
        else if(interrupt_state== DIS_T0_interrupt)
        {
        TIMSK_REG->TOIE0bit = 0;
        }   
    }
    //CTC & FAST PWM Mode
    else if (
            ((Timer0_mode >= TIMER0_CTC_MODE_1PS) 
            && 
            (Timer0_mode <= TIMER0_CTC_MODE_EXTERNAL_RISING))
            ||
            ((Timer0_mode >= TIMER0_FAST_NONINV_PWM_MODE_1PS) 
            && 
            (Timer0_mode <= TIMER0_FAST_NONINV_PWM_MODE_EXTERNAL_RISING))
            ||
            ((Timer0_mode >= TIMER0_FAST_INV_PWM_MODE_1PS) 
            && 
            (Timer0_mode <= TIMER0_FAST_INV_PWM_MODE_EXTERNAL_RISING))
            )
    {
        OCR0_REG = ocr0;  
        PORT_init(GPIOB,OUTPUT_MODE,_PIN3); 
        if(interrupt_state== EN_T0_interrupt)
     {
         GLOBAL_INTERRUPT_ENABLE();
          TIMSK_REG->OCIE0bit = 1; 
          TIMSK_REG->TOIE0bit = 0;
     }
     else if(interrupt_state== DIS_T0_interrupt)
     {
        TIMSK_REG->OCIE0bit = 0;
     } 
    }
    else{}
}
   


   ISR(TIMER0_OVF_vect)
   {
      PORT_Write(GPIOC,~(PORT_Read(GPIOC)));  
   }
  
   ISR(TIMER0_COMP_vect)
   {
     
   }
   
    