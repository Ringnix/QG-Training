#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"


//7:ɾ��ջ��Ԫ�أ�������

Status pop(LINKSTACK* T)

{

	system("cls");//����

	printf("��ǰѡ��Ϊ--7:��ջ��������ջ��Ԫ��--\n");

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

	nodePointer param;

	param = T->top;

	printf("��ǰջ��Ԫ��Ϊ:%d\n", T->top->next->data);

	if (param->next != NULL)

	{

		T->top = param->next;//����

		T->counter--;

		free(param);//�ѽ�����

		printf("ɾ���ɹ�!\n");

	}

	return OK;

}