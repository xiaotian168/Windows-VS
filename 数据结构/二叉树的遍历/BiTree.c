#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BiNode
{
	char ch;
	struct BiNode *lchild;	//�������ڵ�
	struct BiNode *rchild;	//�������ڵ�
}BiNode;

//�ݹ鷨����������
void RecursiveTraversal(BiNode *root)
{
	if (NULL == root)
	{
		return;
	}

	////�������
	////�ȱ����������ڵ�
	//printf("%c", root->ch);
	////�ڱ���������
	//RecursiveTraversal(root->lchild);
	////������������
	//RecursiveTraversal(root->rchild);


	////�������
	////�ȱ���������
	//RecursiveTraversal(root->lchild);
	////�ڱ������ڵ�
	//printf("%c", root->ch);
	////������������
	//RecursiveTraversal(root->rchild);

	//�������
	//�ȱ���������
	RecursiveTraversal(root->lchild);
	//�ڱ���������
	RecursiveTraversal(root->rchild);
	//���������ڵ�
	printf("%c", root->ch);
}

//���������Ҷ�ӽڵ�����(�ݹ�)
int GetLeafNum(BiNode *root, int *num)
{
	if (NULL == root)
	{
		return 0;
	}

	if (NULL == num)	//�쳣����
	{
		return -1;
	}

	//�������������������
	//���ʸ���Ա
	if (NULL == root->lchild && NULL == root->rchild)
	{
		(*num)++;
	}

	//����������
	GetLeafNum(root->lchild, num);

	//����������
	GetLeafNum(root->rchild, num);
}

//��������ĸ߶�(�ݹ�)
int GetHeight(BiNode *root)
{
	if (NULL == root)
	{
		return 0;
	}

	//���������߶�
	int lheight = GetHeight(root->lchild);
	//���������߶�
	int rheight = GetHeight(root->rchild);
	
	//�Ƚ����������߶ȣ�ȡ�ϴ�ֵ
	return lheight > rheight ? lheight + 1 : rheight + 1;
}

//����������
BiNode *CopyBiTree(BiNode *root)
{
	if (NULL == root)
	{
		return NULL;
	}

	//����������
	BiNode *lchild = CopyBiTree(root->lchild);
	//����������
	BiNode *rchild = CopyBiTree(root->rchild);

	//Ϊ��ǰ�ڵ����ռ�
	BiNode *nodeCur = (BiNode *)calloc(1, sizeof(BiNode));
	nodeCur->ch = root->ch;		//��ֵ
	nodeCur->lchild = lchild;
	nodeCur->rchild = rchild;

	return nodeCur;
}

//�ͷŶ�����
void FreeBiTree(BiNode *root)
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
	printf("%c�ڵ㱻�ͷ�!\n", root->ch);
	free(root);
	root = NULL;
}

//�������ǵݹ����(��Ҫ��ջ�Ľṹ����)
void NonRecursion(BiNode *root)
{

}

void test1()
{
	//�����ڵ�����
	BiNode nodeA = { 'A',NULL,NULL };
	BiNode nodeB = { 'B',NULL,NULL };
	BiNode nodeC = { 'C',NULL,NULL };
	BiNode nodeD = { 'D',NULL,NULL };
	BiNode nodeE = { 'E',NULL,NULL };
	BiNode nodeF = { 'F',NULL,NULL };
	BiNode nodeG = { 'G',NULL,NULL };
	BiNode nodeH = { 'H',NULL,NULL };

	//������
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;

	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;

	nodeG.lchild = &nodeH;


	//�ݹ����������
	RecursiveTraversal(&nodeA);

	//��ȡ������Ҷ������(�ݹ麯��ʵ��)
	int num = 0;
	GetLeafNum(&nodeA, &num);
	printf("\n��ǰ������Ҷ������Ϊ��%d\n", num);


	//��ȡ�������ĸ߶�(�ݹ麯��ʵ��)
	int height = GetHeight(&nodeA);
	printf("��ǰ�������߶�Ϊ��%d\n", height);


	//����������
	BiNode *newRoot = CopyBiTree(&nodeA);
	RecursiveTraversal(newRoot);

	//�ͷŶ�����
	printf("\n");
	FreeBiTree(newRoot);
}

int main(void)
{
	/*******************************************************/
	/*
		�������ı���
			1���ݹ����
			2���ǵݹ����
	*/
	/*******************************************************/
	test1();

	printf("\n");
	system("pause");
	return 0;
}
