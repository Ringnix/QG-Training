#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"


pnode* seqstack_pop(phead* istack)//����ջ��Ԫ��
{
    if (isempty(istack) == 0)//ջ��Ϊ��
    {
        pnode* account = istack->top;//��¼ջ�������ݽڵ�
        istack->top = istack->top->next;//ָ��ջ����һ��Ԫ��
        istack->size--;//��¼ջ�Ĵ�С
        return account;//���ص��������ݽڵ�
    }
    return NULL;
}
int seqstack_pop1(phead1* istack)//����ջ��Ԫ��
{
    if (isempty1(istack) == 0)//ջ��Ϊ��
    {
        int account = istack->top->val;//��¼ջ�������ݽڵ�
        istack->top = istack->top->next;//ָ��ջ����һ��Ԫ��
        istack->size--;//��¼ջ�Ĵ�С
        return account;//���ص��������ݽڵ�
    }
    return 99999;
}