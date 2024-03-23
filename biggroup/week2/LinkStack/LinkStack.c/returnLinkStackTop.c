#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"



//5:返回栈顶元素

Status returnLinkStackTop(const LINKSTACK* T)

{

	system("cls");//清屏

	printf("当前选的为--5:返回栈顶元素--\n");

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

	printf("当前栈顶元素为:%d\n", T->top->next->data);

	return OK;

}