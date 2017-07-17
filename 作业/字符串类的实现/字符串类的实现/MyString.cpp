#define _CRT_SECURE_NO_WARNINGS
#include"MyString.h"
/*
private:
	char* pAddress; //字符串实际存储地址
	int mSize; //字符串大小
*/

MyString::MyString() //无参构造 
{
	mSize = 0;
	pAddress = new char[mSize + 1];	//分配存储空间
	strcpy(pAddress, "");	//拷贝空字符
}

MyString::MyString(int n, char c) //有参构造，指定大小和初始值
{
	this->mSize = n;
	this->pAddress = new char[this->mSize + 1];
	memset(pAddress, 0, this->mSize + 1);	//清空内存数据；安全
	for (int i = 0; i < this->mSize; ++i)
	{
		pAddress[i] = c;
	}
}

MyString::MyString(const char *str)	//有参构造，字符串
{
	this->mSize = strlen(str);
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, str);
}

MyString::MyString(const MyString& str) //拷贝构造
{
	this->mSize = str.mSize;
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, str.pAddress);
}

MyString& MyString::operator=(const MyString& str) //赋值运算符重载
{
	if (this->pAddress != NULL)
	{
		delete[]this->pAddress;
		this->pAddress = NULL;
		this->mSize = 0;
	}

	this->mSize = str.mSize;
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, str.pAddress);

	return *this;
}

MyString& MyString::operator=(const char* str) //赋值运算符重载
{
	if (this->pAddress != NULL)
	{
		delete[]this->pAddress;
		this->pAddress = NULL;
		this->mSize = 0;
	}

	this->mSize = strlen(str);
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, str);

	return *this;
}

MyString::~MyString() //析构函数
{
	if (pAddress != NULL)
	{
		delete[]pAddress;
		pAddress = NULL;
		mSize = 0;
	}
}


MyString MyString::operator+(const MyString& str) //加号运算符重载
{
	MyString temp;
	delete []temp.pAddress;
	temp.pAddress = NULL;

	temp.mSize = this->mSize + str.mSize;
	temp.pAddress = new char[temp.mSize + 1];
	memset(temp.pAddress, 0, temp.mSize);
	strcat(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, str.pAddress);

	return temp;
}

MyString MyString::operator+(const char *s) //加号运算符重载
{
	MyString temp;
	delete[]temp.pAddress;
	temp.pAddress = NULL;

	temp.mSize = this->mSize + strlen(s);
	temp.pAddress = new char[temp.mSize + 1];
	memset(temp.pAddress, 0, temp.mSize);
	strcat(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, s);

	return temp;
}


MyString& MyString::operator+=(const MyString& str) //加等运算符重载
{
	this->mSize += str.mSize;
	char *newstr = new char[this->mSize + 1];
	memset(newstr, 0, this->mSize + 1);
	strcat(newstr, this->pAddress);
	strcat(newstr, str.pAddress);

	delete[]this->pAddress;
	this->pAddress = newstr;

	return *this;
}

MyString& MyString::operator+=(const char *s) //加等运算符重载
{
	this->mSize += strlen(s);
	char *newstr = new char[this->mSize + 1];
	memset(newstr, 0, this->mSize + 1);
	strcat(newstr, this->pAddress);
	strcat(newstr, s);

	delete[]this->pAddress;
	this->pAddress = newstr;

	return *this;
}


char& MyString::operator[](int index) //下标运算符重载
{
	return this->pAddress[index];
}

int MyString::Size() //返回字符串长度
{
	return mSize;
}

std::ostream& operator<<(std::ostream &out, MyString &str) //输出运算符重载
{
	out << str.pAddress;
	return out;
}

std::istream& operator >> (std::istream &in, MyString &str) //输入运算符重载
{
	if (str.pAddress != NULL)
	{
		delete[]str.pAddress;
		str.pAddress = NULL;
		str.mSize = 0;
	}

	char buf[1024] = { 0 };
	in >> buf;
	str.mSize = strlen(buf);
	str.pAddress = new char[str.mSize + 1];
	memset(str.pAddress, 0, str.mSize + 1);
	strcpy(str.pAddress, buf);

	return in;
}
