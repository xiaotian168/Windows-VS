#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int id;		//������
	struct Node *next;	//ָ����
}SLIST;

SLIST *SListCreat() //����ͷ���
{
	SLIST *pHead = calloc(1, sizeof(SLIST));
	if (pHead == NULL)	//�쳣����
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
		printf("����������: ");
		scanf("%d", &data);

		if (data == -1)	//����-1���˳�ѭ��
			break;
		pNew = calloc(1, sizeof(SLIST));
		if (pNew == NULL)
		{
			fprintf(stdout, "pNew calloc fail\n");
			break;
		}
		pNew->id = data;	//Ϊ�½ڵ�������ֵ
		pCur->next = pNew;	//��ǰ����next��ָ���½ڵ�
		pNew->next = NULL;	//�½ڵ����һ�ڵ�ָ��NULL
		pCur = pNew;	//��ǰ����ƶ����½ڵ�λ��
	}
	return pHead;
}

void SListPrint(SLIST *pHead) //�������нڵ�
{
	if (pHead == NULL)
	{
		fprintf(stdout, "not found SLIST\n");
		return;
	}
	SLIST *pCur = pHead->next;
	printf("Head->");
	while (pCur)	//�жϵ�ǰ��㲻Ϊ��
	{
		printf("%d->", pCur->id);
		pCur = pCur->next;
	}
	printf("NULL");
}

// ɾ��ֵΪx�����н��
void SListNodeDelPro(SLIST *pHead, int x)
{
	if (pHead == NULL)
	{
		fprintf(stdout, "û���ҵ�ֵΪ%d�Ľڵ�", x);
		return;
	}

	////����һ��
	//SLIST *pCur = pHead;
	//SLIST *pPre = pCur;

	//while (1)
	//{
	//	pPre = pCur;	//ÿ��ѭ����ʼ������ָ��ָ��ͬһ��λ��
	//	if ((pCur = pCur->next) == NULL)	//�жϴ�ͷ��㿪ʼ�������һ�����Ϊβ��㣨���Ҹ��µ�ǰ�ڵ���Ϣ��
	//		break;
	//	if (pCur->id == x)	//�жϳ���Ҫɾ���Ľڵ�
	//	{
	//		pPre->next = pCur->next;	//���½ڵ���Ϣ
	//		free(pCur);		//�ͷŵ�ǰ�ڵ�
	//		pCur = pPre;	//���µ�ǰ�ڵ���Ϣ
	//	}
	//}

	//��������
	SLIST *pPre = pHead;		//��һ���ڵ�
	SLIST *pCur = pHead->next;	//��ǰ�ڵ�
	int flag = 0; //��־λ��0����û��ֵΪx�Ľ�㣬1������

	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			//��һ���ڵ�ָ��ǰ�ڵ����һ���ڵ�
			pPre->next = pCur->next;
			free(pCur);

			//��ǰ�ڵ������ƶ�����ǰ�ڵ�ָ����һ���ڵ�
			//pPre��pCur���һ���ڵ㣬pPreΪ��һ���ڵ㣬pCurΪ��ǰ�ڵ�
			pCur = pPre->next;

			//��־λ��0����û��ֵΪx�Ľ�㣬1������
			flag = 1;

			//��������ѭ����û������ѭ�������Ƿ����ظ�ֵΪx�Ľ��
			continue;
		}

		//���浱ǰ�ڵ�
		pPre = pCur;

		//��ǰ�ڵ������ƶ�����ǰ�ڵ�ָ����һ���ڵ�
		//pPre��pCur���һ���ڵ㣬pPreΪ��һ���ڵ㣬pCurΪ��ǰ�ڵ�
		pCur = pCur->next;
	}
	if (flag == 0)//��־λ��0����û��ֵΪx�Ľ�㣬1������
		printf("û��ֵΪ%d�Ľ��\n", x);
}

