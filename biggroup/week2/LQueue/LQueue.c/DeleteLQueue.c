#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// ���Ӳ���
Status DeLQueue(LQueue* Q) {
    if (IsEmptyLQueue(Q)) { // ����Ϊ��ʱ
        printf("�����ѿգ��첹��Щ���ݰ�\n"); // ��ʾ�û������ѿ�
        return FALSE; // ����FALSE
    }
    else {
        Node* temp = Q->front; // ��ʱָ��ָ���ͷ
        Q->front = Q->front->next; // ��ͷָ�����
        free(temp->data); // �ͷ������ڴ�
        free(temp); // �ͷŽڵ��ڴ�
        Q->length--; // ���г��ȼ�1
        printf("���ӳɹ�\n"); // ��ʾ�û����ӳɹ�
        return TRUE; // ����TRUE
    }
}