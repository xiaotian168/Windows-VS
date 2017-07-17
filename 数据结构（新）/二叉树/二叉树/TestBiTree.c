#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//定义二叉树节点的数据结构
typedef struct BiTreeNode
{
	char ch;
	struct BiTreeNode *lchild;	//左子树节点
	struct BiTreeNode *rchild;	//右子树节点
}BiTreeNode;

//递归遍历二叉树
void Recursion(BiTreeNode *root)
{
	if (NULL == root)
	{
		return;
	}

	////先序遍历
	//printf("%c", root->ch);		//1.先遍历根节点
	//Recursion(root->lchild);	//2.再遍历左子树
	//Recursion(root->rchild);	//3.最后遍历右子树

	////中序遍历
	//Recursion(root->lchild);
	//printf("%c", root->ch);
	//Recursion(root->rchild);

	//后序遍历
	Recursion(root->lchild);
	Recursion(root->rchild);
	printf("%c", root->ch);
}

//求二叉树叶子节点总数
int g_num = 0;
int GetLeafNum(BiTreeNode *root)
{
	if (NULL == root)
	{
		return g_num;
	}

	//先序找叶子节点总数
	if (NULL == root->lchild && NULL == root->rchild)	//叶子节点
	{
		g_num++;	
	}
	GetLeafNum(root->lchild);	//左子树
	GetLeafNum(root->rchild);	//右子树

	return g_num;
}

//求二叉树高度
int GetHeight(BiTreeNode *root)
{
	if (NULL == root)
	{
		return 0;
	}

	//求左子树高度
	int lheight = GetHeight(root->lchild);
	//求右子树高度
	int rheight = GetHeight(root->rchild);

	//比较左、右子树高度；取最大值
	return lheight > rheight ? lheight + 1 : rheight + 1;
}

//拷贝二叉树
BiTreeNode* CopyBiTree(BiTreeNode *root)
{
	if (NULL == root)
	{
		return NULL;
	}

	//拷贝左子树,并且接收左节点的值
	BiTreeNode *lchild = CopyBiTree(root->lchild);
	//拷贝右子树,并且接收右节点的值
	BiTreeNode *rchild = CopyBiTree(root->rchild);
	//为根节点分配存储空间
	BiTreeNode *newRoot = (BiTreeNode *)calloc(1, sizeof(BiTreeNode));
	//赋值
	newRoot->ch = root->ch;
	newRoot->lchild = lchild;
	newRoot->rchild = rchild;

	return newRoot;
}

//释放二叉树
void FreeBiTree(BiTreeNode *root)
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
	printf("%c节点被释放\n", root->ch);
	free(root);
	root = NULL;

}

//二叉树非递归遍历(需要用栈的结构辅助)
void NonRecursion(BiTreeNode *root)
{

}

void test()
{
	//创建节点数据
	BiTreeNode nodeA = { 'A', NULL, NULL };
	BiTreeNode nodeB = { 'B', NULL, NULL };
	BiTreeNode nodeC = { 'C', NULL, NULL };
	BiTreeNode nodeD = { 'D', NULL, NULL };
	BiTreeNode nodeE = { 'E', NULL, NULL };
	BiTreeNode nodeF = { 'F', NULL, NULL };
	BiTreeNode nodeG = { 'G', NULL, NULL };
	BiTreeNode nodeH = { 'H', NULL, NULL };

	//创建树
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;

	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;

	nodeG.lchild = &nodeH;

	//遍历二叉树
	Recursion(&nodeA);

	//求二叉树叶子总数
	printf("\n二叉树节点总数: %d\n", GetLeafNum(&nodeA));

	//求二叉树高度（深度）
	printf("二叉树高度为：%d\n", GetHeight(&nodeA));

	//拷贝二叉树
	BiTreeNode *newRoot = CopyBiTree(&nodeA);

	//释放二叉树
	FreeBiTree(newRoot);

}

int main(void)
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	test();

	printf("\n");
	system("pause");
	return 0;
}
