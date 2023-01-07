#include "fifo.h"

FIFO_status FIFO_init(FIFO_BUF_t *FIFO_buf,ELEMENT_TYPE* buf,uint32_t _length)
{
	if(buf==NULL)return (FIFO_NULL);
	FIFO_buf->base=buf;
	FIFO_buf->head=buf-1;
	FIFO_buf->tail=buf;
	FIFO_buf->count=0;
	FIFO_buf->length=_length;
	return(FIFO_noERROR);
}

FIFO_status FIFO_Add_item(FIFO_BUF_t *FIFO_buf,ELEMENT_TYPE item)
{
	if(!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail )
		return(FIFO_NULL);
    if(FIFO_Is_full(FIFO_buf)==FIFO_FULL)
		return(FIFO_FULL);

   
   if(FIFO_buf->head != ( FIFO_buf->base + ( (FIFO_buf->length-1) * sizeof(ELEMENT_TYPE) ) )  )
   {
  		FIFO_buf->head++;
  		*(FIFO_buf->head)=item;
   	FIFO_buf->count++;
	}
    else if(  FIFO_buf->head == ( FIFO_buf->base + ( (FIFO_buf->length-1) * sizeof(ELEMENT_TYPE) ) )  ) 
	{

		FIFO_buf->head=FIFO_buf->base; 
		*(FIFO_buf->head)=item;
    	FIFO_buf->count++;
	}

    	printf("\tHEAD at %p",FIFO_buf->head);
		return(FIFO_noERROR);
}

FIFO_status FIFO_Get_item(FIFO_BUF_t *FIFO_buf,ELEMENT_TYPE *item)
{

	if(!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail )
		return(FIFO_NULL);
	if(FIFO_buf->count==0)
		return(FIFO_EMPTY);

      *item=*(FIFO_buf->tail);
		FIFO_buf->count--;
		FIFO_buf->tail++;
    
		if(  FIFO_buf->tail == ( FIFO_buf->base + ( FIFO_buf->length * sizeof(ELEMENT_TYPE) ) )  ) 
		FIFO_buf->tail=FIFO_buf->base;
	
	

	return(FIFO_noERROR);
}

FIFO_status FIFO_Is_full (FIFO_BUF_t *FIFO_buf)
{
	if(!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail )
		return(FIFO_NULL);
     if(FIFO_buf->count==FIFO_buf->length)
		return(FIFO_FULL);
	return(FIFO_noERROR);
}

void FIFO_Print(FIFO_BUF_t *FIFO_buf)
{
	ELEMENT_TYPE *temp ;
	uint32_t i ; uint32_t toEND;

if(FIFO_buf->count==0)
	printf("FIFO is empty !\n");	
else if(FIFO_buf->head>FIFO_buf->tail)
{
	  //printf("\n*********FIFO_buf->head  >  FIFO_buf->tail\n");
	temp = FIFO_buf->tail;
	for(i=0;i<FIFO_buf->count;i++){printf("\t at %p ::::: %d \n",temp,*temp);temp++;}
}
else if(FIFO_buf->head<FIFO_buf->tail)
{
	temp = FIFO_buf->tail;
	toEND= FIFO_buf->length-(FIFO_buf->tail-FIFO_buf->base);
	for(i=0;i<toEND;i++){printf("\t at %p ::::: %d \n",temp,*temp);temp++;}

 	temp = FIFO_buf->base;
 	toEND= FIFO_buf->head - FIFO_buf->base ;
 	for(i=0;i<=toEND;i++){printf("\t at %p ::::: %d \n",temp,*temp);temp++;}
}
}