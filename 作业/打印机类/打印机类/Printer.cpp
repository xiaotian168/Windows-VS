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

//��ȡ���ж���
Printer* Printer::myPinter()
{
	return mP;
}

//��ӡ�ַ���
void Printer::Print(const string &str)
{
	cout << str << endl;
	Times++;
}


//��ȡ��ӡ����
int Printer::PrintTimes()
{
	return Times;
}
