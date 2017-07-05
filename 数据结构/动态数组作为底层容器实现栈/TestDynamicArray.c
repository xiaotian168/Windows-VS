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

//初始化栈
SeqStack Init_Stack()
{
	return Init_DynamicArray();
}

//入栈
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
	Insert_DynamicArray(arr, pos, data);	//每次从动态数组后面放入元素

}

//出栈
void Pop_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	struct DArray *arr = (struct DArray *)stack;
	int pos = arr->size;
	Remove_DynamicArray(arr, pos-1);	//每次从动态数组后面删除元素

}

//获取栈顶元素
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

//获取栈中元素个数
int Size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	struct DArray *arr = (struct DArray *)stack;
	return arr->size;
}

//销毁栈
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
	//初始换栈
	SeqStack stack = Init_Stack();

	//测试数据
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };
	struct Person p6 = { "fff", 60 };

	//入栈
	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);

	//获取栈中元素个数
	printf("当前栈中元素个数：%d\n", Size_SeqStack(stack));

	//获取栈顶元素
	struct Person *person = (struct Person *)Top_SeqStack(stack);
	printf("%s, %d\n", person->name, person->age);

	//出栈
	Pop_SeqStack(stack);
	printf("出栈后元素个数：%d\n", Size_SeqStack(stack));

	//获取栈顶元素
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

	//初始化数组
	struct DArray *arr = Init_DynamicArray();

	//测试数据
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };
	struct Person p6 = { "fff", 60 };

	//向数组中插入数据
	Insert_DynamicArray(arr, 0, &p1);
	Insert_DynamicArray(arr, 0, &p2);
	Insert_DynamicArray(arr, 666, &p3);
	Insert_DynamicArray(arr, 1, &p4);
	Insert_DynamicArray(arr, 2, &p5); //20 40 60 50 10 30

	//不建议让用户直接访问数组的关键数据。
	printf("Size:%d\n", arr->size);
	Insert_DynamicArray(arr, 2, &p6);
	printf("Size:%d\n", arr->size); // //20 40 60 50 10 30

	Foreach_DynamicArray(arr, myPrint);
	printf("--------------\n");


	//删除指定位置
	Remove_DynamicArray(arr, 2);
	printf("Size:%d\n", arr->size);
	Foreach_DynamicArray(arr, myPrint);

	//释放内存
	Destroy_DynamicArray(arr);

}

int main() {

	test2();

	system("pause");
	return EXIT_SUCCESS;
}