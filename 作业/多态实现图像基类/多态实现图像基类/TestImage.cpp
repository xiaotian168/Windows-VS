#include<iostream>
#include<string>
#include"ImageBase.h"
#include"ImageDerived.h"
using namespace std;

//全局计算函数
void calcRet(ImageBase *base)
{
	cout << "周长：" << base->clacPerimter() << "  面积：" << base->clacArea() << endl;
}

void test()
{
	//矩形
	ImageBase *pRect = new RectDerived(2,2);
	calcRet(pRect);
	
	//圆形
	ImageBase *pCicle = new CicleDerived(2);
	calcRet(pCicle);
}

int main()
{
	/*******************************************************/
	/*
		需求：
		使用多态实现一个图形基类，两个子类：矩形和圆形
		基类包含两个抽象方法：周长和面积
		子类分别重写这两个方法
		另外写一个全局的计算方法，参数为基类指针，
		传入子类对象时，输出对应的周长和面积
	*/
	/*******************************************************/
	test();

	cout << endl;
	system("pause");
	return 0;
}
