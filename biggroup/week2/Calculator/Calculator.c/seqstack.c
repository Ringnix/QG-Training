#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"

pnode* seqstack_top(phead* istack)//��ȡջ��Ԫ�ص����ݽڵ�
{
    if (istack->size != 0)//ջ��Ϊ��
    {
        return istack->top;//���ص���ջ�������ݽڵ������ջ����Ԫ��
    }
    return NULL;
}
int seqstack_top1(phead1* istack)//��ȡջ��Ԫ��
{
    if (istack->size != 0)//ջ��Ϊ��
    {
        return istack->top->val;//���ص���ջ��������
    }
    return 99999;
}