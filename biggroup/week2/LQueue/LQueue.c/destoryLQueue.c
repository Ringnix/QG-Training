#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// ���ٶ���
void DestoryLQueue(LQueue* Q) {
    while (Q->front != NULL) { // �����в�Ϊ��ʱ
        Node* temp = Q->front; // ��ʱָ��ָ���ͷ
        Q->front = Q->front->next; // ��ͷָ�����
        free(temp->data); // �ͷ������ڴ�
        free(temp); // �ͷŽڵ��ڴ�
    }
    Q->rear = NULL; // ��βָ������ΪNULL
    Q->length = 0; // ���г�������Ϊ0
}