#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"
void seqstack_push(phead* istack, char x)//ѹջ(��ջ)
{
    pnode* temp;//����ѹջ�����ݽڵ�
    temp = (pnode*)malloc(sizeof(pnode));
    temp->val = x;//���������
    temp->next = istack->top;//����ջ�������ݽڵ�
    istack->top = temp;//�䵱ջ��
    istack->size++;//��¼ջ��С�ı仯
    return;
}
void seqstack_push1(phead1* istack, int x)//ѹջ(��ջ)
{
    pnode1* temp;//����ѹջ�����ݽڵ�
    temp = (pnode1*)malloc(sizeof(pnode1));
    temp->val = x;//���������
    temp->next = istack->top;//����ջ�������ݽڵ�
    istack->top = temp;//�䵱ջ��
    istack->size++;//��¼ջ��С�ı仯
    return;
}