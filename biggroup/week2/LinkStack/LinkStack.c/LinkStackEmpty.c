#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"


//4:��ջ�Ƿ�Ϊ��

Status linkStackEmpty(const LINKSTACK* T)

{

	system("cls");//����

	printf("��ǰѡ��Ϊ--4:��ջ�Ƿ�Ϊ��--\n");

	if (T->top == NULL)

	{

		PleaseInit();

		return ERROR;

	}

	if (T->counter == 0)

	{

		printf("��ǰջΪ��,����ѹ��Ԫ�ذ�\n");

		return ERROR;

	}

	printf("��ǰ��ջ��Ϊ��\n");

	return OK;

}