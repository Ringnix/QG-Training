#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calculate.h"

int transform(char str[])//使用const保护数据,函数用来将中缀转换成后缀
{
    phead* istack = initstack();//创建一个栈
    int i = 0;
    while (str[i] != '\0')//遍历整个字符串
    {
        //判断是不是数字
        if (is_number(str[i]) == 1)
        {
            if (is_number(str[i + 1]) == 1)//后面1也是数字,则直接放
            {
                char_put(str[i]);//数字直接放入结果串(即输出)
            }
            else//后面不是数字,添加一个空格作为分隔符
            {
                char_put(str[i]);
                char_put(' ');
            }
        }
        else if (is_operator((str[i])) == 1)
        {
            if (str[i + 1] == '0' && str[i] == '/')
            {
                printf("ILLEGAL");
                return 0;
            }
            if (isempty(istack) == 0)//栈不为空
            {
                while ((isempty(istack) == 0) && (priority(str[i]) <= (priority(seqstack_top(istack)->val))))//栈不为空并且新运算符优先级不高于栈顶
                {
                    char_put(seqstack_pop(istack)->val);//满足条件的栈顶就弹出直到不满足条件
                    char_put(' ');
                }
            }
            seqstack_push(istack, str[i]);//再将该运算符入栈
        }
        else if (is_left(str[i]))//左括号直接入栈
        {
            seqstack_push(istack, str[i]);
        }
        else if (is_right(str[i]))//判断是不是右括号
        {
            while (is_left(seqstack_top(istack)->val) != 1)//栈顶不是左括号的情况
            {
                char_put(seqstack_pop(istack)->val);//弹出并存储到结果串
                if (isempty(istack) == 1)//栈为空仍未找到左括号
                {
                    printf("没有匹配到左括号\n");
                    return -1;
                }
            }
            //此时匹配到了左括号
            seqstack_pop(istack);
            //弹出左括号,这里并不用保存,即两个括号相抵消
        }
        else
        {
            printf("有不能识别的字符\n");
            return -1;
        }
        i++;
    }
    //遍历完了已经
    if (str[i] == '\0')//成功遍历到字符串末尾
    {
        while (isempty(istack) == 0)//弹出全部栈中元素
        {
            if (seqstack_top(istack)->val == '(')//栈顶元素为左括号
            {
                printf("有没有匹配到的'(',缺少')'\n");
                return -1;
            }
            char_put(seqstack_pop(istack)->val);//将栈中元素放入最终串
        }
    }
    else
    {
        printf("遍历没有完成！\n");
    }
    return 1;
}