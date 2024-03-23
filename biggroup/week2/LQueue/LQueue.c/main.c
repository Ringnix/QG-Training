#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"


int main() {
    LQueue Q;
    InitLQueue(&Q);

    char input[30];
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("请输入要入队的数据：");
            scanf("%s", input);
            EnLQueue(&Q, input);
            break;
        case 2:
            DeLQueue(&Q);
            break;
        case 3:
            if (GetHeadLQueue(&Q, input)) {
                printf("队头元素：%s\n", input);
            }
            else {
                printf("队列已空\n");
            }
            break;
        case 4:
            printf("队列长度：%d\n", LengthLQueue(&Q));
            break;
        case 5:
            TraverseLQueue(&Q, LPrint);
            printf("\n");
            break;
        case 6:
            ClearLQueue(&Q);
            break;
        case 7:
            DestoryLQueue(&Q);
            exit(0);
        default:
            printf("无效的选择，请重新输入。\n");
        }
    }

    return 0;
}
