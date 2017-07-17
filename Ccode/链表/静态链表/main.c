#include<stdio.h>
#include<stdlib.h>

typedef struct Stu
{
	int id;	//数据域
	char name[100];

	struct Stu *next;	//指针域
}Stu;

int main()
{
	/*************************************************************/
	/*
		静态链表和动态链表是线性表链式存储结构的两种不同的表示方式：
		所有结点都是在程序中定义的，不是临时开辟的;
		也不能用完后释放，这种链表称为“静态链表”。
	*/
	/*************************************************************/
	
	//初始化三个结构体变量
	Stu s1 = {1, "yuri", NULL};
	Stu s2 = {2, "lily", NULL};
	Stu s3 = {3, "lilei", NULL};

	s1.next = &s2;	//s1的next指针指向s2
	s2.next = &s3;
	s3.next = NULL;	//尾结点

	Stu *p = &s1;
	while (p != NULL)
	{
		printf("id = %d, name = %s\n", p->id, p->name);

		//结点往后移动一位
		p = p->next;
	}
	system("pause");
	return 0;
}

