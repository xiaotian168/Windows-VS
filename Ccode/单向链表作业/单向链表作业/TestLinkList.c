#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkList.h"

struct Person
{
	char name[64];
	int age;
};

void myPrint(void* data)
{
	struct Person *person = (struct Person *)data;
	printf("Name:%s Age:%d\n", person->name, person->age);
}

bool myCompare(void *d1,void *d2)
{
	struct Person *p1 = (struct Person *)d1;
	struct Person *p2 = (struct Person *)d2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test()
{

	//测试数据
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };
	struct Person p6 = { "fff", 60 };

	//创建链表
	LinkList list = Init_LinkList();

	//插入数据
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	Insert_LinkList(list, 0, &p6);

	printf("--------------------\n");
	struct Person p7 = { "fff", 60 };
	//struct Person p7 = { "fff", 60 };
	struct Person *ret = (struct Person *)Search_LinkList(list, &p7, myCompare);
	if (ret != NULL)
	{
		printf("ret -> Name:%s Age:%d\n", ret->name, ret->age);
	}

	ReverseForeach_LinkList(list, myPrint);

	printf("--------------------\n");

	Foreach_LinkList(list, myPrint);

	//删除数据
	Remove_LinkList(list, 0);
	printf("-------------\n");
	Foreach_LinkList(list, myPrint);
	Remove_LinkList(list, Size_LinkList(list) - 1 );
	printf("-------------\n");
	Foreach_LinkList(list, myPrint);

	//销毁链表
	Destroy_LinkList(list);
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}