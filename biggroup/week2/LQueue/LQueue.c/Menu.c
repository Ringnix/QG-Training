#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"LQueue.h"

void LPrint(void* q) {
    printf("%s ", (char*)q);
}
void menu() {//�˵�//
    printf("\n*******��ʽ�洢�ķ��Ͷ��в�����*******\n");
    printf("1. ���\n");
    printf("2. ����\n");
    printf("3. �鿴��ͷԪ��\n");
    printf("4. ���г���\n");
    printf("5. ��������\n");
    printf("6. ��ն���\n");
    printf("7. �˳�\n");
    printf("**************************************\n");
    printf("����������ѡ��(1-7)��");

}