#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

// 清空队列
void ClearLQueue(LQueue* Q) {
    if (IsEmptyLQueue(Q)) { // 队列为空时
        printf("队列已空\n"); // 提示用户队列已空
        return; // 返回
    }
    else {
        while (!IsEmptyLQueue(Q)) {
            DeLQueue(Q);
        }
    }
    printf("队列已清空\n");
    return TRUE;
}