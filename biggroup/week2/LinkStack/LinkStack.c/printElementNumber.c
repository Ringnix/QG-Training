#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"


//8:��ǰջԪ�ظ���

Status printElementNumber(LINKSTACK* T)

{

	system("cls");//����

	printf("��ǰѡ��Ϊ--8:��ǰջԪ�ظ���--\n");

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

	printf("��ǰջԪ�ظ���Ϊ:%d\n", T->counter);

	return OK;

}