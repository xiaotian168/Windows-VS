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

	test();

	system("pause");
	return EXIT_SUCCESS;
}