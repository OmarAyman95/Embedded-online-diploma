#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

/*==================Includes=======================*/


/*=====================MACRos======================*/

//#define main __main
/*===================prototypes====================*/


/*===================typeDefs======================*/


/*===================private variables=============*/

uint32_t _Bss_Var;
uint8_t _Bss_Var2;
uint64_t _Data_Var = 100;
uint64_t _Data_Var2 = 100;
const uint64_t _Rodata_Var = 0xDEADBEAFDEADBEAF;

void fun1(char * ptr)
{
	free(ptr);
}
int main(int argc, char const *argv[])
{
	char *ptr;
	uint8_t i ;
	ptr = (char *)calloc(100,sizeof(char));
	if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
	_Bss_Var2 = 18;
	_Data_Var = _Bss_Var2;
	_Bss_Var = _Data_Var;
	ptr = realloc(ptr,sizeof(char) * 20);
	ptr[0] = 'O';
	ptr[1] = 'M';
	ptr[2] = 'A';
	ptr[3] = 'R';
	
	
	
	ptr[4] = 'A';
	ptr[5] = 'Y';
	ptr[6] = 'M';
	ptr[7] = 'A';
	ptr[8] = 'N';

	ptr[9] = '\0';

	
	printf("%c\n%c\n",ptr[0],ptr[8]);
	printf("Heap  :::: %x\t%x\t%x\nstack :::: %x\n",ptr ,&ptr[0],&ptr[20],&i);
	fun1(ptr);
	


	return 0;
}