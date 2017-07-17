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
	//����ջ
	LinkStack *stack = Init_LinkStack();

	//��������
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };

	//Ԫ����ջ
	Push_LinkStack(stack, &p1);
	Push_LinkStack(stack, &p2);
	Push_LinkStack(stack, &p3);

	//���ջ��Ԫ�ظ���
	printf("%d\n", Size_LinkStack(stack));

	//���ջ������Ԫ��
	while (Size_LinkStack(stack) > 0)
	{
		//�Ȼ�ȡջ��Ԫ��
		Person *person = (Person *)Top_LinkStack(stack);
		printf("name = %s, age = %d\n", person->name, person->age);
		//����ջ��Ԫ��
		Pop_LinkStack(stack);
	}

	//����ջ
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
