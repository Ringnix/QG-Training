#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// 检查队列是否为空
Status IsEmptyLQueue(const LQueue* Q) {
    return Q->front == NULL ? TRUE : FALSE; // 队头指针为NULL时队列空
}