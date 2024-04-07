#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define maxsize 100

//二叉树的基本操作：建立，前序，中序，后序，层次，求叶子数，求层数,求结点树
//二叉树的数据结构
//创建数据域和左右指针域
typedef struct Tree
{
	char data;
	struct tree* lchild;
	struct tree* rchild;
}tree;

//建立二叉数初始化
void inittree(tree* root)
{
	root->data = "";
	root->rchild = NULL;
	root->lchild = NULL;
}

//二叉数的创建
tree* create(tree* root)
{
	char value;
	scanf_s("%c", &value);
	if (value == '#')
	{
		root = NULL;
	}
	else
	{
		root = (tree*)malloc(sizeof(tree));
		root->data = value;
		root->lchild = create(root->lchild);
		root->rchild = create(root->rchild);
	}
	return root;
}

//创建二叉树的结点(二级指针写法)
void createnode(tree** node)
{
	char p_data;
	scanf_s("%c", &p_data);
	if (p_data == '#')
	{
		*node = NULL;
	}
	else
	{
		*node = (tree*)malloc(sizeof(tree));
		(*node)->data = p_data;
		createnode(&((*node)->lchild));
		createnode(&((*node)->rchild));
	}
}

//判断二叉树是否为空
int tempty(tree* root)
{
	if (root->data == "")
	{
		printf("二叉树为空\n");
		return 0;
	}
	else
	{
		printf("二叉树不为空\n");
		return 1;
	}
}

//先序遍历（递归）
void porder(tree* root)
{
	if (root != NULL)
	{
		printf("%c\t", root->data);
		porder(root->lchild);
		porder(root->rchild);
	}
}

//中序遍历（递归）
void morder(tree* root)
{
	if (root != NULL)
	{
		morder(root->lchild);
		printf("%c\t", root->data);
		morder(root->rchild);
	}
}

//后序遍历（递归）
void torder(tree* root)
{
	if (root != NULL)
	{
		torder(root->lchild);
		torder(root->rchild);
		printf("%c\t", root->data);
	}
}

//先序遍历非递归
//访问左子树的结点存入栈中（继续深入）直到无法访问再让其出栈回退访问右子树
void p_order(tree* root)
{
	if (root == NULL)
	{
		return;
	}
	tree* box[10];//创建栈存储每次打印结点的位置
	int box_top = -1;//栈顶的标记,为和数组下标保持一致
	tree* move = root;//从根节点开始打印
	while (box_top != -1 || move)
	{
		while (move)
		{
			//把路径入栈并且打印结点
			printf("%c\t", move->data);
			box[++box_top] = move;//把结点存入数组中
			move = move->lchild;//移动到存入结点的左子树
		}
		if (box_top != -1)//判断如果访问完左子树
		{
			move = box[box_top];//获取栈顶元素
			box_top--;//回溯
			move = move->rchild;//移动访问右子树
		}
	}
}

//中序遍历非递归
//持续深入左子树并且存储结点直到无法深入然后回溯并且打印，出栈再访问右子树
void m_order(tree* root)
{
	tree* box[10];//创建栈，用于存放结点的位置
	int box_top = -1;//定义栈顶的标记
	tree* move = root;//定义移动的指针
	while (box_top != -1 || move)
	{
		//深入访问左子树
		while (move)
		{
			box[++box_top] = move;
			move = move->lchild;
		}
		if (box_top != -1)
		{
			move = box[box_top--];//获取栈顶元素且回溯
			printf("%c\t", move->data);
			move = move->rchild;//移动到右子树
		}
	}
}

//后序遍历非递归
//先访问左子树一直深入直到无法访问，打印结点然后回溯，再访问右子树，在打印回溯，会出现两个树根
//定义访问标记如果访问过就不再打印来解决回溯后多次打印的问题
void t_order(tree* root)
{
	if (root == NULL)
	{
		return;
	}
	tree* box[10];
	int box_top = -1;
	tree* move = root;
	tree* visit = NULL;//访问标记
	while (move)
	{
		box[++box_top] = move;
		move = move->lchild;
	}
	while (box_top != -1)
	{
		move = box[box_top--];
		if (move->rchild == NULL || move->rchild == visit)//判断当前结点的右子树是否被访问
		{
			printf("%c\t", move->data);
			visit = move;//改变标记的位置就是回溯到上一层的树根
		}
		else
		{
			box[++box_top] = move;
			move = move->rchild;
			while (move)
			{
				box[++box_top] = move;
				move = move->lchild;
			}
		}
	}

}

//二叉树求叶子数
int leaves(tree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->lchild == NULL && root->rchild == NULL)
	{
		return 1;
	}
	else
	{
		return leaves(root->lchild) + leaves(root->rchild);
	}
}

//求树深度的递归算法
int deep(tree* root)
{
	int lnum, rnum;
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		lnum = deep(root->lchild);
		rnum = deep(root->rchild);
		return (lnum > rnum ? lnum : rnum) + 1;
	}
}

//求二叉树中以某值为根的子树深度（递归）
void x_deep(tree* root, char x)
{
	int lnum = 0, rnum = 0;
	if (root == NULL)
	{
		printf("空树深度为0\n");
	}
	if (root->data == x)
	{
		printf("%d\n", deep(root));
	}
	else
	{
		if (root->lchild)
		{
			x_deep(root->lchild, x);
		}
		if (root->rchild)
		{
			x_deep(root->rchild, x);
		}
	}
}

//二叉树求指定结点的层数
int floor(tree* root, char x)
{
	int lnum, rnum, fnum;
	if (root == NULL)
	{
		fnum = 0;
	}
	else if (root->data == x)
	{
		fnum = 1;
	}
	else
	{
		lnum = floor(root->lchild, x);
		rnum = floor(root->rchild, x);
		if (lnum == 0 && rnum == 0)//查找失败
		{
			/*printf("查找结束\n");*/
			fnum = 0;
		}
		else
		{
			fnum = ((lnum > rnum) ? lnum : rnum) + 1;
		}
	}
	return fnum;
}


