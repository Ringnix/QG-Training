#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"LinkStack.h"
int LStackLength(LINKSTACK* T) {
    system("cls");//����
    printf("��ǰѡ��Ϊ--9:������ջ����--\n");
    if (T->top== NULL) {
        // ��ջָ��Ϊ�գ����ش���
        PleaseInit();
        return ERROR;
    }

    int length = 0;
    nodePointer current = T->top;
    while (current != NULL) {
        // ������ջ������ڵ�����
        length++;
        current = current->next;
    }
    printf("��ջ�ĳ���Ϊ%d\n",length);
    // ��ӡ��ջ�ĳ���
    return OK;
}