//����ڵ����򣬽�������������
void SListNodeSort(SLIST *pHead)
{
	if (pHead == NULL)
	{
		fprintf(stdout, "û�д�������\n");
		return;
	}

	//SLIST *pFst = pHead->next;	//��һ���ȽϵĽڵ�
	//while (pFst)
	//{
	//	SLIST *pCur = pFst->next;	//��ǰ�ȽϵĽڵ�
	//	while (pFst)	//ѭ������pPre�Ժ�Ľڵ�
	//	{
	//		if (pCur == NULL)
	//			break;
	//		if (pFst->id > pCur->id)	//����
	//		{
	//			int tmp = pFst->id;
	//			pFst->id = pCur->id;
	//			pCur->id = tmp;
	//		}
	//		pCur = pCur->next;	//�ƶ���ǰ�ȽϵĽڵ�
	//	}
	//	pFst = pFst->next;	//���µ�һ���ȽϵĽڵ�
	//}

	SLIST *pPre = NULL;
	SLIST *pCur = NULL;
	for (pPre = pHead->next; pPre->next != NULL; pPre = pPre->next)	//ѡ������
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

//����ԭ�������������,��������½ڵ�
//���ܲ���ڵ������������������½ڵ�x
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
		fprintf(stdout, "����ڵ�Ϊ�գ�ֻ��ͷ��㣩\n");
		return;
	}
	while ( pCur && pCur->id < x)	//�жϵ�ǰ����idС��x
	{
		pCur = pCur->next;
		pPre = pPre->next;
	}
	
	//������˵����ǰ�ڵ�id���ڵ���x����Ҫ�����½ڵ�(��ǰ�ڵ�ǰ��pPre)
	SLIST *pNew = (SLIST *)calloc(1, sizeof(SLIST));		//����Ϊ�½ڵ����ռ�
	if (pNew == NULL)
	{
		fprintf(stdout, "�½ڵ�ռ����ʧ��\n");
		return;
	}
	pNew->id = x;
	pPre->next = pNew;	//pPre�ڵ��nextָ���½ڵ�
	pNew->next = pCur;	//�½ڵ��nextָ��֮ǰpPre�ڵ��next(pCur)
}

//��ת����Ľڵ㣨���������Ƿ�ת������������ָ����
//���磺ԭ����ΪA->B->C->D,ʹ�������ó�ΪD->C->B->A
void SListNodeReverse(SLIST *pHead)
{
	if (pHead == NULL)
	{
		fprintf(stdout, "û�д���ڵ���Ϣ\n");
		return;
	}
	
	SLIST *pPre = pHead->next;	//ǰһ���ڵ�
	SLIST *pCur = pPre->next;	//��ǰ�ڵ�
	SLIST *tmp = NULL;	//��ʱ�ڵ�
	while (pCur)
	{
		tmp = pCur->next;	//����pCur��next
		pCur->next = pPre;	//�ı�pCur.next��ָ��(������ϵ)
		pPre = pCur;	//������ǰһ���ڵ�λ�ã��ƶ�ǰһ���ڵ㵽��ǰ�ڵ�

		pCur = tmp;	//���µ�ǰ�ڵ��λ��
	}

	//ȷ��ͷ����β���
	//����ִ�е��⣬˵��pCurΪNULL��pPreΪ���һ����Ч�ڵ�
	//����ת��pPreΪͷ���ָ��ĵ�һ����Ч�ڵ�

	//��ȷ����ת���β���
	pHead->next->next = NULL;

	//��ʱpPreָ��β���
	pHead->next = pPre;
}

void SListDestroy(SLIST *pHead)	//�ͷ����нڵ�
{
	if (pHead == NULL)	//�쳣����
	{
		fprintf(stdout, "δ��������\n");
		return;
	}
	SLIST *pCur = NULL;		//�������浱ǰ�ڵ���Ϣ

	while (pHead)
	{
		pCur = pHead;
		pHead = pHead->next;	//����ͷ�����Ϣ
		free(pCur);		//�ͷŵ�ǰ�ڵ�
		pCur = NULL;
	}
}

int main()
{
	SLIST *pHead = NULL;

	pHead = SListCreat(); //����ͷ���
	printf("����ͷ����\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeDelPro(pHead, 4);//ɾ������ֵΪ4�Ľ��
	printf("\nɾ������ֵΪ4�Ľ��\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeSort(pHead);//����ڵ�����
	printf("\n����������ڵ�\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeInsertPro(pHead, 5);//�������5
	printf("\n�������5��\n");
	SListPrint(pHead); //�������нڵ�

	//��ת����Ľڵ㣨���������Ƿ�ת��
	SListNodeReverse(pHead);
	printf("\n��ת����Ľڵ�\n");
	SListPrint(pHead); //�������нڵ�

	SListDestroy(pHead);//�ͷ����нڵ�
	pHead = NULL;

	printf("\n");
	system("pause");
	return 0;
}
