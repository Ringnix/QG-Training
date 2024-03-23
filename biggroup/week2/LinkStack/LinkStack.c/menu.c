
//打印菜单

int printMenu(void)

{

	int choice;

	printf("****************链栈实现******************\n");

	printf("1:初始化链栈\n");

	printf("2:销毁链栈\n");

	printf("3:清空链栈\n");

	printf("4:链栈是否为空\n");

	printf("5:返回栈顶元素\n");

	printf("6:元素压入到链栈中\n");

	printf("7:删除栈顶元素，并返回\n");

	printf("8:清点栈元素个数\n");

	printf("9:测量链栈长度\n");

	printf("0:退出程序\n");

	printf("*******************************************\n");

	printf("请选择下一步操作:");

	scanf("%d", &choice);

	return choice;

}