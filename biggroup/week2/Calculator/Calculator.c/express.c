#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"
int express(int left, int right, char op)//opΪ�����,����������
{
    switch (op)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        if (right == 0)
        {
            return 999;
        }
        return left / right;
    default:
        break;
    }
    return -1;
}