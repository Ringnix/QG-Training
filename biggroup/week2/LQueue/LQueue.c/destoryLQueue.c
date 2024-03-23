#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// 销毁队列
void DestoryLQueue(LQueue* Q) {
    while (Q->front != NULL) { // 当队列不为空时
        Node* temp = Q->front; // 临时指针指向队头
        Q->front = Q->front->next; // 队头指针后移
        free(temp->data); // 释放数据内存
        free(temp); // 释放节点内存
    }
    Q->rear = NULL; // 队尾指针设置为NULL
    Q->length = 0; // 队列长度设置为0
}