#include<iostream>
#include<string>
#include"ImageBase.h"
#include"ImageDerived.h"
using namespace std;

//ȫ�ּ��㺯��
void calcRet(ImageBase *base)
{
	cout << "�ܳ���" << base->clacPerimter() << "  �����" << base->clacArea() << endl;
}

void test()
{
	//����
	ImageBase *pRect = new RectDerived(2,2);
	calcRet(pRect);
	
	//Բ��
	ImageBase *pCicle = new CicleDerived(2);
	calcRet(pCicle);
}

int main()
{
	/*******************************************************/
	/*
		����
		ʹ�ö�̬ʵ��һ��ͼ�λ��࣬�������ࣺ���κ�Բ��
		��������������󷽷����ܳ������
		����ֱ���д����������
		����дһ��ȫ�ֵļ��㷽��������Ϊ����ָ�룬
		�����������ʱ�������Ӧ���ܳ������
	*/
	/*******************************************************/
	test();

	cout << endl;
	system("pause");
	return 0;
}
