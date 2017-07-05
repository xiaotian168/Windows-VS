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
	Person *person = (Person *)data;
	printf("name = %s, age = %d\n", person->name, person->age);
}

void test()
{

	//初始化链表
	struct LinkList *list = Init_LinkList();

	//初始化节点数据
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };

	//插入节点数据
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	//遍历链表
	Foreach_LinkList(list, myPrint);

	//链表翻转
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
	return 0;
}
