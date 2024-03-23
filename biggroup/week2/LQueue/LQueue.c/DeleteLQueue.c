#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// 出队操作
Status DeLQueue(LQueue* Q) {
    if (IsEmptyLQueue(Q)) { // 队列为空时
        printf("队列已空，快补充些数据吧\n"); // 提示用户队列已空
        return FALSE; // 返回FALSE
    }
    else {
        Node* temp = Q->front; // 临时指针指向队头
        Q->front = Q->front->next; // 队头指针后移
        free(temp->data); // 释放数据内存
        free(temp); // 释放节点内存
        Q->length--; // 队列长度减1
        printf("出队成功\n"); // 提示用户出队成功
        return TRUE; // 返回TRUE
    }
}