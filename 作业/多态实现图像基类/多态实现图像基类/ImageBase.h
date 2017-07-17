#pragma once

class ImageBase
{
	friend void calcRet(ImageBase *base);
public:
	virtual double clacPerimter();
	virtual double clacArea();
};