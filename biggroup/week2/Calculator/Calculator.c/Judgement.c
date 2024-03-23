#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"

int is_number(char ch)//是不是数字
{
    return(ch >= '0' && ch <= '9');//数字返回1，否则返回0
}
int is_operator(char ch)//是不是运算符
{
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int is_left(char ch)//是不是左括号
{
    return(ch == '(');
}
int is_right(char ch)//是不是右括号
{
    return(ch == ')');
}