#include<iostream>
#include<string>
#include"Printer.h"
using namespace std;

void test()
{
	Printer  *p = Printer::myPinter();
	string str1 = "hello";
	string str2 = "world";
	
	//��ӡ�ַ���
	p->Print(str1);
	p->Print(str2);
	p->Print(str1);
	p->Print(str1);

	//�����ӡ����
	cout << "��ǰ��ӡ����ӡ�ܴ���Ϊ��"<<p->PrintTimes() << endl;;
}

int main()
{
	/*******************************************************/
	/*
		����
			ʹ�õ���ģʽʵ��һ����ӡ����
			��ӡ������ַ���
			�ۼƴ�ӡ����
	*/
	/*******************************************************/
	test();

	cout << endl;
	system("pause");
	return 0;
}
