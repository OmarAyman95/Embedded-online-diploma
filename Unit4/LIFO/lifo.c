#include "lifo.h"
LIFO_status_t LIFO_init(LIFO_Buf_t *lifo_buf,ELEMENT_TYPE* buf,uint32_t _length)
{
	if(buf==NULL)
		return (LIFO_NULL);
	lifo_buf->base=buf;
	lifo_buf->head=buf;
	lifo_buf->length = _length;
	lifo_buf->count=0;
		return (LIFO_noERROR);
}

LIFO_status_t LIFO_push(LIFO_Buf_t *lifo_buf,ELEMENT_TYPE item)
{
	LIFO_status_t status = LIFO_check_status(lifo_buf,0);
    if(status==LIFO_noERROR)
	{
	*(lifo_buf->head)=item;
	lifo_buf->head++;
	lifo_buf->count++;
	}
	return(status);
}

LIFO_status_t LIFO_pop(LIFO_Buf_t *lifo_buf,ELEMENT_TYPE *item)
{
	LIFO_status_t status = LIFO_check_status(lifo_buf,1);
	if(status==LIFO_noERROR)
	{
	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->count--;
	}
	return(status);
}

LIFO_status_t LIFO_check_status(LIFO_Buf_t *lifo_buf,uint8_t RW)
{
	if(!lifo_buf->base || !lifo_buf->head)
		return(LIFO_NULL);
	else if(lifo_buf->count == lifo_buf->length && RW ==0)
		return(LIFO_FULL);
	else if(lifo_buf->count == 0 && RW ==1)
		return(LIFO_EMPTY);
	else 
		return(LIFO_noERROR);
}