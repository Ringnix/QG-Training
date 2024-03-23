#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"


//8:当前栈元素个数

Status printElementNumber(LINKSTACK* T)

{

	system("cls");//清屏

	printf("当前选的为--8:当前栈元素个数--\n");

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

	printf("当前栈元素个数为:%d\n", T->counter);

	return OK;

}