#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, * LinkedList;
typedef enum Status {
    error,
    success
} Status;

//����������


Status InitList(LinkedList* L) {
    LinkedList list;

    list = (LinkedList)malloc(sizeof(LNode));
    if (list == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return error;
    }
    list->next = NULL;
    *L = list;

    return success;
}

void DestroyList(LinkedList* L) {
    LinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

Status InsertList(LNode* p, ElemType data) {
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if (newNode == NULL)
    {
        printf("�ڴ����ʧ��\n");
        return error;
    }
    newNode->data = data;
    newNode->next = NULL;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return success;
}

Status DeleteList(LNode* p, ElemType e) {
    LinkedList posNode = p->next;
    LinkedList posNodeFront = p;
    if (posNode == NULL)
    {
        printf("����Ϊ�գ��޷�ɾ��\n");
    }
    else
    {
        while (posNode->data != e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("�����ڸ�����\n");
                return error;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
        return success;
    }
}

void TraverseList(LinkedList L) {
    LinkedList temp;

    temp = L->next;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Status SearchList(LinkedList L, ElemType e) {
    while (L != NULL)
    {
        if (L->data == e)
        {
            return success;
        }
        L = L->next;
    }
    return error;
}


Status ReverseList(LinkedList* L) {
    LNode* newHead;		//����ÿ�η�ת��ĵ�һ���ڵ� 
    LNode* p1;			//ÿ�ζ�ָ��ǰһ���ڵ�	
    LNode* p2;			// ����δ��תǰ����һ���ڵ� 
    p1 = (*L)->next;
    p2 = p1->next;
    p1->next = NULL;
    newHead = p1;
    while (p2 != NULL) {
        p1 = p2;
        p2 = p1->next;
        p1->next = newHead;
        newHead = p1;
    }
    (*L)->next = newHead;
    return success;
}

LNode* FindMidNode(LinkedList L) {
    LinkedList slow = L, fast = L;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Status IsCircleList(LinkedList L) {
    LinkedList fast = L, slow = L;
    while (fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if ((fast = fast->next->next) == NULL)
            return error;
        if (fast == slow)
            return success;
    }
    return error;
}

void show(void)
{
    printf("      ������ADT\n");
    printf("         Menu\n");
    printf("=======================\n");
    printf("1.���ɵ�����\n");
    printf("2.������\n");
    printf("3.���ٵ�����\n");
    printf("4.ɾ�����\n");
    printf("5.��������\n");
    printf("6.���ҽ��\n");
    printf("7.��ת������\n");
    printf("8.�жϵ������Ƿ�ɻ�\n");
    printf("9.���ص������м���\n");
    printf("10.��ż������\n");
    printf("11.�˳�\n");
    printf("=======================\n");
    printf("��ѡ����Ĳ���(1-11)��\n");

}

int Judgement(void)  //���û�������ַ������ж�
{
    int len, num = 0, arg = 1;
    char word[10];
    int m, j = 1, k;
    while (j)
    {
        scanf("%s", word);
        len = strlen(word);
        for (m = 0; m < len; m++)
        {
            if (word[m] < '0' || word[m]>'11')  //���������Ƿ�Ϸ�
            {
                printf("������������");
                break;
            }
            else
            {
                if (m == len - 1)
                    j = 0;
            }
        }
    }
    j = len - 1;
    for (m = 0; m < len; m++)  // ���ַ�����ת��Ϊ����
    {
        for (k = 0; k < j; k++)
            arg *= 10;
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    return num;
}
void oddEvenList(LNode* head) {
    LNode* odd = head;
    LNode* even = head->next;
    LNode* evenHead = even;
    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    
    
}

int main()
{
    int choice=0, num;
    LinkedList head = NULL;
    show();
    while (choice != 11){
        choice = Judgement();   
        
        switch (choice)
        {
        case 1://����������
        
            if (InitList(&head))
            {
                printf("���������ɹ�\n");
            }
            else
            {
                printf("��������ʧ��\n");
            }
            break;
        

        case 2://��������
        
            if (head == NULL)
            {
                printf("���������� ���ȴ�������\n");
            }
            else
            {
                printf("���������ݣ�");
                scanf("%d", &num);
                if (InsertList(head, num))
                {
                    printf("���ݲ���ɹ�\n");
                }
                else
                {
                    printf("���ݲ���ʧ��\n");
                }
            }
            break;
        
        case 3://��������
        
            DestroyList(&head);
            printf("�����������\n");
            break;
        
        case 4://ɾ������
        
            printf("��ѡ��һ�����ݽ���ɾ����");
            scanf("%d", &num);
            if (DeleteList(head, num))
            {
                printf("����ɾ���ɹ�\n");
            }
            else
            {
                printf("����ɾ��ʧ��\n");
            }
            break;
        
        case 5://��������
        
            if (head == NULL || head->next == NULL)
            {
                printf("�������ڣ����ȴ�������\n");
            }
            else
            {
                TraverseList(head);
            }
            break;
        
        case 6://��������
        
            printf("��������Ҫ���ҵ����ݣ�");
            scanf("%d", &num);
            if (SearchList(head, num))
            {
                printf("�ý�����\n");
            }
            else
            {
                printf("�ý�㲻����\n");
            }
            break;
        
        case 7://��ת����
        
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ�ջ�������ֻ�����������\n");
                printf("��תʧ��\n");
            }
            else
            {
                if (ReverseList(&head))
                {
                    printf("��ת�ɹ�\n");
                }
                else
                {
                    printf("����תʧ��\n");
                }

            }
            break;
        
        case 8://�ж������Ƿ�ɻ�
        
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ��\n");
            }
            else
            {
                if (IsCircleList(head))
                {
                    printf("����ɻ�\n");
                }
                else
                {
                    printf("�����ɻ�\n");
                }
            }
            break;
        
        case 9://�����м���
        
            if (head == NULL || head->next == NULL)
            {
                printf("���ǿ�����\n");
            }
            else
            {
                printf("�����м����ֵΪ%d\n", (FindMidNode(head))->data);
            }
            break;
         case 10://��ż����
            if (head == NULL||head->next==NULL) {
                printf("û�пɵ����Ľ��\n");
            }
            else {
                oddEvenList(head);
                TraverseList(head);
            }
            break;
        case 11://��������
        
            DestroyList(&head);
            break;
        
       
        default:
        
            printf("�������������֣�(1-11)\n");
            break;
        
        }
    } 

    return 0;
}