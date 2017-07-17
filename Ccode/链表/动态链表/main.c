#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "list.h"

typedef struct Stu
{
	int id;	//数据域
	char name[100];

	struct Stu *next;	//指针域
}Stu;

int main01()
{
	/**********************************************************/
	/*
		动态链表，是指在程序执行过程中从无到有地建立起一个链表
		即一个一个地开辟结点和输入各结点数据，并建立起前后
	*/
	/**********************************************************/

	//动态分配3个节点
	Stu *s1 = (Stu *)malloc(sizeof(Stu));
	s1->id = 1;
	strcpy(s1->name, "yuri");

	Stu *s2 = (Stu *)malloc(sizeof(Stu));
	s2->id = 2;
	strcpy(s2->name, "lily");

	Stu *s3 = (Stu *)malloc(sizeof(Stu));
	s3->id = 3;
	strcpy(s3->name, "lilei");

	//建立节点的关系
	s1->next = s2;	//s1的next指针指向s2
	s2->next = s3;
	s3->next = NULL;	//尾结点

	//遍历结点
	Stu *p = s1;
	while (p != NULL)
	{
		printf("id = %d, name = %s\n", p->id, p->name);

		//节点往后移动一位
		p = p->next;
	}

	//释放节点空间
	p = s1;
	Stu *tmp = NULL;
	while (p != NULL)
	{
		tmp = p;
		p = p->next;
		free(tmp);
		tmp = NULL;
	}
	system("pause");
	return 0;
}


int main(void)
{
	/*******************************************************/
	/*
		单向动态链表基本操作
	*/
	/*******************************************************/
	SLIST *pHead = NULL;

	pHead = SListCreat(); //创建头结点
	printf("\n创建头结点后\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeDelPro(pHead, 4);//删除所有值为4的结点
	printf("\n删除所有值为4的结点\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeSort(pHead);//链表节点排序
	printf("\n链表节点排序\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeInsertPro(pHead, 5);//升序插入5
	printf("\n升序插入5后\n");
	SListPrint(pHead); //遍历所有节点

	//翻转链表的节点（不是排序，是翻转）
	SListNodeReverse(pHead);
	printf("\n翻转链表的节点\n");
	SListPrint(pHead); //遍历所有节点

	SListDestroy(pHead);//释放所有节点
	pHead = NULL;

	printf("\n");
	system("pause");
	return 0;
}
