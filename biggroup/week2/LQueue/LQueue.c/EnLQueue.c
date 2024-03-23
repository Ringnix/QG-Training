#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// 入队操作
Status EnLQueue(LQueue* Q, void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // 分配新节点内存
    if (newNode == NULL) return FALSE; // 分配失败时返回FALSE
    newNode->data = malloc(strlen(data) + 1); // 分配数据内存
    if (newNode->data == NULL) return FALSE; // 分配失败时返回FALSE
    strcpy(newNode->data, data); // 拷贝数据到新节点
    newNode->next = NULL; // 新节点的next指针设置为NULL

    if (IsEmptyLQueue(Q)) { // 队列为空时
        Q->front = Q->rear = newNode; // 队头和队尾指向新节点
    }
    else {
        Q->rear->next = newNode; // 队尾节点的next指向新节点
        Q->rear = newNode; // 更新队尾指针
    }
    Q->length++; // 队列长度加1
    return TRUE; // 成功时返回TRUE
}