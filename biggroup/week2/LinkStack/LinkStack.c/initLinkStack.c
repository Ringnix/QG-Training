//1:初始化链栈
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"

Status initLinkStack(LINKSTACK* T)

{

	system("cls");//清屏

	printf("当前选的为--1:初始化链栈--\n");

	if (T->top != NULL)

	{

		printf("请勿重复操作\n");

		return ERROR;

	}

	T->top = (nodePointer)malloc(sizeof(STACKNODE));

	if (T->top == NULL)

	{

		printf("初始化失败!\n");

		return ERROR;

	}

	T->counter = 0;//初始化为0,表示链栈为空。但是已经初始化了

	T->top->next = NULL;//申请分配一个空间之后，它是第一个元素所以要压入栈。栈底元素没有指向别的结点

	printf("初始化成功!\n");

	return OK;

}