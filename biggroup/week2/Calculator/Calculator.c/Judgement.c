#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"

int is_number(char ch)//�ǲ�������
{
    return(ch >= '0' && ch <= '9');//���ַ���1�����򷵻�0
}
int is_operator(char ch)//�ǲ��������
{
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int is_left(char ch)//�ǲ���������
{
    return(ch == '(');
}
int is_right(char ch)//�ǲ���������
{
    return(ch == ')');
}