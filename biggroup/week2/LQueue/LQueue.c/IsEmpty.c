#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// �������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q) {
    return Q->front == NULL ? TRUE : FALSE; // ��ͷָ��ΪNULLʱ���п�
}