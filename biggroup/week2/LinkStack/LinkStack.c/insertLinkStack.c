#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"




//6:Ԫ��ѹ�뵽��ջ��

Status insertLinkStack(LINKSTACK* T)

{

	system("cls");//����

	printf("��ǰѡ��Ϊ--6:Ԫ��ѹ�뵽��ջ��--\n");

	if (T->top == NULL)

	{

		PleaseInit();

		return ERROR;

	}

	nodePointer param;

	int pushElement;

	param = T->top;

	printf("������Ҫѹ���Ԫ��:");

	scanf("%d", &pushElement);

	fflush(stdin);//��ֹ������

	param = (nodePointer)malloc(sizeof(STACKNODE));

	if (param == NULL)

	{

		printf("ѹ��ʧ��!\n");

		return ERROR;

	}

	T->top->data = pushElement;

	param->next = T->top;

	T->counter++;

	T->top = param;

	printf("ѹ��ɹ�!\n");

	return OK;

}