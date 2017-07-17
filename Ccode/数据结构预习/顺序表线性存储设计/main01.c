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
		线性表线性存储设计
	*/
	/*******************************************************/
	Sql_list *p = (Sql_list *)List_Create(10);	//创建线性表
	srand(time(NULL));	//置随机数种子
	int k;
	for (int i = 0; i < p->Cay; ++i)	//插入所有元素
	{
		k = rand() % 100;
		List_Insert(p, &k, i);
	}
	
	int *n = NULL;
	for (int i = 0; i < p->len; ++i)	//遍历所有元素
	{
		n = List_Get(p, i);
		if(n)
			printf("%d->", *n);
	}
	printf("\b\b\t");

	if(List_Delete(p, 3));	//删除线性表3号位置的数值
	{
		printf("删除3号位置后的线性表为: \n");
		for (int i = 0; i < p->len; ++i)	//遍历所有元素
		{
			n = List_Get(p, i);
			if (n)
				printf("%d->", *n);
		}
		printf("\b\b\t\t\n");
	}

	n = List_Get(p, 7);	//获取线性表7号位置的数值
	printf("当前线性表7号位置的数值位：%d\n", *n);

	//清空线性表
	if (List_Clear(p))
	{
		printf("线性表清空成功\n");
		n = List_Get(p, 1);	//获取线性表1号位置的数值
		if (n)
			printf("%d", *n);
	}

	//销毁线性表
	List_Destroy(p);
	p = NULL;
	printf("\n");
	system("pause");
	return 0;
}
