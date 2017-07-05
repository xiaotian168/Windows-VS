#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"DynamicArray.h"

struct Person
{
	char name[64];
	int age;
};

//��ʼ��ջ
SeqStack Init_Stack()
{
	return Init_DynamicArray();
}

//��ջ
void Push_SeqStack(SeqStack stack, void *data)
{
	if (NULL == stack)
	{
		return;
	}
	
	if (NULL == data)
	{
		return;
	}
	struct DArray *arr = (struct DArray *)stack;
	int pos = arr->size;
	Insert_DynamicArray(arr, pos, data);	//ÿ�δӶ�̬����������Ԫ��

}

//��ջ
void Pop_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	struct DArray *arr = (struct DArray *)stack;
	int pos = arr->size;
	Remove_DynamicArray(arr, pos-1);	//ÿ�δӶ�̬�������ɾ��Ԫ��

}

//��ȡջ��Ԫ��
void *Top_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return NULL;
	}

	struct DArray *arr = (struct DArray *)stack;
	int pos = arr->size;

	return Get_DynamicArray(arr, pos - 1);
}

//��ȡջ��Ԫ�ظ���
int Size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	struct DArray *arr = (struct DArray *)stack;
	return arr->size;
}

//����ջ
void Destroy_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	struct DArray *arr = (struct DArray *)stack;
	Destroy_DynamicArray(arr);
}

void test2()
{
	//��ʼ��ջ
	SeqStack stack = Init_Stack();

	//��������
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };
	struct Person p6 = { "fff", 60 };

	//��ջ
	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);

	//��ȡջ��Ԫ�ظ���
	printf("��ǰջ��Ԫ�ظ�����%d\n", Size_SeqStack(stack));

	//��ȡջ��Ԫ��
	struct Person *person = (struct Person *)Top_SeqStack(stack);
	printf("%s, %d\n", person->name, person->age);

	//��ջ
	Pop_SeqStack(stack);
	printf("��ջ��Ԫ�ظ�����%d\n", Size_SeqStack(stack));

	//��ȡջ��Ԫ��
	person = (struct Person *)Top_SeqStack(stack);
	printf("%s, %d\n", person->name, person->age);

}

void myPrint(void* data)
{
	struct Person *person = (struct Person *)data;
	printf("Name:%s Age:%d\n", person->name, person->age);
}

void test()
{

	//��ʼ������
	struct DArray *arr = Init_DynamicArray();

	//��������
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };
	struct Person p6 = { "fff", 60 };

	//�������в�������
	Insert_DynamicArray(arr, 0, &p1);
	Insert_DynamicArray(arr, 0, &p2);
	Insert_DynamicArray(arr, 666, &p3);
	Insert_DynamicArray(arr, 1, &p4);
	Insert_DynamicArray(arr, 2, &p5); //20 40 60 50 10 30

	//���������û�ֱ�ӷ�������Ĺؼ����ݡ�
	printf("Size:%d\n", arr->size);
	Insert_DynamicArray(arr, 2, &p6);
	printf("Size:%d\n", arr->size); // //20 40 60 50 10 30

	Foreach_DynamicArray(arr, myPrint);
	printf("--------------\n");


	//ɾ��ָ��λ��
	Remove_DynamicArray(arr, 2);
	printf("Size:%d\n", arr->size);
	Foreach_DynamicArray(arr, myPrint);

	//�ͷ��ڴ�
	Destroy_DynamicArray(arr);

}

int main() {

	test2();

	system("pause");
	return EXIT_SUCCESS;
}