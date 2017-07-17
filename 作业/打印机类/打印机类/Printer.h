#pragma once
#include<iostream>
#include<string>
using namespace std;

class Printer
{
public:
	//获取单列对象
	static Printer* myPinter();

	//打印字符串
	void Print(const string &str);

	//获取打印次数
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
