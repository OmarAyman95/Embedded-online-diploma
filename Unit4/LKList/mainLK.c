#include "LinkedList.h"
extern struct Sstudent *header;
int main(void)
{
	uint8_t option = 0;
	struct Sstudent *currentStudent;

for(;;)
{
	
	option = 0 ;
	printf("\nenter the option:\n1:Add\t2:view\t3:delete_item\t4:GetNth\t5:GetlengthREC\t6:GetMiddle\t7:Delete_all\t8:GetNodeFromTheEnd\t9:ReversList\n");FLUSH;scanf("%d",&option);
	switch(option)
	{
		case 1 : 
		AddStudent();
		printf("\n####################\n");
		break;
		case 2 : 
		viewStudents();
		printf("\n####################\n");
		break;
		case 3 : 
		DeleteStudent();
		printf("\n####################\n");
		break;
		case 4 : 
		currentStudent=GetNth(2,header);
		if(currentStudent)printf("node:: 2 ::\tthis_student_at::%p\tID = [%d]\tname ::: {%s}\theight :::(%f)\n",currentStudent,currentStudent->StudentData.ID,currentStudent->StudentData.name,currentStudent->StudentData.height);
		printf("\n####################\n");
		break;
		case 5 :
		printf("Length of list is = %d\n",GetlengthREC(header));
		printf("\n####################\n");
		break;
		case 6 :
		currentStudent=GetMiddleNode(header);
		if(currentStudent)printf("Middle Node:::::this_student_at::%p\tID = [%d]\tname ::: {%s}\theight :::(%f)\n",currentStudent,currentStudent->StudentData.ID,currentStudent->StudentData.name,currentStudent->StudentData.height);
		printf("\n####################\n");
		break;
		case 7 :
		Delete_all();
		printf("\n\t\t\tAll________________Deleted \n");
		break;
		case 8 :
		currentStudent=GetNodeFromTheEnd(2,header);	
		if(currentStudent)printf("Node 2 from the end :::::this_student_at::%p\tID = [%d]\tname ::: {%s}\theight :::(%f)\n",currentStudent,currentStudent->StudentData.ID,currentStudent->StudentData.name,currentStudent->StudentData.height);
		printf("\n####################\n");
		break;
		case 9 :
		ReversList(header);
		break;
		default : 
		printf("you have entered a wrong option pls try again ::::\n");
		break;

	}

}
	return(0);
}