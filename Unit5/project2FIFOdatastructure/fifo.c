#include "fifo.h"
uint32_t counter;
Sstudent_Data_t **tempGet;
FIFO_status FIFO_init(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t** buf,uint32_t _length)//FIFO_init(&FIFO_BUF,&ptrstIN[0],WIDTH)
{

	if(buf==NULL)return (FIFO_NULL);
	FIFO_buf->base=buf;
	FIFO_buf->head=buf;
	FIFO_buf->tail=buf;
	FIFO_buf->count=0;
	FIFO_buf->length=_length;

	uint32_t size =  (sizeof(Sstudent_Data_t *) * ((FIFO_buf->length)-1));
	//printf("\n\t\t\t\t\t\t\t          					 size = %u\n",size);
	size=size+(uint32_t)(FIFO_buf->base);
	FIFO_buf->OverFlowAddress = (Sstudent_Data_t **)size;
	(FIFO_buf->OverFlowAddress)++;
	//printf("\n\t\t\t\t\t\t\tFIFO_buf->OverFlowAddress = %p\n",FIFO_buf->OverFlowAddress);
	//printf("\n\t\t\t\t\t\t\t           FIFO_buf->base = %p\n",FIFO_buf->base);
	return(FIFO_noERROR);
}

uint32_t FIFO_countStudents(FIFO_BUF_t *FIFO_buf)
{
	FIFO_status currentStatus;
	uint32_t noOfStudents;
	if(FIFO_buf->count==0)return(0);
	else
	{
	currentStatus = FIFO_Is_full(FIFO_buf);
  if(currentStatus==FIFO_noERROR || currentStatus==FIFO_FULL)return(FIFO_buf->count);
	else if(currentStatus==FIFO_NULL)return(0);
	}
}





Sstudent_Data_t** searchById	 (FIFO_BUF_t *FIFO_buf,uint32_t DestId)
{
	uint32_t i;
	uint32_t savedId=0;
	Sstudent_Data_t **temp ;
	if(FIFO_buf->count==0)
	{
	printf("FIFO is empty you can NOT searchById !\n");
	return(NULL);
	}
	else
	{
		  temp = FIFO_buf->tail;

     	for(i=0;i<FIFO_buf->count;i++)
	{
		printf("temp %x\n",temp);
		savedId=((*temp)->studentID);
		printf("DestId = [%u] \tsavedId = [%u]\n",DestId,savedId);
		if(DestId == savedId){printf("%lu IS EXISTED\n",DestId);return(temp);}
		temp++;
	}
	if(i==FIFO_buf->count){printf("%lu is not existed\n",DestId);return(NULL);}
	}
}

uint32_t checkDuplicatedIDs(FIFO_BUF_t *FIFO_buf,uint32_t IDTocheak)
{
	Sstudent_Data_t **temp ;
	temp = searchById(FIFO_buf,IDTocheak);
	if(temp!=NULL) 
	{
		return(0);
	}
	else return(1);

}


void re_init(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t **buf)
{
	uint32_t offset = (uint32_t)((FIFO_buf->tail)-(FIFO_buf->base)),i;
	counter-=offset;
	FIFO_buf->tail=buf;
	(FIFO_buf->head)-=offset;
	printf("(uint32_t)((FIFO_buf->tail)-(FIFO_buf->base) = %u\n",offset);
	for(i=0;i<(FIFO_buf->length-offset);i++)
	{
		*(buf+i)=*(buf+i+offset);
	}
	FIFO_Print(FIFO_buf);
	printf("FIFO_buf->tail = %xFIFO_buf->head = %x\n",FIFO_buf->tail ,FIFO_buf->head );
}


FIFO_status FIFO_Add_item(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t *item)//(&FIFO_UART,&stIN[counter])
{
	//if(checkDuplicatedIDs(FIFO_buf,item->studentID)==1)
	//{
		FIFO_status currentStatus = FIFO_Is_full(FIFO_buf);
	       
	       //if(currentStatus==FIFO_FULL){re_init(FIFO_buf);}
	       if(currentStatus!=FIFO_noERROR)	return(currentStatus);
		else if(currentStatus==FIFO_noERROR)
		{
			printf("\tAdd [%u] is done! \n",item->studentID);counter++;
  		*(FIFO_buf->head)=item;
  		FIFO_buf->head++;
   		FIFO_buf->count++;
			return(FIFO_noERROR);
		}
//	}
	else 
	{
		printf("\tAdd is failed! {DublicatedIDs: %u} \n",item->studentID);
		return(FIFO_MultipleIDs);
	}
}

