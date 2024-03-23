//2:销毁链栈
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"
Status destroyLinkStack(LINKSTACK* T)

{

	system("cls");//清屏

	printf("当前选的为--2:销毁链栈--\n");

	if (T->top == NULL)

	{

		PleaseInit();

		return ERROR;

	}

	char inputValue;
	int scanfResult;

	printf("是否要销毁链表?(Y/N)\n");
	while ((scanfResult = getchar()) != '\n' && scanfResult != EOF) {}
	scanf("%c", &inputValue);
	// 清除输入缓冲区中的换行符

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





		printf("销毁成功!\n");

		return OK;

	}

	if (inputValue == 'N' || inputValue == 'n')

	{
		printf("销毁操作已取消!\n");
		return OK;

	}
	else
	{
		printf("无效输入! 请输入Y或N。\n");
		return ERROR;
	}

	return OK;

}