#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// ��ն���
void ClearLQueue(LQueue* Q) {
    if (IsEmptyLQueue(Q)) { // ����Ϊ��ʱ
        printf("�����ѿ�\n"); // ��ʾ�û������ѿ�
        return; // ����
    }
    else {
        while (!IsEmptyLQueue(Q)) {
            DeLQueue(Q);
        }
    }
    printf("���������\n");
    return TRUE;
}