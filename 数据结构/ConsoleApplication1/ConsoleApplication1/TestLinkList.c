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
	Person *person = (Person *)data;
	printf("name = %s, age = %d\n", person->name, person->age);
}

void test()
{

	//��ʼ������
	struct LinkList *list = Init_LinkList();

	//��ʼ���ڵ�����
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };

	//����ڵ�����
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	//��������
	Foreach_LinkList(list, myPrint);

	//����ת
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
	return 0;
}
