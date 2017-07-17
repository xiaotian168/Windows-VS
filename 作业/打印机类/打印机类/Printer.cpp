#include"Printer.h"

Printer * Printer::mP = new Printer;
int Printer::Times = 0;

Printer::Printer()
{

}

Printer::Printer(const Printer& obj)
{

}

Printer::~Printer()
{
	
}

//获取单列对象
Printer* Printer::myPinter()
{
	return mP;
}

//打印字符串
void Printer::Print(const string &str)
{
	cout << str << endl;
	Times++;
}


//获取打印次数
int Printer::PrintTimes()
{
	return Times;
}
