#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node//ѹջ�ͳ�ջ����ջ������(�����ջ��ָǰһ��)
{
    char val;//����
    struct node* next;//ָ��
}pnode;
typedef struct seqstack
{
    int size;//��¼ջ�Ĵ�С
    pnode* top;//ָ��ջ��Ԫ��
}phead;
//�·�Ϊ�����׺���ʽ��Ҫ�ĺ���
typedef struct node1//�����ջ������ջ
{
    int val;//����
    struct node1* next;//ָ��
}pnode1;
typedef struct seqstack1
{
    int size;//��¼ջ�Ĵ�С
    pnode1* top;//ָ��ջ��Ԫ��
}phead1;
//��������׺���ʽת��׺���ʽ�ĺ���
char buffer[256] = { 0 };//����������ÿ�����ݶ���ʼ��Ϊ'\0'(\0��ascill����0)
//bufferΪ�����
void char_put(char ch)//�������ַ������������
{
    static int index = 0;//static���徲̬����,�ź����б�ʾindexֻ��ʼ��һ��,ֻ����index�ĸı�
    buffer[index++] = ch;
}