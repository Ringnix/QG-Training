#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"

int getsize(phead1* stack)
{
    return stack->size;
}
int calculate(char str[])//计算后缀表达式
{
    phead1* istack2 = initstack1();//创建栈
    int i = 0;
    while (str[i] != '\0')//遍历整个后缀表达式
    {
        char a[6] = { 0 };
        int index = 0;
        if (is_number(str[i]) == 1)
        {
            while (is_number(str[i]) == 1)
            {
                a[index] = str[i];
                index++;
                i++;
            }
            //成功读取数字
            seqstack_push1(istack2, atoi(a));//将该整数入栈
        }
        else if (is_operator(str[i]) == 1)
        {
            int right = seqstack_pop1(istack2);
            int left = seqstack_pop1(istack2);
            int ret = express(left, right, str[i]);
            if (ret == 999)//被除数为0了
            {
                printf("ILLEGAL");
                return 999;
            }
            seqstack_push1(istack2, ret);//运算结果入栈
        }
        else if (str[i] == ' ')
        {

        }
        else
        {
            printf("error\n");
            break;
        }
        i++;
    }
    if (str[i] == '\0' && getsize(istack2))
    {
        return seqstack_top1(istack2);
    }
    return 0;
}