//统计数中结点个数
int nodenum(tree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return(nodenum(root->lchild) + nodenum(root->rchild)) + 1;
	}
}

//层序遍历BFS
//准备工作：构造队列
typedef struct queue
{
	tree* qdata[maxsize];
	int front;
	int rear;
}q;

//对队列进行初始化
void initqueue(q* node)
{
	node->front = node->rear = 0;
}

//判断队列是否为空
void empty(q* node)
{
	if (node->front == node->rear)
	{
		printf("队列为空");
	}
}

//入队
void push(q* node, tree* root)
{
	node->qdata[node->rear] = root;
	node->rear++;
}

//出队
tree* pop(q* node, tree* root)
{
	return node->qdata[(++node->front) - 1];
}

//二叉树层次遍历BFS
void BFS(tree* root)
{
	q* node;
	node = (q*)malloc(sizeof(q));
	initqueue(node);
	if (root != NULL)
	{
		push(node, root);
	}
	while (node->front != node->rear)
	{
		tree* root1 = (tree*)malloc(sizeof(tree));
		root1 = pop(node, root1);
		printf("%c\t", root1->data);
		if (root1->lchild != NULL)
		{
			push(node, root1->lchild);
		}
		if (root1->rchild != NULL)
		{
			push(node, root1->rchild);
		}
	}
}
void menu() {
	printf("         二叉树综合实验(MENU)\n");
	printf("1.二叉树先序遍历\n");
	printf("2.二叉树中序遍历\n");
	printf("3.二叉树后序遍历\n");
	printf("4.二叉树先序遍历（非递归）\n");
	printf("5.二叉树先序遍历（非递归）\n");
	printf("6.二叉树先序遍历（非递归）\n");
	printf("7.二叉树层次遍历（BFS）\n");
	printf("8.求二叉树深度（递归）\n");
	printf("9.二叉树求叶子数\n");
	printf("10.二叉树求结点数\n");
	printf("11.二叉树求指定结点所在的层数\n");
	printf("12.判断二叉树是否为空树\n");
	printf("13.求二叉树中以某值为根的子树深度（递归）\n");
	printf("14.退出程序\n");
	printf("请输入你的操作（1-14）：");
}
int main()
{
	
	tree* root = (tree*)malloc(sizeof(tree));
	inittree(root);
	printf("请按先序遍历的次序输入二叉树(例如：12#46###3#5##,ABC##DE#G##F###)：\n");
	root = create(root);
	int temp;
	while (1)
	{
		printf("         二叉树综合实验(MENU)\n");
		printf("1.二叉树先序遍历\n");
		printf("2.二叉树中序遍历\n");
		printf("3.二叉树后序遍历\n");
		printf("4.二叉树先序遍历（非递归）\n");
		printf("5.二叉树先序遍历（非递归）\n");
		printf("6.二叉树先序遍历（非递归）\n");
		printf("7.二叉树层次遍历（BFS）\n");
		printf("8.求二叉树深度（递归）\n");
		printf("9.二叉树求叶子数\n");
		printf("10.二叉树求结点数\n");
		printf("11.二叉树求指定结点所在的层数\n");
		printf("12.判断二叉树是否为空树\n");
		printf("13.求二叉树中以某值为根的子树深度（递归）\n");
		printf("14.退出程序\n");
		printf("请输入你的操作（1-14）：");
		scanf_s("%d", &temp);
		if (temp == 14)
		{
			printf("已成功退出程序");
			system("pause");
			break;
		}
		switch (temp)
		{
		case 1:
			system("cls");
			printf("二叉树前序遍历(递归)为：\n");
			porder(root);
			printf("\n");
			break;
		case 2:
			system("cls");
			printf("二叉树中序遍历(递归)为：\n");
			morder(root);
			printf("\n");
			
			
			break;
		case 3:
			system("cls");
			printf("二叉树后序遍历(递归)为：\n");
			torder(root);
			printf("\n");
			
			
			break;
		case 4:
			system("cls");
			printf("二叉树前序遍历为：\n");
			p_order(root);
			printf("\n");
			break;
		case 5:
			system("cls");
			printf("二叉树中序遍历为：\n");
			m_order(root);
			printf("\n");
			break;
		case 6:
			system("cls");
			printf("二叉树后序遍历为：\n");
			t_order(root);
			printf("\n");
			break;
		case 7:
			system("cls");
			printf("BFS层序遍历二叉树：\n");
			BFS(root);
			printf("\n");
			break;
		case 8:
			system("cls");
			printf("二叉树的深度为%d层\n", deep(root));
			break;
		case 9:
			system("cls");
			printf("二叉树中含有%d个叶子结点\n", leaves(root));
			break;
		case 10:
			system("cls");
			printf("二叉树共有%d个结点\n", nodenum(root));
			break;
		case 11:
			system("cls");
		{char x;
		printf("请输入你要查找的结点：");
		scanf_s(" %c", &x);
		
		printf("当前结点所在的层数为：%d\n", floor(root, x));
		getchar();
		}
		break;
		case 12:
			system("cls");
			tempty(root);
			printf("\n");
			break;
		case 13:
			system("cls");
		{
			char x2;
			printf("请输入你要查找的结点：");
			scanf_s(" %c", &x2);
			printf("以%c为子树的深度为：", x2);
			x_deep(root, x2);
			getchar();
			printf("\n");
		}
		break;
		default:
			getchar();
			system("cls");
			printf("输入错误，请重新输入\n");
			break;
		}
	}
	return 0;
}
