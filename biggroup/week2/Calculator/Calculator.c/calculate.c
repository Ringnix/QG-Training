#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"

int getsize(phead1* stack)
{
    return stack->size;
}
int calculate(char str[])//�����׺���ʽ
{
    phead1* istack2 = initstack1();//����ջ
    int i = 0;
    while (str[i] != '\0')//����������׺���ʽ
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
            //�ɹ���ȡ����
            seqstack_push1(istack2, atoi(a));//����������ջ
        }
        else if (is_operator(str[i]) == 1)
        {
            int right = seqstack_pop1(istack2);
            int left = seqstack_pop1(istack2);
            int ret = express(left, right, str[i]);
            if (ret == 999)//������Ϊ0��
            {
                printf("ILLEGAL");
                return 999;
            }
            seqstack_push1(istack2, ret);//��������ջ
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

