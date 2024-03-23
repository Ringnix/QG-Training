#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"







//3:清空链栈

Status clearLinkStack(LINKSTACK* T)

{

	system("cls");//清屏

	printf("当前选的为--3:清空链栈--\n");


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

	char inputValue;
	int scanfResult;
	printf("是否要清空链表?(Y/N)\n");
	while ((scanfResult = getchar()) != '\n' && scanfResult != EOF) {}

	scanf("%c", &inputValue);


	if (inputValue == 'Y' || inputValue == 'y')

	{

		nodePointer param;

		while (T->top != NULL)

		{

			param = T->top;

			T->top = param->next;//回退

			T->counter--;

			free(param);//把结点回收

		}

		printf("清除成功!\n");

		return OK;

	}

	if (inputValue == 'N' || inputValue == 'n')

	{
		printf("清空操作已取消!\n");
		return OK;

	}
	else
	{
		printf("无效输入! 请输入Y或N。\n");
		return ERROR;
	}

	return OK;

}
