#include "fifo.h"
#define FLUSH fflush(stdin);fflush(stdout)

extern Sstudent_Data_t **tempGet;
static FIFO_BUF_t FIFO_BUF;
static FIFO_status state;
static uint32_t counterforFilemethod=0;
extern uint32_t counter;
Sstudent_Data_t     stIN[WIDTH];
Sstudent_Data_t *ptrstIN[WIDTH];

void checkOption(int8_t option);
void FIFOstart(void);
void count(void);
void add(void);
void get(void);
void search1(void);
void search2(void);
void view(void);
void swapping(void);
void delete(void);
void Update(void);
void addFile(void);
void coursefind(void);
int main(void)
{
	//variables
	int8_t ch ,option;
	//Fifo init
	FIFOstart();
	/*loop forever*/
	for(;;)
	{
 		printf("Enter an option :\t1:add\t2:get\t3:delete\t4:view\t5:searchID\t6:searchName\n\t\t\t7:UpdateStudent\t8:countStudents\t9:addfromFile\t10:coursefind\n"); 		
 		FLUSH;scanf("%d",&option);
 		checkOption(option);		
	}
	return(0);
}

void checkOption(int8_t option)
{
	switch(option)
	{
		case 1 : add();			break;
		case 2 : get();			break;
		case 3 : delete();		break;
		case 4 : view();		break;
		case 5 : search1();		break;
		case 6 : search2();		break;
		case 7 : Update();		break;
		case 8 : count();		break;
		case 9 : addFile();	 	break;
		case 10: coursefind();	break;
		default: printf("error :::please insert the option again ..!\n");break;
	}	
}
void FIFOstart(void)
{
	if(FIFO_init(&FIFO_BUF,&ptrstIN[0],WIDTH)==FIFO_noERROR) 
		printf("FIFO init is done! \n");
	else 
		{printf("FIFO init is failed ! \n");exit(1);}
}
void add(void)
{
	//variables 
	Sstudent_Data_t input;
	int8_t ch ;uint32_t noCourses,j;
	FIFO_status currentStatus;
	if(counter<WIDTH)
	{
		//checkadding
			//data
		printf("::::::::::student%u::::::::\n",counter+1);
		printf("firstName:");FLUSH;gets(stIN[counter].firstName);
		printf("lastName:");FLUSH;gets(stIN[counter].lastName);
		printf("ID:");FLUSH;scanf("%lu",&stIN[counter].studentID);
		printf("GPA:");FLUSH;scanf("%f",&stIN[counter].studentGPA);
			//courses
		printf("no of courses to add (1~10) ? ::::");FLUSH;scanf("%d",&noCourses);
		if((noCourses<1)||(noCourses>10)){printf("error :::no of courses should be (1~10)");}
		else
		{
		for(j=1;j<=noCourses;j++)
		{
			switch(j)
			{
			case 1 : printf("course 1 :");FLUSH;gets(stIN[counter].courses.course1);break;
			case 2 : printf("course 2 :");FLUSH;gets(stIN[counter].courses.course2);break;
			case 3 : printf("course 3 :");FLUSH;gets(stIN[counter].courses.course3);break;
			case 4 : printf("course 4 :");FLUSH;gets(stIN[counter].courses.course4);break;
			case 5 : printf("course 5 :");FLUSH;gets(stIN[counter].courses.course5);break;
			case 6 : printf("course 6 :");FLUSH;gets(stIN[counter].courses.course6);break;
			case 7 : printf("course 7 :");FLUSH;gets(stIN[counter].courses.course7);break;
			case 8 : printf("course 8 :");FLUSH;gets(stIN[counter].courses.course8);break;
			case 9 : printf("course 9 :");FLUSH;gets(stIN[counter].courses.course9);break;
			case 10 :printf("course10 :");FLUSH;gets(stIN[counter].courses.course10);break;
			}
		}
		}
		//save from input stdin into DataStructure(FIFO)
		currentStatus = FIFO_Add_item(&FIFO_BUF,&stIN[counter]);
		printf("\t\tcounter = <%u>\n",counter);
		/*if(currentStatus==FIFO_noERROR)
		{
		printf("newElement?\t(0)ToExit\t(enter)ToContinue\n");FLUSH;scanf("%c",&ch);
		if(ch=='0'){counter++;break;}
		}

		else {printf("\tAdd is failed! {currentStatus : %u} \n",currentStatus);counter--;}*/
		
		}//end of [if(counter<WIDTH)]
	else if(counter==WIDTH)
	{
		re_init(&FIFO_BUF,&ptrstIN[0]);

	}		

		counterforFilemethod=counter;
}
void search1(void)
{
	//variables 
	int8_t ch ;uint32_t IDx;
	Sstudent_Data_t **tempDest;
	//searchById
	printf("ID ?");FLUSH;scanf("%lu",&IDx);
	tempDest=searchById(&FIFO_BUF,IDx);
	if(tempDest!=NULL)
		printf("data of <%s %s> at : %x\n",(*tempDest)->firstName,(*tempDest)->lastName,*tempDest);
}

void search2(void)
{
	//varibles
	int8_t DestName[20],ch;
	printf("DestName?");FLUSH;gets(DestName);
	searchByfirstName(&FIFO_BUF,DestName);
}
void view(void)
{
	FIFO_Print(&FIFO_BUF);
}

void delete(void)
{
	uint32_t IDx;
	printf("ID to delete?");FLUSH;scanf("%lu",&IDx);
	DeleteStudent(&FIFO_BUF,IDx);
}

