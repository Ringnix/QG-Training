#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"
phead* initstack()//����ջ
{
    phead* istack = (phead*)malloc(sizeof(phead));//Ϊͷ�ڵ����ռ�
    if (istack != NULL)//��׳���ж�
    {
        istack->top = NULL;
        istack->size = 0;
    }
    return istack;
}
phead1* initstack1()//����ջ
{
    phead1* istack = (phead1*)malloc(sizeof(phead1));//Ϊͷ�ڵ����ռ�
    if (istack != NULL)//��׳���ж�
    {
        istack->top = NULL;
        istack->size = 0;
    }
    return istack;
}