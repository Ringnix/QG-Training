#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"
int LStackLength(LINKSTACK* T) {
    system("cls");//清屏
    printf("当前选的为--9:测量链栈长度--\n");
    if (T->top== NULL) {
        // 链栈指针为空，返回错误
        PleaseInit();
        return ERROR;
    }

    int length = 0;
    nodePointer current = T->top;
    while (current != NULL) {
        // 遍历链栈，计算节点数量
        length++;
        current = current->next;
    }
    printf("链栈的长度为%d\n",length);
    // 打印链栈的长度
    return OK;
}