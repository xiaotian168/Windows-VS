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

int valFound(void *data, void *my_data)
{
	//接收节点数据
	struct Person *person = (struct Person *)data;

	int *n = (int *)my_data;

	if (person->age == *n)	//找到特定的值
	{
		return 0;
	}
	return -1;
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

	Foreach_LinkList(list, myPrint);

	//删除数据
	Remove_LinkList(list, 0);
	printf("-------------\n");
	Foreach_LinkList(list, myPrint);
	Remove_LinkList(list, Size_LinkList(list) - 1 );
	printf("-------------\n");
 	Foreach_LinkList(list, myPrint);

	//查找指定数据（按年龄查找）
	int n = 30;
	struct Person *node = (struct Person *)Get_Value(list, valFound, &n);
	printf(node->name);
	printf("\n");

	//逆序打印链表
	printf("逆序打印为\n");
	print_LinkList(list, myPrint);

	//销毁链表
	Destroy_LinkList(list);
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}