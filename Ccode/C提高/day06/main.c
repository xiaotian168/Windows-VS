#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int id;		//数据域
	struct Node *next;	//指针域
}SLIST;

SLIST *SListCreat() //创建头结点
{
	SLIST *pHead = calloc(1, sizeof(SLIST));
	if (pHead == NULL)	//异常处理
	{
		fprintf(stdout,"pHead calloc fail\n");
		return NULL;
	}
	pHead->next = NULL;

	SLIST *pCur = pHead;
	SLIST *pNew = NULL;
	int data;
	while (1)
	{
		printf("请输入数据: ");
		scanf("%d", &data);

		if (data == -1)	//输入-1，退出循环
			break;
		pNew = calloc(1, sizeof(SLIST));
		if (pNew == NULL)
		{
			fprintf(stdout, "pNew calloc fail\n");
			break;
		}
		pNew->id = data;	//为新节点数据域赋值
		pCur->next = pNew;	//当前结点的next点指向新节点
		pNew->next = NULL;	//新节点的下一节点指向NULL
		pCur = pNew;	//当前结点移动到新节点位置
	}
	return pHead;
}

void SListPrint(SLIST *pHead) //遍历所有节点
{
	if (pHead == NULL)
	{
		fprintf(stdout, "not found SLIST\n");
		return;
	}
	SLIST *pCur = pHead->next;
	printf("Head->");
	while (pCur)	//判断当前结点不为空
	{
		printf("%d->", pCur->id);
		pCur = pCur->next;
	}
	printf("NULL");
}

// 删除值为x的所有结点
void SListNodeDelPro(SLIST *pHead, int x)
{
	if (pHead == NULL)
	{
		fprintf(stdout, "没有找到值为%d的节点", x);
		return;
	}

	////方法一：
	//SLIST *pCur = pHead;
	//SLIST *pPre = pCur;

	//while (1)
	//{
	//	pPre = pCur;	//每次循环开始；两个指针指向同一个位置
	//	if ((pCur = pCur->next) == NULL)	//判断从头结点开始；如果下一个结点为尾结点（并且更新当前节点信息）
	//		break;
	//	if (pCur->id == x)	//判断出现要删除的节点
	//	{
	//		pPre->next = pCur->next;	//更新节点信息
	//		free(pCur);		//释放当前节点
	//		pCur = pPre;	//更新当前节点信息
	//	}
	//}

	//方法二：
	SLIST *pPre = pHead;		//上一个节点
	SLIST *pCur = pHead->next;	//当前节点
	int flag = 0; //标志位，0代表没有值为x的结点，1代表有

	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			//上一个节点指向当前节点的下一个节点
			pPre->next = pCur->next;
			free(pCur);

			//当前节点往后移动，当前节点指向下一个节点
			//pPre和pCur相差一个节点，pPre为上一个节点，pCur为当前节点
			pCur = pPre->next;

			//标志位，0代表没有值为x的结点，1代表有
			flag = 1;

			//结束本次循环，没有跳出循环，看是否有重复值为x的结点
			continue;
		}

		//保存当前节点
		pPre = pCur;

		//当前节点往后移动，当前节点指向下一个节点
		//pPre和pCur相差一个节点，pPre为上一个节点，pCur为当前节点
		pCur = pCur->next;
	}
	if (flag == 0)//标志位，0代表没有值为x的结点，1代表有
		printf("没有值为%d的结点\n", x);
}

//链表节点排序，交换的是数据域
void SListNodeSort(SLIST *pHead)
{
	if (pHead == NULL)
	{
		fprintf(stdout, "没有创建链表\n");
		return;
	}

	//SLIST *pFst = pHead->next;	//第一个比较的节点
	//while (pFst)
	//{
	//	SLIST *pCur = pFst->next;	//当前比较的节点
	//	while (pFst)	//循环遍历pPre以后的节点
	//	{
	//		if (pCur == NULL)
	//			break;
	//		if (pFst->id > pCur->id)	//升序
	//		{
	//			int tmp = pFst->id;
	//			pFst->id = pCur->id;
	//			pCur->id = tmp;
	//		}
	//		pCur = pCur->next;	//移动当前比较的节点
	//	}
	//	pFst = pFst->next;	//更新第一个比较的节点
	//}

	SLIST *pPre = NULL;
	SLIST *pCur = NULL;
	for (pPre = pHead->next; pPre->next != NULL; pPre = pPre->next)	//选择排序
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

//假如原来链表是升序的,升序插入新节点
//不能插入节点后再排序，是升序插入新节点x
void SListNodeInsertPro(SLIST *pHead, int x)
{
	if (pHead == NULL)
	{
		fprintf(stdout, "not found SLIST\n");
		return;
	}
	SLIST *pPre = pHead;
	SLIST *pCur = pHead->next;
	if (pCur == NULL)
	{
		fprintf(stdout, "链表节点为空（只有头结点）\n");
		return;
	}
	while ( pCur && pCur->id < x)	//判断当前结点的id小于x
	{
		pCur = pCur->next;
		pPre = pPre->next;
	}
	
	//到这里说明当前节点id大于等于x；需要插入新节点(当前节点前面pPre)
	SLIST *pNew = (SLIST *)calloc(1, sizeof(SLIST));		//堆中为新节点分配空间
	if (pNew == NULL)
	{
		fprintf(stdout, "新节点空间分配失败\n");
		return;
	}
	pNew->id = x;
	pPre->next = pNew;	//pPre节点的next指向新节点
	pNew->next = pCur;	//新节点的next指向之前pPre节点的next(pCur)
}

//翻转链表的节点（不是排序，是翻转），交换的是指针域
//例如：原链表为A->B->C->D,使链表逆置成为D->C->B->A
void SListNodeReverse(SLIST *pHead)
{
	if (pHead == NULL)
	{
		fprintf(stdout, "没有创造节点信息\n");
		return;
	}
	
	SLIST *pPre = pHead->next;	//前一个节点
	SLIST *pCur = pPre->next;	//当前节点
	SLIST *tmp = NULL;	//临时节点
	while (pCur)
	{
		tmp = pCur->next;	//保存pCur的next
		pCur->next = pPre;	//改变pCur.next的指向(建立关系)
		pPre = pCur;	//（更新前一个节点位置）移动前一个节点到当前节点

		pCur = tmp;	//更新当前节点的位置
	}

	//确定头结点和尾结点
	//程序执行到这，说明pCur为NULL，pPre为最后一个有效节点
	//而翻转后，pPre为头结点指向的第一个有效节点

	//先确定翻转后的尾结点
	pHead->next->next = NULL;

	//此时pPre指向尾结点
	pHead->next = pPre;
}

void SListDestroy(SLIST *pHead)	//释放所有节点
{
	if (pHead == NULL)	//异常处理
	{
		fprintf(stdout, "未创建链表\n");
		return;
	}
	SLIST *pCur = NULL;		//用来保存当前节点信息

	while (pHead)
	{
		pCur = pHead;
		pHead = pHead->next;	//更新头结点信息
		free(pCur);		//释放当前节点
		pCur = NULL;
	}
}

int main()
{
	SLIST *pHead = NULL;

	pHead = SListCreat(); //创建头结点
	printf("创建头结点后\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeDelPro(pHead, 4);//删除所有值为4的结点
	printf("\n删除所有值为4的结点\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeSort(pHead);//链表节点排序
	printf("\n排序后的链表节点\n");
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
