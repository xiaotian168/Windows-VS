#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

typedef struct Person
{
	char name[64];
	int age;
}Person;

void test()
{
	//创建栈
	LinkStack *stack = Init_LinkStack();

	//创建数据
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };

	//元素入栈
	Push_LinkStack(stack, &p1);
	Push_LinkStack(stack, &p2);
	Push_LinkStack(stack, &p3);

	//输出栈中元素个数
	printf("%d\n", Size_LinkStack(stack));

	//输出栈中所有元素
	while (Size_LinkStack(stack) > 0)
	{
		//先获取栈顶元素
		Person *person = (Person *)Top_LinkStack(stack);
		printf("name = %s, age = %d\n", person->name, person->age);
		//弹出栈顶元素
		Pop_LinkStack(stack);
	}

	//销毁栈
	Destroy_LinkStack(stack);
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
