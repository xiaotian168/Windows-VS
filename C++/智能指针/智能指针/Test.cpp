#include<iostream>
#include<string>
#include"SmartPointer.h"
using namespace std;

void test()
{
	SmartPointer person(new Person(10));
	person->Test();
}

int main()
{
	/*******************************************************/
	/*
		智能指针：
			1、定义一个类Person；
			2、定义一个指针类；里面含有一个Person类型的指针变量
	*/
	/*******************************************************/
	test();

	cout << endl;
	system("pause");
	return 0;
}
