#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"



//5:����ջ��Ԫ��

Status returnLinkStackTop(const LINKSTACK* T)

{

	system("cls");//����

	printf("��ǰѡ��Ϊ--5:����ջ��Ԫ��--\n");

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

	printf("��ǰջ��Ԫ��Ϊ:%d\n", T->top->next->data);

	return OK;

}