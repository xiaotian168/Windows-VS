﻿#include<stdio.h>
#include<stdlib.h>

typedef struct Stu
{
	int id;		//数据域
	char name[100];

	struct Stu *next;	//指针域
}Stu;

int main()
{
	/*************************************************************/
	/*
		链表：无需一次性分配一块连续的存储区域，
		只需分配n块节点存储区域，通过指针建立关系。
		优点：1) 不需要一块连续的存储区域
			  2) 删除和插入某个元素效率高
		缺点：随机访问元素效率低

		链表的节点实际上是结构体变量，此结构体包含数据域和指针域：
		数据域:用来存储数据
		指针域:用于建立与下一个结点的联系，
			   当此节点为尾节点时，指针域的值为NULL
	*/
	/************************************************************/



	system("pause");
	return 0;
}