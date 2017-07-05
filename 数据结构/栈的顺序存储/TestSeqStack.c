#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"

typedef struct Person
{
	char name[64];
	int age;
}Person;

void test()
{
	//创建栈
	SeqStack *stack = (SeqStack *)Init_SeqStack();

	//创建数据
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };

	//数据入栈
	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);

	//输出栈中所有元素
	while (Size_SeqStack(stack) > 0)
	{
		//先获取栈顶元素
		Person *person = (Person *)Top_SeqStack(stack);
		printf("name = %s, age = %d\n", person->name, person->age);
		//弹出栈顶元素
		Pop_SeqStack(stack);
	}

	//销毁栈
	Destroy_SeqStack(stack);

}

int IsLeft(char ch)	//判断是否为左括号
{
	return ch == '(';
}

int IsRight(char ch)	//判断是否为右括号
{
	return ch == ')';
}

void printError(const char *str, char *p)
{
	printf("%s\n", str);
	//计算连个字符之间相隔的个数
	int dis = p - str;
	for (int i = 0; i < dis; ++i)
	{
		printf(" ");
	}
	printf("A\n");
}

void test2()	//栈的应用--就近匹配
{
	/*
		实现编译器中的符号成对检测
		5+5*(6)+9/3*1)-(1+3(
	*/
	const char *str = "5+5*(6)+9/3*1)-(1+3(";
	char *p = (char *)str;
	//创建栈
	SeqStack *stack = Init_SeqStack();
	while (*p != NULL)
	{
		if (IsLeft(*p))	//检查是左括号
		{
			Push_SeqStack(stack, p);	//元素入栈
		}
		
		if (IsRight(*p))	//检查是右括号
		{
			//判断栈是否为空，为空说明当前右括号没有匹配的左括号
			if (0 == Size_SeqStack(stack))
			{
				//printf("没有匹配的左括号!\n");
				printError(str, p);
			}
			else
			{
				Pop_SeqStack(stack);	//左括号出栈
			}
		}

		++p;
	}

	//判断栈是否为空；不为空说明里面全是左括号
	while(Size_SeqStack(stack) > 0)
	{
		//先获取栈顶元素
		p = (char *)Top_SeqStack(stack);
		printError(str, p);

		//栈顶元素出栈
		Pop_SeqStack(stack);
	}
}

int main(void)
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	test();
	test2();

	printf("\n");
	system("pause");
	return 0;
}
