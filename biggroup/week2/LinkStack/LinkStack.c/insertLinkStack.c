#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"




//6:元素压入到链栈中

Status insertLinkStack(LINKSTACK* T)

{

	system("cls");//清屏

	printf("当前选的为--6:元素压入到链栈中--\n");

	if (T->top == NULL)

	{

		PleaseInit();

		return ERROR;

	}

	nodePointer param;

	int pushElement;

	param = T->top;

	printf("请输入要压入的元素:");

	scanf("%d", &pushElement);

	fflush(stdin);//防止多输入

	param = (nodePointer)malloc(sizeof(STACKNODE));

	if (param == NULL)

	{

		printf("压入失败!\n");

		return ERROR;

	}

	T->top->data = pushElement;

	param->next = T->top;

	T->counter++;

	T->top = param;

	printf("压入成功!\n");

	return OK;

}