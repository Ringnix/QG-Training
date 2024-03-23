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
            printf("������Ҫ��ӵ����ݣ�");
            scanf("%s", input);
            EnLQueue(&Q, input);
            break;
        case 2:
            DeLQueue(&Q);
            break;
        case 3:
            if (GetHeadLQueue(&Q, input)) {
                printf("��ͷԪ�أ�%s\n", input);
            }
            else {
                printf("�����ѿ�\n");
            }
            break;
        case 4:
            printf("���г��ȣ�%d\n", LengthLQueue(&Q));
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
            printf("��Ч��ѡ�����������롣\n");
        }
    }

    return 0;
}
