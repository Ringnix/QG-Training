#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// 获取队列长度
int LengthLQueue(LQueue* Q) {
    return Q->length; // 返回队列长度
}