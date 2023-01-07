#ifndef _LIFO_H_
#define _LIFO_H_
#include "stdint.h"
#include "stdlib.h"
#define ELEMENT_TYPE uint8_t
#define WIDTH 10 
ELEMENT_TYPE buf1[WIDTH];

typedef struct {
	uint32_t length ;
	uint32_t count;
	ELEMENT_TYPE *head;
	ELEMENT_TYPE *base;
}LIFO_Buf_t;
typedef enum {
	LIFO_noERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL
}LIFO_status_t;

LIFO_status_t LIFO_init(LIFO_Buf_t *lifo_buf,ELEMENT_TYPE* buf,uint32_t _length);
LIFO_status_t LIFO_push(LIFO_Buf_t *lifo_buf,ELEMENT_TYPE item);
LIFO_status_t LIFO_pop(LIFO_Buf_t *lifo_buf,ELEMENT_TYPE *item);
LIFO_status_t LIFO_check_status(LIFO_Buf_t *lifo_buf,uint8_t RW);

#endif