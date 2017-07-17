#include"ImageDerived.h"

//矩形子类
RectDerived::RectDerived(double length, double wide)
{
	this->mLength = length;
	this->mWide = wide;
}

RectDerived::~RectDerived()
{

}

double RectDerived::clacPerimter()
{
	return (mLength + mWide) * 2;
}

double RectDerived::clacArea()
{
	return mLength * mWide;
}


//圆形子类
CicleDerived::CicleDerived(double r)
{
	this->mR = r;
}

CicleDerived::~CicleDerived()
{

}

double CicleDerived::clacPerimter()
{
	return 6.48*mR;
}

double CicleDerived::clacArea()
{
	return 3.14*mR*mR;
}
