#pragma once
#define OK 1

#define ERROR 0

typedef int Status;

typedef struct stackNode {

	long int data;

	struct stackNode* next;

}STACKNODE;//定义链栈结点结构

typedef struct stackNode* nodePointer;

typedef struct linkStack {

	nodePointer top;

	int counter;

}LINKSTACK;//定义指针top和计数器结构

int printMenu(void);

void PleaseInit(void);

Status initLinkStack(LINKSTACK* T);

Status insertLinkStack(LINKSTACK* T);

Status printElementNumber(LINKSTACK* T);

Status linkStackEmpty(const LINKSTACK* T);

Status returnLinkStackTop(const LINKSTACK* T);

Status pop(LINKSTACK* T);

Status clearLinkStack(LINKSTACK* T);

Status destroyLinkStack(LINKSTACK* T);
int LStackLength(LINKSTACK* T);