#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"


// ��ʼ������
void InitLQueue(LQueue* Q) {
    Q->front = Q->rear = NULL; // ��ͷ�Ͷ�βָ���ʼ��ΪNULL
    Q->length = 0; // ���г��ȳ�ʼ��Ϊ0
}