FIFO_status FIFO_Get_item(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t **item)
{
	if(!FIFO_buf->base || !FIFO_buf->head || !FIFO_buf->tail )
		return(FIFO_NULL);
	if(FIFO_buf->count==0)
		return(FIFO_EMPTY);

    item = FIFO_buf->tail;
    tempGet=item;
		FIFO_buf->count--;
		FIFO_buf->tail++;
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
	Sstudent_Data_t **temp ;
	uint32_t i,j;
if(FIFO_buf->count==0)
	printf("FIFO is empty you can NOT print !\n");	
else 
{  
	temp = FIFO_buf->tail;
	for(i=0;i<FIFO_buf->count;i++)
		{
			
			printf("%u - {%s %s}\t[GPA:%f]\t[ID:%lu][corses:",i+1,((*temp)->firstName)
				,((*temp)->lastName),((*temp)->studentGPA),((*temp)->studentID));
			printf("%s,",((*temp)->courses.course1));
			printf("%s,",((*temp)->courses.course2));
			printf("%s,",((*temp)->courses.course3));
			printf("%s,",((*temp)->courses.course4));
			printf("%s,",((*temp)->courses.course5));
			printf("%s,",((*temp)->courses.course6));
			printf("%s,",((*temp)->courses.course7));
			printf("%s,",((*temp)->courses.course8));
			printf("%s,",((*temp)->courses.course9));
			printf("%s]\n",((*temp)->courses.course10));
			printf("temp = %x\t\t",temp);
			printf("*temp(address of current data) = %x\t",*temp);
			printf("FIFO_buf->OverFlowAddress= %x\n\n",FIFO_buf->OverFlowAddress);
			temp++;
		}
}
}

void putAtTail(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t** DestStudent)
{
	Sstudent_Data_t *DestLocation,*tailLpcation;

	DestLocation= *DestStudent;
	tailLpcation= *(FIFO_buf->tail);

	*(FIFO_buf->tail) = DestLocation;
	*DestStudent = tailLpcation;

}


void DeleteStudent(FIFO_BUF_t *FIFO_buf,uint32_t DestId)
{
//variables 
	Sstudent_Data_t **tempDest;
	Sstudent_Data_t **item;
	FIFO_status currentUbdateStatus;

	tempDest=searchById(FIFO_buf,DestId);
	if(tempDest!=NULL)
		{
			printf("*tempDest=%x\n",*tempDest);
			putAtTail(FIFO_buf,tempDest);
			currentUbdateStatus = FIFO_Get_item(FIFO_buf,item);
		}	
}
void UpdateStudent(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t **Dest ,Sstudent_Data_t updatedData)
{
	//variables 
			Sstudent_Data_t **tempDest = Dest;
	//check before update....
		//	if( (((*tempDest)->studentID) == updatedData.studentID) ||(checkDuplicatedIDs(FIFO_buf,updatedData.studentID)==1)  )
		//	{
	//Updating ....
			((*tempDest)->studentGPA) =  updatedData.studentGPA;
			((*tempDest)->studentID) =  updatedData.studentID;
			strcpy( ((*tempDest)->firstName),updatedData.firstName);
			strcpy( ((*tempDest)->lastName),updatedData.lastName);
			strcpy( ((*tempDest)->courses.course1),updatedData.courses.course1 );
			strcpy( ((*tempDest)->courses.course2),updatedData.courses.course2 );
			strcpy( ((*tempDest)->courses.course3),updatedData.courses.course3 );
			strcpy( ((*tempDest)->courses.course4),updatedData.courses.course4 );
			strcpy( ((*tempDest)->courses.course5),updatedData.courses.course5 );
			strcpy( ((*tempDest)->courses.course6),updatedData.courses.course6 );
			strcpy( ((*tempDest)->courses.course7),updatedData.courses.course7 );
			strcpy( ((*tempDest)->courses.course8),updatedData.courses.course8 );
			strcpy( ((*tempDest)->courses.course9),updatedData.courses.course9 );
			strcpy( ((*tempDest)->courses.course10),updatedData.courses.course10 );
		//}
	//	else 
	//{
		//printf("\tAdd is failed! {DublicatedIDs: %u} \n",updatedData.studentID);
	//}	
		
}

