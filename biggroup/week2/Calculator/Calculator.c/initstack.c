#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"
phead* initstack()//创建栈
{
    phead* istack = (phead*)malloc(sizeof(phead));//为头节点分配空间
    if (istack != NULL)//健壮性判断
    {
        istack->top = NULL;
        istack->size = 0;
    }
    return istack;
}
phead1* initstack1()//创建栈
{
    phead1* istack = (phead1*)malloc(sizeof(phead1));//为头节点分配空间
    if (istack != NULL)//健壮性判断
    {
        istack->top = NULL;
        istack->size = 0;
    }
    return istack;
}