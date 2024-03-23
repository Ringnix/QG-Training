#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {//±éÀúÁ´±í//
    if (IsEmptyLQueue(Q)) return FALSE;
    Node* current = Q->front;
    while (current != NULL) {
        foo(current->data);
        current = current->next;
    }
    return TRUE;
}