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
		����ָ�룺
			1������һ����Person��
			2������һ��ָ���ࣻ���溬��һ��Person���͵�ָ�����
	*/
	/*******************************************************/
	test();

	cout << endl;
	system("pause");
	return 0;
}
