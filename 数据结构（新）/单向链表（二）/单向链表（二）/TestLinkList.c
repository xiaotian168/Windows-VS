#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

/*
用户定义数据
*/

//用户使用链表二,必须在数据首地址的位置包含链表节点
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

	//初始化链表
	struct LinkList *list = Init_LinkList();

	//初始化节点数据
	Person p1 = { NULL, "aaa", 10 };
	Person p2 = { NULL, "bbb", 20 };
	Person p3 = { NULL, "ccc", 30 };
	Person p6 = { NULL, "ggg", 60 };
	Person p5 = { NULL, "eee", 50 };
	Person p4 = { NULL, "ddd", 40 };

	//插入节点数据
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p6);
	Insert_LinkList(list, 0, &p5);
	Insert_LinkList(list, 0, &p4);
	//遍历链表
	Foreach_LinkList(list, myPrint);

	//链表翻转
	Inverted_LinkList(list);
	printf("逆序后的链表为: \n");
	Foreach_LinkList(list, myPrint);	//遍历链表

	Sort_LinkList(list, myCompare);
	printf("排序后的链表为: \n");
	Foreach_LinkList(list, myPrint);	//遍历链表

	////链表翻转
	Inverted_LinkList(list);
	printf("逆序后的链表为: \n");
	Foreach_LinkList(list, myPrint);	//遍历链表
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
