//1:��ʼ����ջ
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"

Status initLinkStack(LINKSTACK* T)

{

	system("cls");//����

	printf("��ǰѡ��Ϊ--1:��ʼ����ջ--\n");

	if (T->top != NULL)

	{

		printf("�����ظ�����\n");

		return ERROR;

	}

	T->top = (nodePointer)malloc(sizeof(STACKNODE));

	if (T->top == NULL)

	{

		printf("��ʼ��ʧ��!\n");

		return ERROR;

	}

	T->counter = 0;//��ʼ��Ϊ0,��ʾ��ջΪ�ա������Ѿ���ʼ����

	T->top->next = NULL;//�������һ���ռ�֮�����ǵ�һ��Ԫ������Ҫѹ��ջ��ջ��Ԫ��û��ָ���Ľ��

	printf("��ʼ���ɹ�!\n");

	return OK;

}