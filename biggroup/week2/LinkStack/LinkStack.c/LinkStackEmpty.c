#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"


//4:链栈是否为空

Status linkStackEmpty(const LINKSTACK* T)

{

	system("cls");//清屏

	printf("当前选的为--4:链栈是否为空--\n");

	if (T->top == NULL)

	{

		PleaseInit();

		return ERROR;

	}

	if (T->counter == 0)

	{

		printf("当前栈为空,请先压入元素吧\n");

		return ERROR;

	}

	printf("当前链栈不为空\n");

	return OK;

}