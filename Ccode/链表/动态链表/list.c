#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include "list.h"
//#pragma warning(disable:4996)

SLIST *SListCreat() //����ͷ���
{
	SLIST *head = (SLIST *)calloc(1, sizeof(SLIST));	//Ϊͷ������ռ�
	if (head == NULL)
	{
		fprintf(stdout, "headͷ��㴴��ʧ��\n");
		return NULL;
	}
	head->id = -1;	//ͷ������ݲ�ʹ�ã������⸳ֵ
	head->next = NULL;

	SLIST *pNew = NULL;		//�½ڵ�
	SLIST *pCur = head;	//��ǰ�ڵ�

	int n;
	while(1)
	{
		printf("������ڵ����ݣ�");
		scanf("%d", &n);	//��������
		if (n == -1)	//-1��Ϊ������־
			break;
		pNew = (SLIST *)calloc(1, sizeof(SLIST));	//Ϊ�½ڵ����ռ�
		if (pNew == NULL)
			continue;
		pNew->id = n;	//��ֵ
		pNew->next = NULL;

		pCur->next = pNew;	//�����ڵ��ϵ
		pCur = pNew;	//���µ�ǰ���λ��
	}
	return head;
}

void SListPrint(SLIST *pHead) //�������нڵ�
{
	if (pHead == NULL)	//�쳣����
	{
		fprintf(stdout, "pHead == NULL\n");
		return;
	}

	//����һ����һ������ָ��
	//SLIST *pCur = pHead->next;	//��ǰ�ڵ�
	//printf("Head->");
	//while (pCur)
	//{
	//	printf("%d->", pCur->id);
	//	pCur = pCur->next;
	//}
	//printf("NULL");

	//��������ֱ��ʹ��ͷ����������
	printf("Head->");
	while (pHead->next)
	{
		printf("%d->", pHead->next->id);
		pHead = pHead->next;
	}
	printf("NULL");
}

void SListNodeDelPro(SLIST *pHead, int n)//ɾ������ֵΪ4�Ľ��
{
	if (pHead == NULL)	//�쳣����
	{
		fprintf(stdout, "δ��������\n");
		return;
	}

	SLIST *pPre = pHead;
	SLIST *pCur = pHead->next;
	while (pCur)
	{
		if (pCur->id == n)	//�жϳ���ֵΪn�Ľڵ�
		{
			pPre->next = pCur->next;	//��һ���ڵ����һ���ڵ�ָ��ǰ�ڵ����һ���ڵ�
			free(pCur);		//�ͷŵ�ǰ�ڵ�
			pCur = pPre->next;	//���µ�ǰ�ڵ�λ��
			continue;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}

}

void SListNodeSort(SLIST *pHead)//����ڵ�����
{
	if (pHead == NULL || pHead->next == NULL)	//�쳣����
	{
		fprintf(stdout, "����ֻ��һ����Ч�ڵ�\n");
		return;
	}

	SLIST *pPre = NULL;	//����׽ڵ�
	SLIST *pCur = NULL;	//�����׽ڵ����һ���ڵ�
	for (pPre = pHead->next; pPre->next != NULL; pPre = pPre->next)		//ѡ������
	{
		for (pCur = pPre->next; pCur != NULL; pCur = pCur->next)
		{
			if (pPre->id > pCur->id)	//����
			{
				SLIST tmp = *pPre;
				*pPre = *pCur;
				*pCur = tmp;

				//����ָ����
				tmp.next = pPre->next;
				pPre->next = pCur->next;
				pCur->next = tmp.next;
			}
		}
	}
}

void SListNodeInsertPro(SLIST *pHead, int n)//�������5
{
	if (pHead == NULL)	//�쳣����
	{
		fprintf(stdout, "δ��������\n");
		return;
	}

	SLIST *pPre = pHead;	//ͷ�ڵ�
	SLIST *pCur = pPre->next;	//��һ���ڵ�
	while (pCur)
	{
		if (pCur->id > n)	//�ҵ������
		{
			break;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}
	//�½ڵ����ռ�
	SLIST *pNew = (SLIST *)calloc(1, sizeof(SLIST));
	if (pNew == NULL)
	{
		fprintf(stdout, "�²���ڵ�ռ����ʧ��\n");
		return;
	}
	pNew->id = n;	//�½ڵ㸳ֵ
	
	//����ִ�е��⣬��2�����
	//1. �ҵ�ƥ��ڵ㣬pCurΪ��ǰƥ��ڵ㣬pPreΪ��һ���ڵ�
	//2. û���ҵ�ƥ��ڵ㣬�ڵ��ƶ�����β��pPreΪ���һ���ڵ㣬pCurΪNULL
	pPre->next = pNew;
	pNew->next = pCur;
}

//��ת����Ľڵ㣨���������Ƿ�ת��
void SListNodeReverse(SLIST *pHead)
{
	if (pHead == NULL || pHead->next == NULL || pHead->next->next == NULL)	//�쳣����
	{
		fprintf(stdout, "pHead == NULL || pHead->next || pHead->next->next == NULL\n");
		return;
	}

	SLIST *pPre = pHead->next;
	SLIST *pCur = pPre->next;
	SLIST *tmp = NULL;
	while (pCur)
	{
		tmp = pCur->next;	//���浱ǰ�ڵ��next
		pCur->next = pPre;	//�õ�ǰ�ڵ�ָ��ǰһ���ڵ�
		pPre = pCur;	//ǰһ���ڵ��ƶ�����ǰ�ڵ�
		pCur = tmp;	//��ǰ�ڵ��ƶ�����һ���ڵ�
	}

	//�ȱ���β�ڵ�
	pHead->next->next = NULL;
	//ͷ����������׽ڵ�
	pHead->next = pPre;
}

void SListDestroy(SLIST *pHead) //�ͷ����нڵ�
{
	if (pHead == NULL)	//�쳣����
	{
		fprintf(stdout, "δ��������\n");
		return;
	}
	
	SLIST *pCur = NULL;
	while (pHead)
	{
		pCur = pHead->next;	//����ͷ�ڵ����һ���ڵ���Ϣ
		free(pHead);	//�ͷ�ͷ���
		pHead = pCur;	//ͷ����ƶ�����һ���ڵ�
	}
}
