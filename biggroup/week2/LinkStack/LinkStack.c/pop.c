#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"


//7:删除栈顶元素，并返回

Status pop(LINKSTACK* T)

{

	system("cls");//清屏

	printf("当前选的为--7:出栈，并返回栈顶元素--\n");

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

	nodePointer param;

	param = T->top;

	printf("当前栈顶元素为:%d\n", T->top->next->data);

	if (param->next != NULL)

	{

		T->top = param->next;//回退

		T->counter--;

		free(param);//把结点回收

		printf("删除成功!\n");

	}

	return OK;

}