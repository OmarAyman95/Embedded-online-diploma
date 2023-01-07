#ifndef _FIFO_H
#define _FIFO_H	
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define WIDTH 12
#pragma pack(1)



typedef struct{
		int8_t course1 [45];
		int8_t course2 [45];
		int8_t course3 [45];
		int8_t course4 [45];
		int8_t course5 [45];
		int8_t course6 [45];
		int8_t course7 [45];
		int8_t course8 [45];
		int8_t course9 [45];
		int8_t course10[45];
	}Sstudent_courses_t;

	typedef struct{
		int8_t firstName[20];
		int8_t lastName[20];
		uint32_t studentID;
		float studentGPA;
		Sstudent_courses_t courses;
	}Sstudent_Data_t;

	typedef struct{
		Sstudent_Data_t **base;
		Sstudent_Data_t **tail;
		Sstudent_Data_t **head;
		uint32_t  count;
		uint32_t  length;
		Sstudent_Data_t **OverFlowAddress;
	}FIFO_BUF_t;

	typedef enum {
	FIFO_noERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL,
	FIFO_MultipleIDs
}FIFO_status;

FIFO_status 			FIFO_init    				(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t** buf,uint32_t _length);
uint32_t				FIFO_countStudents			(FIFO_BUF_t *FIFO_buf);
uint32_t 				countcheckDuplicatedIDs		(FIFO_BUF_t *FIFO_buf,uint32_t IDTocheak);
FIFO_status 			FIFO_Add_item				(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t *item);
FIFO_status 			FIFO_Get_item				(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t **item);
FIFO_status 			FIFO_Is_full 				(FIFO_BUF_t *FIFO_buf);
void        			FIFO_Print   				(FIFO_BUF_t *FIFO_buf);
Sstudent_Data_t**  		searchById					(FIFO_BUF_t *FIFO_buf,uint32_t DestId);
int8_t 					testName					(int8_t *name);
void        			searchByfirstName			(FIFO_BUF_t *FIFO_buf,int8_t *DestfirstName);
void 					putAtTail					(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t** DestStudent);
void 					DeleteStudent				(FIFO_BUF_t *FIFO_buf,uint32_t DestId);
void 					UpdateStudent				(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t **Dest ,Sstudent_Data_t updatedData);
FIFO_status 			AddfromFile					(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t updatedData);
int8_t 					testCourseName				(int8_t *name);
int8_t 					testEquality				(uint32_t len,int8_t *course1,int8_t *course2);
void 					searchcourse				(FIFO_BUF_t *FIFO_buf,int8_t *DestcourseName);
void 					re_init						(FIFO_BUF_t *FIFO_buf,Sstudent_Data_t **buf);
#endif