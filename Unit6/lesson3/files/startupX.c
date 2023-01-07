/* done by Omar Ayman at  ___5:46___    ___09/30/2022___*/

/*Libraries and MACROS*/
#include"stdint.h"


/*prototypes*/
void Default_handler(void); 
void Reset_handler(void);
void NMI_handler(void)__attribute__((weak,alias("Default_handler")));;
void HardFault_handler(void)__attribute__((weak,alias("Default_handler")));;
void MemManage_handler(void)__attribute__((weak,alias("Default_handler")));;
void BusFault_handler(void)__attribute__((weak,alias("Default_handler")));;
void UsageFault_handler(void)__attribute__((weak,alias("Default_handler")));;
extern int main(void);


/*pointers to transfer .data from flash to ram and to initialize .bss in ram*/
extern uint32_t  _E_text;
extern uint32_t _S_DATA,_E_DATA;
extern uint32_t _S_BSS,_E_BSS;
extern uint32_t _stack_top;

/*Vector Table*/
uint32_t Vectors[] __attribute__((section(".vectors")))=
{
	(uint32_t)&_stack_top,
	(uint32_t)Reset_handler,
	(uint32_t)NMI_handler,
	(uint32_t)HardFault_handler,
	(uint32_t)MemManage_handler,
	(uint32_t)BusFault_handler,
	(uint32_t)UsageFault_handler,
};


/*The definitions of handlers*/
void Reset_handler(void) 
       {

        uint32_t DataSize = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA;
        uint32_t BssSize =  (uint8_t*)&_E_BSS  - (uint8_t*)&_S_BSS;   

        uint8_t *P_src = (uint8_t*)&_E_text;
        uint8_t *P_dst = (uint8_t*)&_S_DATA;
        uint8_t *Pbss = (uint8_t*)&_S_BSS;

        for(uint32_t i = 0 ;i<DataSize;i++)
        {
        *((uint8_t*)P_dst++) = *((uint8_t*)P_src++);
		}		
        for(uint32_t i = 0 ;i<BssSize;i++)
        {
		*((uint8_t*)Pbss++) = (uint8_t)0;
        }
       	main();
       }
void Default_handler(void)      {Reset_handler();}