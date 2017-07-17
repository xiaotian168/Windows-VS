#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "list.h"

int main(void)
{
	/*******************************************************/
	/*
		���Ա����Դ洢���
	*/
	/*******************************************************/
	Sql_list *p = (Sql_list *)List_Create(10);	//�������Ա�
	srand(time(NULL));	//�����������
	int k;
	for (int i = 0; i < p->Cay; ++i)	//��������Ԫ��
	{
		k = rand() % 100;
		List_Insert(p, &k, i);
	}
	
	int *n = NULL;
	for (int i = 0; i < p->len; ++i)	//��������Ԫ��
	{
		n = List_Get(p, i);
		if(n)
			printf("%d->", *n);
	}
	printf("\b\b\t");

	if(List_Delete(p, 3));	//ɾ�����Ա�3��λ�õ���ֵ
	{
		printf("ɾ��3��λ�ú�����Ա�Ϊ: \n");
		for (int i = 0; i < p->len; ++i)	//��������Ԫ��
		{
			n = List_Get(p, i);
			if (n)
				printf("%d->", *n);
		}
		printf("\b\b\t\t\n");
	}

	n = List_Get(p, 7);	//��ȡ���Ա�7��λ�õ���ֵ
	printf("��ǰ���Ա�7��λ�õ���ֵλ��%d\n", *n);

	//������Ա�
	if (List_Clear(p))
	{
		printf("���Ա���ճɹ�\n");
		n = List_Get(p, 1);	//��ȡ���Ա�1��λ�õ���ֵ
		if (n)
			printf("%d", *n);
	}

	//�������Ա�
	List_Destroy(p);
	p = NULL;
	printf("\n");
	system("pause");
	return 0;
}