void get(void)
{
	FIFO_status currentStatus = FIFO_Is_full(&FIFO_BUF);
	         if(currentStatus==FIFO_EMPTY || currentStatus==FIFO_NULL || currentStatus==FIFO_MultipleIDs)
	         	printf("\tGet is failed! {currentStatus : %u} \n",currentStatus);
		else if( currentStatus==FIFO_FULL|| currentStatus==FIFO_noERROR)  
			 	state = FIFO_Get_item(&FIFO_BUF,tempGet);
		
}

void Update(void)
{
	uint32_t IDx,j,noCourses;
	Sstudent_Data_t **tempDest;
	Sstudent_Data_t updatedData={0};

	printf("ID to Update?");FLUSH;scanf("%lu",&IDx);
	tempDest=searchById(&FIFO_BUF,IDx);

	if(tempDest!=NULL)
		{
				//data
		printf("firstName:");FLUSH;gets(updatedData.firstName);
		printf("lastName:");FLUSH;gets(updatedData.lastName);
		printf("ID:");FLUSH;scanf("%lu",&updatedData.studentID);
		printf("GPA:");FLUSH;scanf("%f",&updatedData.studentGPA);
			//courses
		printf("no of courses to add (1~10) ? ::::");FLUSH;scanf("%d",&noCourses);
		if((noCourses<1)||(noCourses>10)){printf("error :::no of courses should be (1~10)");}
		else
		{
		for(j=1;j<=noCourses;j++)
		{
			switch(j)
			{
			case 1 : printf("course 1 :");FLUSH;gets(updatedData.courses.course1);break;
			case 2 : printf("course 2 :");FLUSH;gets(updatedData.courses.course2);break;
			case 3 : printf("course 3 :");FLUSH;gets(updatedData.courses.course3);break;
			case 4 : printf("course 4 :");FLUSH;gets(updatedData.courses.course4);break;
			case 5 : printf("course 5 :");FLUSH;gets(updatedData.courses.course5);break;
			case 6 : printf("course 6 :");FLUSH;gets(updatedData.courses.course6);break;
			case 7 : printf("course 7 :");FLUSH;gets(updatedData.courses.course7);break;
			case 8 : printf("course 8 :");FLUSH;gets(updatedData.courses.course8);break;
			case 9 : printf("course 9 :");FLUSH;gets(updatedData.courses.course9);break;
			case 10 :printf("course10 :");FLUSH;gets(updatedData.courses.course10);break;
			}
		}
		}
		UpdateStudent(&FIFO_BUF,tempDest,updatedData);
		}

	
}

void count(void)
{
 printf("numberOfStudents is = [%u]\n",FIFO_countStudents(&FIFO_BUF));
}


//from file challenge

void addFile(void)
{
	//variables
	 static char txt[400];
	 static uint32_t i = 0 ;
	 uint32_t j;
	 Sstudent_Data_t studentFromFile;
	 char ID[25];unsigned int studentID;
	 char GPA[10];float studentGPA;
	 char firstName[20];
	 char lastName[20];
	FILE *fptr;

	while(txt[i]!='?' && counterforFilemethod<WIDTH)
	{

    //check Null
	   if ((fptr = fopen("e:\\program.txt","r")) == NULL)
	   {
	       printf("Error! opening file");
	       exit(1);
	   }
	

	   fgets(txt,400,fptr );

	   for(j=0;txt[i]!=',';i++){firstName[j++]=txt[i];}  firstName[j]='\0';
	   i++;

	   for(j=0;txt[i]!=',';i++){lastName[j++]=txt[i];} lastName[j++]='\0';
	   i++;

	   for(j=0;txt[i]!=',';i++){ID[j++]=txt[i];} ID[j]='\0';
	   studentID=atoi(ID);
	   i++;

	   for(j=0;txt[i]!='#';i++){GPA[j++]=txt[i];}
	   studentGPA=atof(GPA);
	   i++;
	  // printf("\ni = %c\n",txt[i]);
	  		
	
		//checkadding
	FIFO_status currentStatus = FIFO_Is_full(&FIFO_BUF);
	         if(currentStatus!=FIFO_noERROR){printf("\tAdd is failed! {currentStatus : %u} \n",currentStatus);}
		else if(currentStatus==FIFO_noERROR)
		{
  			//add elements
	   strcpy(stIN[counterforFilemethod].firstName,firstName);
	   strcpy(stIN[counterforFilemethod].lastName,lastName);
	   stIN[counterforFilemethod].studentID = studentID;
	   stIN[counterforFilemethod].studentGPA = studentGPA;
	
		//save from input stdin into DataStructure(FIFO)
		currentStatus = FIFO_Add_item(&FIFO_BUF,&stIN[counterforFilemethod]);
		if(currentStatus==FIFO_noERROR)
		{
		//printf("\tptrstIN[%d]:%p\n",counterforFilemethod,ptrstIN[counterforFilemethod]);
		printf("\tAdd is done!{currentStatus : %u} \n",currentStatus);
	    counterforFilemethod++;
	    counter=counterforFilemethod;
		}
		else
		{
			printf("\tAdd is failed! {currentStatus : %u} \n",currentStatus);
		}
		}

	   fclose(fptr);
	}i=0;
	if(counterforFilemethod==WIDTH)
	{
		re_init(&FIFO_BUF,&ptrstIN[0]);
	}

}

void coursefind(void)
{
	int8_t DestCourse[50];
	printf("course you want to find no of students are registered :");FLUSH;gets(DestCourse);
	searchcourse(&FIFO_BUF,DestCourse);
}
