#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"
int isempty(phead* istack)//�ж�ջΪ��
{
    if (istack->top == NULL)
    {
        return 1;//ջΪ��
    }
    return 0;//ջ��Ϊ��
}
int isempty1(phead1* istack)//�ж�ջΪ��
{
    if (istack->top == NULL)
    {
        return 1;//ջΪ��
    }
    return 0;//ջ��Ϊ��
}