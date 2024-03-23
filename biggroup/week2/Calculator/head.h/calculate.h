#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node//压栈和出栈都在栈顶进行(这里的栈顶指前一段)
{
    char val;//数据
    struct node* next;//指针
}pnode;
typedef struct seqstack
{
    int size;//记录栈的大小
    pnode* top;//指向栈顶元素
}phead;
//下方为计算后缀表达式需要的函数
typedef struct node1//这里的栈是整型栈
{
    int val;//数据
    struct node1* next;//指针
}pnode1;
typedef struct seqstack1
{
    int size;//记录栈的大小
    pnode1* top;//指向栈顶元素
}phead1;
//下面是中缀表达式转后缀表达式的函数
char buffer[256] = { 0 };//即对数组中每个数据都初始化为'\0'(\0的ascill码是0)
//buffer为结果串
void char_put(char ch)//用来将字符放入放入结果串
{
    static int index = 0;//static定义静态变量,放函数中表示index只初始化一次,只保留index的改变
    buffer[index++] = ch;
}