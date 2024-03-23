#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"


pnode* seqstack_pop(phead* istack)//弹出栈顶元素
{
    if (isempty(istack) == 0)//栈不为空
    {
        pnode* account = istack->top;//记录栈顶的数据节点
        istack->top = istack->top->next;//指向栈顶下一个元素
        istack->size--;//记录栈的大小
        return account;//返回弹出的数据节点
    }
    return NULL;
}
int seqstack_pop1(phead1* istack)//弹出栈顶元素
{
    if (isempty1(istack) == 0)//栈不为空
    {
        int account = istack->top->val;//记录栈顶的数据节点
        istack->top = istack->top->next;//指向栈顶下一个元素
        istack->size--;//记录栈的大小
        return account;//返回弹出的数据节点
    }
    return 99999;
}