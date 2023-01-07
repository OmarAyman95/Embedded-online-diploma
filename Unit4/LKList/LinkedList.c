#include "LinkedList.h"
struct Sstudent *header =NULL;
void AddStudent(void)
{
	struct Sstudent *PnewStudent;
	struct Sstudent *PlastStudent;
	int8_t name[40];
	uint32_t ID;
	float height;
	if(header==NULL)
	{
		PnewStudent=(struct Sstudent *)malloc(sizeof(struct Sstudent));
		header=PnewStudent;
	}
	else
	{	
		PlastStudent = header;	
		while(PlastStudent->next != NULL)
			PlastStudent=PlastStudent->next;
		PnewStudent=(struct Sstudent *)malloc(sizeof(struct Sstudent));
		PlastStudent->next = PnewStudent;
	}
 	printf("Enter the name : ");FLUSH;scanf("%s",name);
 	//PnewStudent->StudentData.name = name;
 	strcpy(PnewStudent->StudentData.name,name);

	printf("Enter the ID : ");FLUSH;scanf("%d",&ID);
 	PnewStudent->StudentData.ID = ID;
 	
 	printf("Enter the height : ");FLUSH;scanf("%f",&height);
 	PnewStudent->StudentData.height = height;

	PnewStudent->next = NULL;
	Delete_Students_Multiple_IDs(PnewStudent->StudentData.ID);

}

void DeleteStudent(void)
{
	struct Sstudent *currentStudent;
	struct Sstudent *previousStudent;
	volatile uint32_t selectedID;
	int i =0; 
	printf("Enter the Id you want to remove it : : : ");FLUSH;scanf("%d",&selectedID);
	currentStudent = header;
    //  ___________________________1__________________________the linked list is empty
	if(currentStudent==NULL){printf("the list is Empty !\n");}
	else
	{
		while(currentStudent->StudentData.ID != selectedID)
		{
			i++;
			if(currentStudent->next==NULL){printf(":::::%d::::\n\n",i);break;}
			previousStudent=currentStudent;
			currentStudent=currentStudent->next;
			printf(":::::%d::::\n\n",i);

		}
		if(currentStudent->StudentData.ID==selectedID)
		{
         	//________________________2______________________the first student is what we looking for
			// _____2A.1_____ there are other elements 
			//_____2A.2______ this linked list cotatains just 1 element
			if(currentStudent==header)
			{
			if(currentStudent->next != NULL)
				header = currentStudent->next;
		    else
		    	header = NULL;
			free(currentStudent);
			}
			//______________________3__________________________the last student is what we looking for 
			else if(currentStudent->next==NULL)
			{
		
			previousStudent->next=NULL;
			free(currentStudent);
			}
        	// ______________________4__________________________the student we want at the Middle 
			else
			{
		 	previousStudent->next=currentStudent->next;
			free(currentStudent);
			}
			printf("you have just deleted [ID = %d] ! \n",selectedID);	
		}
		else if(currentStudent->StudentData.ID!=selectedID)
			printf("you entered an unexisted ID !  \n");

	}
}

void viewStudents(void)
{
	struct Sstudent *currentStudent;
	currentStudent = header;
	uint32_t counter = 0 ;
   //the linked list is empty
	if(currentStudent==NULL){printf("the list is Empty !\n");}
	else
	{	
		do
		{
			counter++;
			printf("Header at ::%p\tthis_student_at::%p\tID = [%d]\tname ::: {%s}\theight :::(%f)\tnext<<<%p>>>\n",header,currentStudent,currentStudent->StudentData.ID,currentStudent->StudentData.name,currentStudent->StudentData.height,currentStudent->next);
			currentStudent=currentStudent->next;
		}while(currentStudent!=NULL);
		printf("\n\t\t####no of nodes in this list is = %d\n",counter);
	}
}

