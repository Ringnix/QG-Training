#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// ��ȡ��ͷԪ��
Status GetHeadLQueue(LQueue* Q, void* e) {
    if (IsEmptyLQueue(Q)) return FALSE; // ����Ϊ��ʱ����FALSE
    strcpy(e, Q->front->data); // ������ͷԪ�ص����ݵ�eָ����ڴ�
    return TRUE; // �ɹ�ʱ����TRUE
}