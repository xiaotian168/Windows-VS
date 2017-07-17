#pragma once


typedef struct Node
{
	int id;		//������
	struct Node *next;	//ָ����
}SLIST;

SLIST *SListCreat(); //����ͷ���

void SListPrint(SLIST *pHead); //�������нڵ�

void SListNodeDelPro(SLIST *pHead, int n);//ɾ������ֵΪ4�Ľ��

void SListNodeSort(SLIST *pHead);//����ڵ�����

void SListNodeInsertPro(SLIST *pHead, int n);//�������5

//��ת����Ľڵ㣨���������Ƿ�ת��
void SListNodeReverse(SLIST *pHead);

void SListDestroy(SLIST *pHead);//�ͷ����нڵ�
