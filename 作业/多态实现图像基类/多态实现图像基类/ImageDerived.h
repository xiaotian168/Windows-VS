#pragma once
#include<iostream>
#include"ImageBase.h"
using namespace std;

class RectDerived: public ImageBase
{
	friend void calcRet(ImageBase *base);
public:
	RectDerived(double length = 0.0, double wide = 0.0);
	~RectDerived();

	virtual double clacPerimter();
	virtual double clacArea();

private:
	double mLength;
	double mWide;
};

class CicleDerived :public ImageBase
{
	friend void calcRet(ImageBase *base);
public:
	CicleDerived(double r = 0.0);
	~CicleDerived();

	virtual double clacPerimter();
	virtual double clacArea();

private:
	double mR;
};