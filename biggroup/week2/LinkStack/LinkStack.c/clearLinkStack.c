#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"







//3:�����ջ

Status clearLinkStack(LINKSTACK* T)

{

	system("cls");//����

	printf("��ǰѡ��Ϊ--3:�����ջ--\n");


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

	char inputValue;
	int scanfResult;
	printf("�Ƿ�Ҫ�������?(Y/N)\n");
	while ((scanfResult = getchar()) != '\n' && scanfResult != EOF) {}

	scanf("%c", &inputValue);


	if (inputValue == 'Y' || inputValue == 'y')

	{

		nodePointer param;

		while (T->top != NULL)

		{

			param = T->top;

			T->top = param->next;//����

			T->counter--;

			free(param);//�ѽ�����

		}

		printf("����ɹ�!\n");

		return OK;

	}

	if (inputValue == 'N' || inputValue == 'n')

	{
		printf("��ղ�����ȡ��!\n");
		return OK;

	}
	else
	{
		printf("��Ч����! ������Y��N��\n");
		return ERROR;
	}

	return OK;

}