FIFO_status AddfromFile(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t DataFromFile)
{
	//variables 
			Sstudent_Data_t **tempDest; FIFO_status currentStatus ;
		  tempDest = FIFO_buf->head;
	//cheak first
			   currentStatus = FIFO_Is_full(FIFO_buf);
	       if(currentStatus!=FIFO_noERROR)	return(currentStatus);
	       	//Updating ....
		else if(currentStatus==FIFO_noERROR)
		{


		//	((*tempDest)->studentGPA) =  DataFromFile.studentGPA;
		//	((*tempDest)->studentID) =  DataFromFile.studentID;
		//	strcpy( ((*tempDest)->firstName),DataFromFile.firstName);
		//	strcpy( ((*tempDest)->lastName),DataFromFile.lastName);
			FIFO_buf->head++;
   		FIFO_buf->count++;
   	}
}


Sstudent_Data_t **tempSearch;
void searchByfirstName	(FIFO_BUF_t *FIFO_buf,int8_t *DestfirstName)
{
	uint32_t i;
	if(FIFO_buf->count==0)
	printf("FIFO is empty you can NOT searchByName !\n");
	else
	{
	tempSearch = FIFO_buf->tail;
	for(i=0;i<FIFO_buf->count;i++)
	{
		
		if(  testName(DestfirstName)==1  ){printf("%s is existed\n",DestfirstName);break;}
		tempSearch++;
	}

		if(i==FIFO_buf->count)printf("%s is not existed\n",DestfirstName);
	}
}

int8_t testName(int8_t *name)
{
  int8_t i=0,equal=1,length1,length2;
  for(i=0;((*tempSearch)->firstName)[i]!='\0';i++);length1=i;//printf("length1 = %d ",length1);
  for(i=0;name[i]!='\0';i++);length2=i;//printf("length2 = %d ",length2);

  if(length2==length1)
  {
  for(i=0;i<length1;i++){if(((*tempSearch)->firstName)[i]!=name[i]){equal = 0;break;}}
  if(equal ==0){/*printf("\tN\t");*/ return(0);}
  else if (equal ==1){/*printf("\tequal\t");*/return(1);}
  }
  else if (length2!=length1){/*printf("\tNN\t");*/ return(0);}

}







Sstudent_Data_t **tempSearchCourse;
uint8_t courseRegistered  ;


int8_t testEquality(uint32_t len,int8_t *course1,int8_t *course2)
{
	int8_t equal=1,i;
	for(i=0;i<len;i++)
  {
  if( course1[i]!=course2[i] ){return 0;}
	}
	 return(1);
}

