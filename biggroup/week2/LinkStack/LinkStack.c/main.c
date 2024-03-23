#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include "LinkStack.h"
#define OK 1

#define ERROR 0
int main(int argc, char* argv[]) {

	int menuChoice;

	LINKSTACK topLinkStack;//声明一个LINKSTACK类型的变量,以后用以指向链栈结点

	topLinkStack.top = NULL;//初始化为NULL,表示没有指向链栈可见当前链栈为空

	while (menuChoice = printMenu())

	{

		switch (menuChoice)

		{

		case 1:

			initLinkStack(&topLinkStack);

			break;

		case 2:

			destroyLinkStack(&topLinkStack);

			break;

		case 3:

			clearLinkStack(&topLinkStack);

			break;

		case 4:

			linkStackEmpty(&topLinkStack);

			break;

		case 5:

			returnLinkStackTop(&topLinkStack);

			break;

		case 6:

			insertLinkStack(&topLinkStack);

			break;

		case 7:

			pop(&topLinkStack);

			break;

		case 8:

			printElementNumber(&topLinkStack);

			break;
		case 9:
			LStackLength(&topLinkStack);
			break;
		}

	}

	return 0;

}