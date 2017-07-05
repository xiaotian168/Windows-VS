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
	//����ջ
	SeqStack *stack = (SeqStack *)Init_SeqStack();

	//��������
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };

	//������ջ
	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);

	//���ջ������Ԫ��
	while (Size_SeqStack(stack) > 0)
	{
		//�Ȼ�ȡջ��Ԫ��
		Person *person = (Person *)Top_SeqStack(stack);
		printf("name = %s, age = %d\n", person->name, person->age);
		//����ջ��Ԫ��
		Pop_SeqStack(stack);
	}

	//����ջ
	Destroy_SeqStack(stack);

}

int IsLeft(char ch)	//�ж��Ƿ�Ϊ������
{
	return ch == '(';
}

int IsRight(char ch)	//�ж��Ƿ�Ϊ������
{
	return ch == ')';
}

void printError(const char *str, char *p)
{
	printf("%s\n", str);
	//���������ַ�֮������ĸ���
	int dis = p - str;
	for (int i = 0; i < dis; ++i)
	{
		printf(" ");
	}
	printf("A\n");
}

void test2()	//ջ��Ӧ��--�ͽ�ƥ��
{
	/*
		ʵ�ֱ������еķ��ųɶԼ��
		5+5*(6)+9/3*1)-(1+3(
	*/
	const char *str = "5+5*(6)+9/3*1)-(1+3(";
	char *p = (char *)str;
	//����ջ
	SeqStack *stack = Init_SeqStack();
	while (*p != NULL)
	{
		if (IsLeft(*p))	//�����������
		{
			Push_SeqStack(stack, p);	//Ԫ����ջ
		}
		
		if (IsRight(*p))	//�����������
		{
			//�ж�ջ�Ƿ�Ϊ�գ�Ϊ��˵����ǰ������û��ƥ���������
			if (0 == Size_SeqStack(stack))
			{
				//printf("û��ƥ���������!\n");
				printError(str, p);
			}
			else
			{
				Pop_SeqStack(stack);	//�����ų�ջ
			}
		}

		++p;
	}

	//�ж�ջ�Ƿ�Ϊ�գ���Ϊ��˵������ȫ��������
	while(Size_SeqStack(stack) > 0)
	{
		//�Ȼ�ȡջ��Ԫ��
		p = (char *)Top_SeqStack(stack);
		printError(str, p);

		//ջ��Ԫ�س�ջ
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
