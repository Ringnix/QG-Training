#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"


// 初始化队列
void InitLQueue(LQueue* Q) {
    Q->front = Q->rear = NULL; // 队头和队尾指针初始化为NULL
    Q->length = 0; // 队列长度初始化为0
}