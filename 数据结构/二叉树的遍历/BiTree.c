#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BiNode
{
	char ch;
	struct BiNode *lchild;	//左子树节点
	struct BiNode *rchild;	//右子树节点
}BiNode;

//递归法遍历二叉树
void RecursiveTraversal(BiNode *root)
{
	if (NULL == root)
	{
		return;
	}

	////先序遍历
	////先遍历遍历根节点
	//printf("%c", root->ch);
	////在遍历左子树
	//RecursiveTraversal(root->lchild);
	////最后遍历右子树
	//RecursiveTraversal(root->rchild);


	////中序遍历
	////先遍历左子树
	//RecursiveTraversal(root->lchild);
	////在遍历根节点
	//printf("%c", root->ch);
	////最后遍历右子树
	//RecursiveTraversal(root->rchild);

	//后序遍历
	//先遍历左子树
	RecursiveTraversal(root->lchild);
	//在遍历右子树
	RecursiveTraversal(root->rchild);
	//最后遍历根节点
	printf("%c", root->ch);
}

//求二叉树的叶子节点总数(递归)
int GetLeafNum(BiNode *root, int *num)
{
	if (NULL == root)
	{
		return 0;
	}

	if (NULL == num)	//异常处理
	{
		return -1;
	}

	//本函数采用先序遍历法
	//访问根成员
	if (NULL == root->lchild && NULL == root->rchild)
	{
		(*num)++;
	}

	//遍历左子树
	GetLeafNum(root->lchild, num);

	//遍历右子树
	GetLeafNum(root->rchild, num);
}

//求二叉树的高度(递归)
int GetHeight(BiNode *root)
{
	if (NULL == root)
	{
		return 0;
	}

	//求左子树高度
	int lheight = GetHeight(root->lchild);
	//求右子树高度
	int rheight = GetHeight(root->rchild);
	
	//比较左、右子树高度；取较大值
	return lheight > rheight ? lheight + 1 : rheight + 1;
}

//拷贝二叉树
BiNode *CopyBiTree(BiNode *root)
{
	if (NULL == root)
	{
		return NULL;
	}

	//拷贝左子树
	BiNode *lchild = CopyBiTree(root->lchild);
	//拷贝右子树
	BiNode *rchild = CopyBiTree(root->rchild);

	//为当前节点分配空间
	BiNode *nodeCur = (BiNode *)calloc(1, sizeof(BiNode));
	nodeCur->ch = root->ch;		//赋值
	nodeCur->lchild = lchild;
	nodeCur->rchild = rchild;

	return nodeCur;
}

//释放二叉树
void FreeBiTree(BiNode *root)
{
	if (NULL == root)
	{
		return;
	}

	//释放左子树
	FreeBiTree(root->lchild);
	//释放右子树
	FreeBiTree(root->rchild);
	//释放当前节点
	printf("%c节点被释放!\n", root->ch);
	free(root);
	root = NULL;
}

//二叉树非递归遍历(需要用栈的结构辅助)
void NonRecursion(BiNode *root)
{

}

void test1()
{
	//创建节点数据
	BiNode nodeA = { 'A',NULL,NULL };
	BiNode nodeB = { 'B',NULL,NULL };
	BiNode nodeC = { 'C',NULL,NULL };
	BiNode nodeD = { 'D',NULL,NULL };
	BiNode nodeE = { 'E',NULL,NULL };
	BiNode nodeF = { 'F',NULL,NULL };
	BiNode nodeG = { 'G',NULL,NULL };
	BiNode nodeH = { 'H',NULL,NULL };

	//创建树
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;

	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;

	nodeG.lchild = &nodeH;


	//递归遍历二叉树
	RecursiveTraversal(&nodeA);

	//获取二叉树叶子总数(递归函数实现)
	int num = 0;
	GetLeafNum(&nodeA, &num);
	printf("\n当前二叉树叶子总数为：%d\n", num);


	//获取二叉树的高度(递归函数实现)
	int height = GetHeight(&nodeA);
	printf("当前二叉树高度为：%d\n", height);


	//拷贝二叉树
	BiNode *newRoot = CopyBiTree(&nodeA);
	RecursiveTraversal(newRoot);

	//释放二叉树
	printf("\n");
	FreeBiTree(newRoot);
}

int main(void)
{
	/*******************************************************/
	/*
		二叉树的遍历
			1、递归遍历
			2、非递归遍历
	*/
	/*******************************************************/
	test1();

	printf("\n");
	system("pause");
	return 0;
}
