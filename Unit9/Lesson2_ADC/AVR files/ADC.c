#include "ADC.h"

ADC_config *gADCx;
static uint16_t ADCL_H;
void ADC_init(ADC_config *ADCx)
{
    uint8_t tempReg = 0x00;
    // set ADMUX
    tempReg |= ADCx->ADC_Chanel_Select;
    tempReg |= ADCx->ADC_Reference_Voltage;
    tempReg |= ADCx->ADC_RIGHT_LEFT_Adjust;
    ADMUX_REG->_ADMUX = tempReg;
    tempReg = 0x00;
    //set ADCSRA
    tempReg |= ADCx->ADC_Prescaler_Factor;
    tempReg |= ADCx->ADC_Interrupt_Enable;
    ADCSRA_REG->_ADCSRA = tempReg;
    tempReg = 0x00;
    if(ADCx->ADC_Interrupt_Enable == ADC_INTERRUPT_ENABLE)
        GLOBAL_INTERRUPT_ENABLE();
    //set SFIOR
    tempReg |= ADCx->ADC_Trigger_Source;
    SFIOR_REG->_SFIOR |= tempReg;
    tempReg = 0x00;
    if(ADCx->ADC_Trigger_Source != ADC_FREE_RUNNING_TRIGGER)
        ADCSRA_REG->ADATEbit = 1; 
}
uint16_t ADC_READ(uint8_t ADC_CHx)
{
    
    ADC_ON();
    ADC_START_CONVERSION();
    while(ADCSRA_REG->ADIFbit==0);
    ADCL_H = ADCL_REG;
    ADCL_H |= (ADCH_REG<<8);
    ADC_OFF();
    return (ADCL_H);
}

ISR(ADC_vect)
{
   
}