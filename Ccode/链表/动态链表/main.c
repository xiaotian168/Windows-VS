#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "list.h"

typedef struct Stu
{
	int id;	//������
	char name[100];

	struct Stu *next;	//ָ����
}Stu;

int main01()
{
	/**********************************************************/
	/*
		��̬������ָ�ڳ���ִ�й����д��޵��еؽ�����һ������
		��һ��һ���ؿ��ٽ��������������ݣ���������ǰ��
	*/
	/**********************************************************/

	//��̬����3���ڵ�
	Stu *s1 = (Stu *)malloc(sizeof(Stu));
	s1->id = 1;
	strcpy(s1->name, "yuri");

	Stu *s2 = (Stu *)malloc(sizeof(Stu));
	s2->id = 2;
	strcpy(s2->name, "lily");

	Stu *s3 = (Stu *)malloc(sizeof(Stu));
	s3->id = 3;
	strcpy(s3->name, "lilei");

	//�����ڵ�Ĺ�ϵ
	s1->next = s2;	//s1��nextָ��ָ��s2
	s2->next = s3;
	s3->next = NULL;	//β���

	//�������
	Stu *p = s1;
	while (p != NULL)
	{
		printf("id = %d, name = %s\n", p->id, p->name);

		//�ڵ������ƶ�һλ
		p = p->next;
	}

	//�ͷŽڵ�ռ�
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
		����̬�����������
	*/
	/*******************************************************/
	SLIST *pHead = NULL;

	pHead = SListCreat(); //����ͷ���
	printf("\n����ͷ����\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeDelPro(pHead, 4);//ɾ������ֵΪ4�Ľ��
	printf("\nɾ������ֵΪ4�Ľ��\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeSort(pHead);//����ڵ�����
	printf("\n����ڵ�����\n");
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
