#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// 获取队头元素
Status GetHeadLQueue(LQueue* Q, void* e) {
    if (IsEmptyLQueue(Q)) return FALSE; // 队列为空时返回FALSE
    strcpy(e, Q->front->data); // 拷贝队头元素的数据到e指向的内存
    return TRUE; // 成功时返回TRUE
}