#include<iostream>
#include<string>
#include"Printer.h"
using namespace std;

void test()
{
	Printer  *p = Printer::myPinter();
	string str1 = "hello";
	string str2 = "world";
	
	//打印字符串
	p->Print(str1);
	p->Print(str2);
	p->Print(str1);
	p->Print(str1);

	//输出打印次数
	cout << "当前打印机打印总次数为："<<p->PrintTimes() << endl;;
}

int main()
{
	/*******************************************************/
	/*
		需求：
			使用单例模式实现一个打印机类
			打印传入的字符串
			累计打印次数
	*/
	/*******************************************************/
	test();

	cout << endl;
	system("pause");
	return 0;
}
