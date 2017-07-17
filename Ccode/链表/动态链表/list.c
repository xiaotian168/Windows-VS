#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include "list.h"
//#pragma warning(disable:4996)

SLIST *SListCreat() //创建头结点
{
	SLIST *head = (SLIST *)calloc(1, sizeof(SLIST));	//为头结点分配空间
	if (head == NULL)
	{
		fprintf(stdout, "head头结点创建失败\n");
		return NULL;
	}
	head->id = -1;	//头结点数据不使用；可随意赋值
	head->next = NULL;

	SLIST *pNew = NULL;		//新节点
	SLIST *pCur = head;	//当前节点

	int n;
	while(1)
	{
		printf("请输入节点数据：");
		scanf("%d", &n);	//接收数据
		if (n == -1)	//-1作为结束标志
			break;
		pNew = (SLIST *)calloc(1, sizeof(SLIST));	//为新节点分配空间
		if (pNew == NULL)
			continue;
		pNew->id = n;	//赋值
		pNew->next = NULL;

		pCur->next = pNew;	//建立节点关系
		pCur = pNew;	//更新当前结点位置
	}
	return head;
}

void SListPrint(SLIST *pHead) //遍历所有节点
{
	if (pHead == NULL)	//异常处理
	{
		fprintf(stdout, "pHead == NULL\n");
		return;
	}

	//方法一：用一个辅助指针
	//SLIST *pCur = pHead->next;	//当前节点
	//printf("Head->");
	//while (pCur)
	//{
	//	printf("%d->", pCur->id);
	//	pCur = pCur->next;
	//}
	//printf("NULL");

	//方法二：直接使用头结点往后遍历
	printf("Head->");
	while (pHead->next)
	{
		printf("%d->", pHead->next->id);
		pHead = pHead->next;
	}
	printf("NULL");
}

void SListNodeDelPro(SLIST *pHead, int n)//删除所有值为4的结点
{
	if (pHead == NULL)	//异常处理
	{
		fprintf(stdout, "未创建链表\n");
		return;
	}

	SLIST *pPre = pHead;
	SLIST *pCur = pHead->next;
	while (pCur)
	{
		if (pCur->id == n)	//判断出现值为n的节点
		{
			pPre->next = pCur->next;	//上一个节点的下一个节点指向当前节点的下一个节点
			free(pCur);		//释放当前节点
			pCur = pPre->next;	//更新当前节点位置
			continue;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}

}

void SListNodeSort(SLIST *pHead)//链表节点排序
{
	if (pHead == NULL || pHead->next == NULL)	//异常处理
	{
		fprintf(stdout, "链表只有一个有效节点\n");
		return;
	}

	SLIST *pPre = NULL;	//获得首节点
	SLIST *pCur = NULL;	//代表首节点的下一个节点
	for (pPre = pHead->next; pPre->next != NULL; pPre = pPre->next)		//选择法排序
	{
		for (pCur = pPre->next; pCur != NULL; pCur = pCur->next)
		{
			if (pPre->id > pCur->id)	//升序
			{
				SLIST tmp = *pPre;
				*pPre = *pCur;
				*pCur = tmp;

				//交换指针域
				tmp.next = pPre->next;
				pPre->next = pCur->next;
				pCur->next = tmp.next;
			}
		}
	}
}

void SListNodeInsertPro(SLIST *pHead, int n)//升序插入5
{
	if (pHead == NULL)	//异常处理
	{
		fprintf(stdout, "未创建链表\n");
		return;
	}

	SLIST *pPre = pHead;	//头节点
	SLIST *pCur = pPre->next;	//下一个节点
	while (pCur)
	{
		if (pCur->id > n)	//找到插入点
		{
			break;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}
	//新节点分配空间
	SLIST *pNew = (SLIST *)calloc(1, sizeof(SLIST));
	if (pNew == NULL)
	{
		fprintf(stdout, "新插入节点空间分配失败\n");
		return;
	}
	pNew->id = n;	//新节点赋值
	
	//程序执行到这，有2种情况
	//1. 找到匹配节点，pCur为当前匹配节点，pPre为上一个节点
	//2. 没有找到匹配节点，节点移动到结尾，pPre为最后一个节点，pCur为NULL
	pPre->next = pNew;
	pNew->next = pCur;
}

//翻转链表的节点（不是排序，是翻转）
void SListNodeReverse(SLIST *pHead)
{
	if (pHead == NULL || pHead->next == NULL || pHead->next->next == NULL)	//异常处理
	{
		fprintf(stdout, "pHead == NULL || pHead->next || pHead->next->next == NULL\n");
		return;
	}

	SLIST *pPre = pHead->next;
	SLIST *pCur = pPre->next;
	SLIST *tmp = NULL;
	while (pCur)
	{
		tmp = pCur->next;	//保存当前节点的next
		pCur->next = pPre;	//让当前节点指向前一个节点
		pPre = pCur;	//前一个节点移动到当前节点
		pCur = tmp;	//当前节点移动到下一个节点
	}

	//先保存尾节点
	pHead->next->next = NULL;
	//头结点在连接首节点
	pHead->next = pPre;
}

void SListDestroy(SLIST *pHead) //释放所有节点
{
	if (pHead == NULL)	//异常处理
	{
		fprintf(stdout, "未创建链表\n");
		return;
	}
	
	SLIST *pCur = NULL;
	while (pHead)
	{
		pCur = pHead->next;	//保存头节点的下一个节点信息
		free(pHead);	//释放头结点
		pHead = pCur;	//头结点移动到下一个节点
	}
}
