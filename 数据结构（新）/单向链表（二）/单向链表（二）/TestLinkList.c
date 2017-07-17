#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

/*
�û���������
*/

//�û�ʹ�������,�����������׵�ַ��λ�ð�������ڵ�
typedef struct Person
{
	struct LinkNode node;
	char name[64];
	int age;
}Person;

void myPrint(void *data)
{
	if (NULL == data)
	{
		return;
	}
	Person *person = (Person *)data;
	printf("name = %s, age = %d\n", person->name, person->age);
}

int myCompare(void *d1, void *d2)
{
	if (NULL == d1)
	{
		return -2;
	}

	if (NULL == d2)
	{
		return -3;
	}

	Person *p1 = (Person *)d1;
	Person *p2 = (Person *)d2;
	if (p1->age > p2->age)
	{
		return 1;
	}
	else if (p1->age == p2->age)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void test()
{

	//��ʼ������
	struct LinkList *list = Init_LinkList();

	//��ʼ���ڵ�����
	Person p1 = { NULL, "aaa", 10 };
	Person p2 = { NULL, "bbb", 20 };
	Person p3 = { NULL, "ccc", 30 };
	Person p6 = { NULL, "ggg", 60 };
	Person p5 = { NULL, "eee", 50 };
	Person p4 = { NULL, "ddd", 40 };

	//����ڵ�����
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p6);
	Insert_LinkList(list, 0, &p5);
	Insert_LinkList(list, 0, &p4);
	//��������
	Foreach_LinkList(list, myPrint);

	//����ת
	Inverted_LinkList(list);
	printf("����������Ϊ: \n");
	Foreach_LinkList(list, myPrint);	//��������

	Sort_LinkList(list, myCompare);
	printf("����������Ϊ: \n");
	Foreach_LinkList(list, myPrint);	//��������

	////����ת
	Inverted_LinkList(list);
	printf("����������Ϊ: \n");
	Foreach_LinkList(list, myPrint);	//��������
}

int main(void)
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	test();

	printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}
