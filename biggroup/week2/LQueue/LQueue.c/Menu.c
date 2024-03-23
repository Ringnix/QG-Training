#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

void LPrint(void* q) {
    printf("%s ", (char*)q);
}
void menu() {//菜单//
    printf("\n*******链式存储的泛型队列操作：*******\n");
    printf("1. 入队\n");
    printf("2. 出队\n");
    printf("3. 查看队头元素\n");
    printf("4. 队列长度\n");
    printf("5. 遍历队列\n");
    printf("6. 清空队列\n");
    printf("7. 退出\n");
    printf("**************************************\n");
    printf("请输入您的选择(1-7)：");

}