#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"


int priority(char ch)//用来比较优先级
{
    int ret = 0;
    switch (ch)
    {
    case '+'://case穿透,即上一个case没有break语句时会继续向下执行
    case '-':
        ret = 1;
        break;
    case '*':
    case '/':
        ret = 2;
        break;
    default://这里直接break也可以
        break;
    }
    return ret;
}