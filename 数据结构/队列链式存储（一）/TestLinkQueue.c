#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkQueue.h"

typedef struct Person
{
	char name[64];
	int age;
}Person;

void test()
{
	LQueue *queue = NULL;
	//创建队列
	int ret = Init_LinkQueue(&queue);

	if (0 == ret)
	{
		printf("队列创建成功\n");
	}

	//创建数据
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };
	Person p4 = { "ddd", 40 };
	Person p5 = { "eee", 50 };
	Person p6 = { "fff", 60 };

	//入队
	Push_LinkQueue(queue, &p1);
	Push_LinkQueue(queue, &p2);
	Push_LinkQueue(queue, &p3);
	Push_LinkQueue(queue, &p4);
	Push_LinkQueue(queue, &p5);
	Push_LinkQueue(queue, &p6);
	

	Person *p = Back_LinkQueue(queue);	//获取队尾元素
	printf("队尾元素为：Name = %s, Age = %d\n", p->name, p->age);

	p = Front_LinkQueue(queue);
	printf("队头元素为：Name = %s, Age = %d\n", p->name, p->age);

	int size = Size_LinkQueue(queue);	//获取队列元素个数
	printf("队列元素个数：%d\n", size);

	//队列出队
	ret = Pop_LinkQueue(queue);
	if (0 == ret)
	{
		printf("队列出队成功\n");
	}
	
	size = Size_LinkQueue(queue);	//获取队列元素个数
	printf("当前队列元素个数为：%d\n",size);

	//销毁队列
	ret = Destroy_LinkQueue(queue);
	if (0 == ret)
	{
		printf("队列销毁成功\n");
	}
}

int main(void)
{
	/*******************************************************/
	/*
		队列测试
	*/
	/*******************************************************/
	test();

	printf("\n");
	system("pause");
	return 0;
}
