#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H 

#include"stdint.h"
#include"stdlib.h"
#include"stdio.h"
#include"string.h"
#include"conio.h"

#define FLUSH fflush(stdin);fflush(stdout)

struct SData {
	int8_t name[40];
	uint32_t ID;
	float height;
};


 struct Sstudent{
	struct SData StudentData;
	struct Sstudent *next;
};


void AddStudent(void);
void DeleteStudent(void);
void viewStudents(void);
void Delete_Students_Multiple_IDs(uint32_t);
void Delete_all(void);
struct Sstudent* GetNth(uint32_t index,struct Sstudent* _header);
uint32_t Getlength(struct Sstudent* _header);
uint32_t GetlengthREC(struct Sstudent* _header);
struct Sstudent* GetMiddleNode(struct Sstudent* _header);
struct Sstudent* GetNodeFromTheEnd(uint32_t node,struct Sstudent* _header);
void ReversList(struct Sstudent* _header);
#endif