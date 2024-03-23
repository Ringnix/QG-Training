#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"
void seqstack_push(phead* istack, char x)//压栈(入栈)
{
    pnode* temp;//进行压栈的数据节点
    temp = (pnode*)malloc(sizeof(pnode));
    temp->val = x;//填充数据域
    temp->next = istack->top;//连接栈顶的数据节点
    istack->top = temp;//充当栈顶
    istack->size++;//记录栈大小的变化
    return;
}
void seqstack_push1(phead1* istack, int x)//压栈(入栈)
{
    pnode1* temp;//进行压栈的数据节点
    temp = (pnode1*)malloc(sizeof(pnode1));
    temp->val = x;//填充数据域
    temp->next = istack->top;//连接栈顶的数据节点
    istack->top = temp;//充当栈顶
    istack->size++;//记录栈大小的变化
    return;
}