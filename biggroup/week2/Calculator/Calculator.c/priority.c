#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"


int priority(char ch)//�����Ƚ����ȼ�
{
    int ret = 0;
    switch (ch)
    {
    case '+'://case��͸,����һ��caseû��break���ʱ���������ִ��
    case '-':
        ret = 1;
        break;
    case '*':
    case '/':
        ret = 2;
        break;
    default://����ֱ��breakҲ����
        break;
    }
    return ret;
}