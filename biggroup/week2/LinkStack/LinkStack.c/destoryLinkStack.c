//2:������ջ
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"
Status destroyLinkStack(LINKSTACK* T)

{

	system("cls");//����

	printf("��ǰѡ��Ϊ--2:������ջ--\n");

	if (T->top == NULL)

	{

		PleaseInit();

		return ERROR;

	}

	char inputValue;
	int scanfResult;

	printf("�Ƿ�Ҫ��������?(Y/N)\n");
	while ((scanfResult = getchar()) != '\n' && scanfResult != EOF) {}
	scanf("%c", &inputValue);
	// ������뻺�����еĻ��з�

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





		printf("���ٳɹ�!\n");

		return OK;

	}

	if (inputValue == 'N' || inputValue == 'n')

	{
		printf("���ٲ�����ȡ��!\n");
		return OK;

	}
	else
	{
		printf("��Ч����! ������Y��N��\n");
		return ERROR;
	}

	return OK;

}