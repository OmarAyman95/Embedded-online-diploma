#ifndef _FIFO_H
#define _FIFO_H	
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#define ELEMENT_TYPE  uint8_t
#define WIDTH 10
ELEMENT_TYPE uart_buf[WIDTH];
	typedef struct{
		ELEMENT_TYPE *base;
		ELEMENT_TYPE *tail;
		ELEMENT_TYPE *head;
		uint32_t  count;
		uint32_t  length;
	}FIFO_BUF_t;

	typedef enum {
	FIFO_noERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}FIFO_status;

FIFO_status FIFO_init    (FIFO_BUF_t *FIFO_buf,ELEMENT_TYPE* buf,uint32_t _length);
FIFO_status FIFO_Add_item(FIFO_BUF_t *FIFO_buf,ELEMENT_TYPE item);
FIFO_status FIFO_Get_item(FIFO_BUF_t *FIFO_buf,ELEMENT_TYPE *item);
FIFO_status FIFO_Is_full (FIFO_BUF_t *FIFO_buf);
FIFO_status checkNull	 (FIFO_BUF_t *FIFO_buf);
void        FIFO_Print   (FIFO_BUF_t *FIFO_buf);

#endif