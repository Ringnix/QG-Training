#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// ��Ӳ���
Status EnLQueue(LQueue* Q, void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // �����½ڵ��ڴ�
    if (newNode == NULL) return FALSE; // ����ʧ��ʱ����FALSE
    newNode->data = malloc(strlen(data) + 1); // ���������ڴ�
    if (newNode->data == NULL) return FALSE; // ����ʧ��ʱ����FALSE
    strcpy(newNode->data, data); // �������ݵ��½ڵ�
    newNode->next = NULL; // �½ڵ��nextָ������ΪNULL

    if (IsEmptyLQueue(Q)) { // ����Ϊ��ʱ
        Q->front = Q->rear = newNode; // ��ͷ�Ͷ�βָ���½ڵ�
    }
    else {
        Q->rear->next = newNode; // ��β�ڵ��nextָ���½ڵ�
        Q->rear = newNode; // ���¶�βָ��
    }
    Q->length++; // ���г��ȼ�1
    return TRUE; // �ɹ�ʱ����TRUE
}