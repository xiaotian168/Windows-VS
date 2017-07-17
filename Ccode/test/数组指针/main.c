#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main01()		//数组指针，它是指针，指向数组的指针。
{
	int a[10] = {0};
	int i = 0;
	
	//先定义数组类型，根据类型定义指针变量
	typedef int A[10];	//A数组类型，[10]代表步长
	A *p = NULL;	//p数组指针类型变量

	//p = a; //a代表数组首元素地址，a和&a值一样，编译器也是当做&a处理，会有警告
	p = &a;	//&a代表整个数组首地址，p指向数组a

	for (int i = 0; i < 10; ++i)
	{
		//p = &a
		//*p = *&a = a
		(*p)[i] = i + 1;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", (*p)[i]);
	}
	printf("\n");


	system("pause");
	return 0;
}

int main02()	//先定义数组指针类型，根据类型定义指针变量（常用）
{
	//()和[]优先级一样，结合律从左往右
	//第一个()代表指针，所以，它是指针
	//第二个[]代表数组，指向数组的指针
	//指向数组的指针，它有typedef，所以它是一个数组指针类型
	typedef int(*P)[10];

	P q;	//数组指针变量
	
	int a[10] = {0};
	q = &a;

	system("pause");
	return 0;
}

int main()	//直接定义数组指针变量
{
	//() 和[]优先级一样，结合律从左往右
	//第一个()代表指针，所以，它是指针
	//第二个[]代表数组，指向数组的指针
	//指向数组的指针，没有typedef，所以它是一个数组指针变量
	int(*q)[10];
	int a[10] = { 0 };
	q = &a;

	system("pause");
	return 0;
}