void Delete_all(void)
{
	struct Sstudent *currentStudent;
	struct Sstudent *previousStudent;
	currentStudent = header;
	if(currentStudent==NULL){printf("the list is Empty !\n");}
	else
	{
		while(currentStudent)
		{
			previousStudent=currentStudent;
			free(previousStudent);
			currentStudent=currentStudent->next;
		}
		header=NULL;
	}
}
void Delete_Students_Multiple_IDs(uint32_t selectedID)
{
	struct Sstudent *currentStudent;
	struct Sstudent *previousStudent;
	currentStudent = header;
	uint8_t i = 0 ;
	
		while(currentStudent->StudentData.ID != selectedID  && currentStudent->next!=NULL)
		{
			
			//if(currentStudent->next==NULL){return 1;}
			previousStudent=currentStudent;
			currentStudent=currentStudent->next;

		}
		if(currentStudent->StudentData.ID == selectedID && currentStudent->next!=NULL)
			{
         	//________________________2______________________the first student is what we looking for
			// _____2A.1_____ there are other elements 
			//_____2A.2______ this linked list cotatains just 1 element
			if(currentStudent==header)
			{
			if(currentStudent->next != NULL)
				{header = currentStudent->next;printf("\n\t\tMultiple IDs Detected::2A.1::\n\n");}
		    else
		    	{header = NULL;printf("\n\t\tMultiple IDs Detected::2A.2::\n\n");}
			free(currentStudent);
			}
			//______________________3__________________________the last student is what we looking for 
			else if(currentStudent->next==NULL)
			{
			printf("\n\t\tMultiple IDs Detected::3::\n\n");
			previousStudent->next=NULL;
			free(currentStudent);
			}
        	// ______________________4__________________________the student we want at the Middle 
			else
			{
			printf("\n\t\tMultiple IDs Detected::4::\n\n");
		 	previousStudent->next=currentStudent->next;
			free(currentStudent);
			}
	}			
}

struct Sstudent* GetNth(uint32_t index,struct Sstudent* _header)
{
	struct Sstudent *currentStudent;
	currentStudent = _header;
	uint32_t counter = 0 ;
   //the linked list is empty
	if(currentStudent==NULL)
	{
		printf(" \n \t\t\t the list is Empty !\n");
		return NULL;
	}
	else
	{	
		do
		{
			counter++;
			if(counter==index)break;
			currentStudent=currentStudent->next;
		}while(currentStudent!=NULL);
		if(counter==index)
		{
			printf(" \n \t\t\tdetected at Node%d \n",counter);
			return(currentStudent);
		}
		else
		{
		printf(" \n \t\t\t OUT OF RANGE ! \n");
		return NULL;
		}
	}
}

uint32_t Getlength(struct Sstudent* _header)
{
	struct Sstudent *currentStudent;
	currentStudent = _header;
	uint32_t counter= 0; 
	if(currentStudent!=NULL)
	{
	do
	{
		counter++;
		currentStudent=currentStudent->next;
	}while(currentStudent!=NULL);
	return counter;
	}
	return 0 ;
}


uint32_t GetlengthREC(struct Sstudent* _header)
{
	if(_header==NULL)
		return 0;
	else
	{
		if(_header->next){return (1+GetlengthREC(_header->next));}
		else {return 1 ; }
	}
}

struct Sstudent* GetMiddleNode(struct Sstudent* _header)
{
	uint32_t length =  Getlength(_header) ; 
	uint32_t Middle ;
	if(length==0)       return NULL;
	else if(length>0)
		{
			Middle = ((length/2)+1);
			return(GetNth(Middle,_header));	
		}

}

struct Sstudent* GetNodeFromTheEnd(uint32_t node,struct Sstudent* _header)
{
	uint32_t length = Getlength(_header);
	uint32_t index ;
	if(length==0)
	{
		printf(" \n \t\t\t the list is Empty !\n");
		return NULL;
	}
	else
	{
	index = (length-node+1);
	return(GetNth(index,_header));	
	}
}

void ReversList(struct Sstudent* _header)
{
	struct Sstudent *nextTest;


	struct Sstudent *currentStudent;
	struct Sstudent *nextsStudent;
	struct Sstudent *LastStudent;
	uint8_t counter= 0;
	if(_header){if(_header->next!=NULL){nextTest=_header->next;if(nextTest->next!=NULL){
while(LastStudent->next!=NULL || counter == 0 )
{
	if(counter==0)
	{
		currentStudent = _header;
		nextsStudent= currentStudent->next;
		currentStudent->next=NULL;
	}
	else
	{
		currentStudent=nextsStudent;
		nextsStudent=LastStudent;
	}
		LastStudent=nextsStudent->next;
		nextsStudent->next=currentStudent;
		counter++;
}
    	LastStudent->next=nextsStudent; 
    	header = LastStudent;
    }
	}
	}
	 if(counter==0)
	 {
     if(_header==NULL) {printf("\n \t##########\n \tList is Empty :::: pls insert such elements ! \n");}
     else if (_header->next==NULL){printf("\n \t##########\n \tthis List contains just 1 element :::: pls insert at least 3 elements ! \n");}
     else if (nextTest->next==NULL){printf("\n \t##########\n \tthis List contains just 2 elements :::: pls insert at least 3 elements ! \n");}
 	}
}

