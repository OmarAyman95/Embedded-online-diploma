/* done by Omar Ayman at  ___5:46___    ___09/30/2022___*/

/*Libraries and MACROS*/
#include"stdint.h"


/*prototypes*/
void Default_handler(void); 
void Reset_handler(void);
void NMI_handler(void)__attribute__((weak,alias("Default_handler")));;
void HardFault_handler(void)__attribute__((weak,alias("Default_handler")));;

extern int main(void);


/*pointers to transfer .data from flash to ram and to initialize .bss in ram*/
extern uint32_t  _E_text;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;

static uint32_t Stack_top[256];

/*Vector Table*/
void (* const g_p_fn_Vectors[])()__attribute__((section(".vectors")))=
{
       (void(*)())((uint32_t)Stack_top+sizeof(Stack_top)),
       Reset_handler,
       NMI_handler,
       HardFault_handler
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