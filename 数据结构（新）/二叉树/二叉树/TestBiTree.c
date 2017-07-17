#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//����������ڵ�����ݽṹ
typedef struct BiTreeNode
{
	char ch;
	struct BiTreeNode *lchild;	//�������ڵ�
	struct BiTreeNode *rchild;	//�������ڵ�
}BiTreeNode;

//�ݹ����������
void Recursion(BiTreeNode *root)
{
	if (NULL == root)
	{
		return;
	}

	////�������
	//printf("%c", root->ch);		//1.�ȱ������ڵ�
	//Recursion(root->lchild);	//2.�ٱ���������
	//Recursion(root->rchild);	//3.������������

	////�������
	//Recursion(root->lchild);
	//printf("%c", root->ch);
	//Recursion(root->rchild);

	//�������
	Recursion(root->lchild);
	Recursion(root->rchild);
	printf("%c", root->ch);
}

//�������Ҷ�ӽڵ�����
int g_num = 0;
int GetLeafNum(BiTreeNode *root)
{
	if (NULL == root)
	{
		return g_num;
	}

	//������Ҷ�ӽڵ�����
	if (NULL == root->lchild && NULL == root->rchild)	//Ҷ�ӽڵ�
	{
		g_num++;	
	}
	GetLeafNum(root->lchild);	//������
	GetLeafNum(root->rchild);	//������

	return g_num;
}

//��������߶�
int GetHeight(BiTreeNode *root)
{
	if (NULL == root)
	{
		return 0;
	}

	//���������߶�
	int lheight = GetHeight(root->lchild);
	//���������߶�
	int rheight = GetHeight(root->rchild);

	//�Ƚ����������߶ȣ�ȡ���ֵ
	return lheight > rheight ? lheight + 1 : rheight + 1;
}

//����������
BiTreeNode* CopyBiTree(BiTreeNode *root)
{
	if (NULL == root)
	{
		return NULL;
	}

	//����������,���ҽ�����ڵ��ֵ
	BiTreeNode *lchild = CopyBiTree(root->lchild);
	//����������,���ҽ����ҽڵ��ֵ
	BiTreeNode *rchild = CopyBiTree(root->rchild);
	//Ϊ���ڵ����洢�ռ�
	BiTreeNode *newRoot = (BiTreeNode *)calloc(1, sizeof(BiTreeNode));
	//��ֵ
	newRoot->ch = root->ch;
	newRoot->lchild = lchild;
	newRoot->rchild = rchild;

	return newRoot;
}

//�ͷŶ�����
void FreeBiTree(BiTreeNode *root)
{
	if (NULL == root)
	{
		return;
	}

	//�ͷ�������
	FreeBiTree(root->lchild);
	//�ͷ�������
	FreeBiTree(root->rchild);
	//�ͷŵ�ǰ�ڵ�
	printf("%c�ڵ㱻�ͷ�\n", root->ch);
	free(root);
	root = NULL;

}

//�������ǵݹ����(��Ҫ��ջ�Ľṹ����)
void NonRecursion(BiTreeNode *root)
{

}

void test()
{
	//�����ڵ�����
	BiTreeNode nodeA = { 'A', NULL, NULL };
	BiTreeNode nodeB = { 'B', NULL, NULL };
	BiTreeNode nodeC = { 'C', NULL, NULL };
	BiTreeNode nodeD = { 'D', NULL, NULL };
	BiTreeNode nodeE = { 'E', NULL, NULL };
	BiTreeNode nodeF = { 'F', NULL, NULL };
	BiTreeNode nodeG = { 'G', NULL, NULL };
	BiTreeNode nodeH = { 'H', NULL, NULL };

	//������
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;

	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;

	nodeG.lchild = &nodeH;

	//����������
	Recursion(&nodeA);

	//�������Ҷ������
	printf("\n�������ڵ�����: %d\n", GetLeafNum(&nodeA));

	//��������߶ȣ���ȣ�
	printf("�������߶�Ϊ��%d\n", GetHeight(&nodeA));

	//����������
	BiTreeNode *newRoot = CopyBiTree(&nodeA);

	//�ͷŶ�����
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