int8_t testCourseName(int8_t *name)
{
  int8_t i=0,equal=1;
  int8_t length1_1,length1_2,length1_3,length1_4,length1_5,length1_6,length1_7,length1_8,length1_9,length1_10;
  int8_t length2;

  for(i=0;((*tempSearchCourse)->courses.course1)[i]!='\0';i++);	length1_1=i;//printf("\nlen1=%d\t",length1_1);
  for(i=0;((*tempSearchCourse)->courses.course2)[i]!='\0';i++);	length1_2=i;//printf("len2=%d\t",length1_2);
  for(i=0;((*tempSearchCourse)->courses.course3)[i]!='\0';i++);	length1_3=i;//printf("len3=%d\t",length1_3);
  for(i=0;((*tempSearchCourse)->courses.course4)[i]!='\0';i++);	length1_4=i;//printf("len4=%d\t",length1_4);
  for(i=0;((*tempSearchCourse)->courses.course5)[i]!='\0';i++);	length1_5=i;//printf("len5=%d\t",length1_5);
  for(i=0;((*tempSearchCourse)->courses.course6)[i]!='\0';i++);	length1_6=i;//printf("len6=%d\t",length1_6);
  for(i=0;((*tempSearchCourse)->courses.course7)[i]!='\0';i++);	length1_7=i;//printf("len7=%d\t",length1_7);
  for(i=0;((*tempSearchCourse)->courses.course8)[i]!='\0';i++);	length1_8=i;//printf("len8=%d\t",length1_8);
  for(i=0;((*tempSearchCourse)->courses.course9)[i]!='\0';i++);	length1_9=i;//printf("len9=%d\t",length1_9);
  for(i=0;((*tempSearchCourse)->courses.course10)[i]!='\0';i++);length1_10=i;//printf("len10=%d\n",length1_10);

  for(i=0;name[i]!='\0';i++);length2=i;//printf("\nlength2 = %d\n",length2);

	if(length2==length1_1)
  {printf("\t\t\t\t\t\t\tlength1_1\n");
	if( testEquality( length2,name , ((*tempSearchCourse)->courses.course1) ) ==1){courseRegistered++; return(1);}
  }

  if(length2==length1_2)
  {printf("\t\t\t\t\t\t\tlength1_2\n");
	if( testEquality( length2,name , ((*tempSearchCourse)->courses.course2) ) ==1){courseRegistered++; return(1);}
  }

	if(length2==length1_3)
  {printf("\t\t\t\t\t\t\tlength1_3\n");
	if( testEquality( length2,name , ((*tempSearchCourse)->courses.course3) ) ==1){courseRegistered++; return(1);}
  }

  if(length2==length1_4)
  {printf("\t\t\t\t\t\t\tlength1_4\n");
	if( testEquality( length2,name , ((*tempSearchCourse)->courses.course4) ) ==1){courseRegistered++; return(1);}
  }

	if(length2==length1_5)
  {printf("\t\t\t\t\t\t\tlength1_5\n");
	if( testEquality( length2,name , ((*tempSearchCourse)->courses.course5) ) ==1){courseRegistered++; return(1);}
  }

  if(length2==length1_6)
  {printf("\t\t\t\t\t\t\tlength1_6\n");
	if( testEquality( length2,name , ((*tempSearchCourse)->courses.course6) ) ==1){courseRegistered++; return(1);}
  }

  if(length2==length1_7)
  {printf("\t\t\t\t\t\t\tlength1_7\n");
	if( testEquality( length2,name , ((*tempSearchCourse)->courses.course7) ) ==1){courseRegistered++; return(1);}
  }

  if(length2==length1_8)
  {printf("\t\t\t\t\t\t\tlength1_8\n");
	if( testEquality( length2,name , ((*tempSearchCourse)->courses.course8) ) ==1){courseRegistered++; return(1);}
  }

  if(length2==length1_9)
  {printf("\t\t\t\t\t\t\tlength1_9\n");
	if( testEquality( length2,name , ((*tempSearchCourse)->courses.course9) ) ==1){courseRegistered++; return(1);}
  }

  if(length2==length1_10)
  {printf("\t\t\t\t\t\t\tlength1_10\n");
	if( testEquality( length2,name , ((*tempSearchCourse)->courses.course10) ) ==1){courseRegistered++; return(1);}
  }

  return 0;
}


void searchcourse	(FIFO_BUF_t *FIFO_buf,int8_t *DestcourseName)
{
	uint32_t i;courseRegistered=0;
	if(FIFO_buf->count==0)
	printf("FIFO is empty you can NOT search a course !\n");
	else
	{
	tempSearchCourse = FIFO_buf->tail;
	for(i=0;i<FIFO_buf->count;i++)
	{
		
		if(  testCourseName(DestcourseName)==1  ){printf("%s is existed\n",DestcourseName);}
		tempSearchCourse++;
	}

		if(courseRegistered==0)printf("%s is not existed\n",DestcourseName);
		else if (courseRegistered>0)
			{printf("%s is existed ...%u times\n",DestcourseName,courseRegistered);courseRegistered=0;}
	}
}
