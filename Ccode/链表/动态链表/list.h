#pragma once


typedef struct Node
{
	int id;		//数据域
	struct Node *next;	//指针域
}SLIST;

SLIST *SListCreat(); //创建头结点

void SListPrint(SLIST *pHead); //遍历所有节点

void SListNodeDelPro(SLIST *pHead, int n);//删除所有值为4的结点

void SListNodeSort(SLIST *pHead);//链表节点排序

void SListNodeInsertPro(SLIST *pHead, int n);//升序插入5

//翻转链表的节点（不是排序，是翻转）
void SListNodeReverse(SLIST *pHead);

void SListDestroy(SLIST *pHead);//释放所有节点
