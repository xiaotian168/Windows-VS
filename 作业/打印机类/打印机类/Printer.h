#pragma once
#include<iostream>
#include<string>
using namespace std;

class Printer
{
public:
	//��ȡ���ж���
	static Printer* myPinter();

	//��ӡ�ַ���
	void Print(const string &str);

	//��ȡ��ӡ����
	int PrintTimes();

private:
	Printer();
	Printer(const Printer& obj);
	~Printer();

private:
	static Printer *mP;
	static int Times;
	string mStr;
};
