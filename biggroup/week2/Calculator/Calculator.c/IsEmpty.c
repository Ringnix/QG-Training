#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"
int isempty(phead* istack)//ÅÐ¶ÏÕ»Îª¿Õ
{
    if (istack->top == NULL)
    {
        return 1;//Õ»Îª¿Õ
    }
    return 0;//Õ»²»Îª¿Õ
}
int isempty1(phead1* istack)//ÅÐ¶ÏÕ»Îª¿Õ
{
    if (istack->top == NULL)
    {
        return 1;//Õ»Îª¿Õ
    }
    return 0;//Õ»²»Îª¿Õ
}