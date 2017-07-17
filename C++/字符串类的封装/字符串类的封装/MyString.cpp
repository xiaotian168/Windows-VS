#include"MyString.h"

MyString::MyString()
{	
	mSize = 0;
	pString = new char[1];	//分配存储空间
	memset(pString, 0, 1);	//清空数据；空串""
}

MyString::MyString(const char *str)
{
	this->mSize = strlen(str);	//获取字符串长度
	this->pString = new char[this->mSize + 1];	//分配字符串存储空间
	memset(this->pString, 0, this->mSize + 1);	//清空内存（安全）
	strcpy(this->pString, str);	//拷贝数据
}

MyString::MyString(const int &n, const char &ch)
{
	this->mSize = n;
	this->pString = new char[this->mSize + 1];	//分配内存
	memset(this->pString, 0, this->mSize + 1);	//清空数据
	
	for (int i = 0; i < n; ++i)	//拷贝数据
	{
		this->pString[i] = ch;
	}

}

MyString::MyString(const MyString &str)
{
	this->mSize = str.mSize;	//获取字符串有效长度
	this->pString = new char[this->mSize + 1];	//分配字符串存储空间
	memset(this->pString, 0, this->mSize + 1);	//清空内存（安全）
	strcpy(this->pString, str.pString);	//拷贝数据
}

MyString::~MyString()
{
	if (pString != NULL)
	{
		delete[] pString;
		mSize = 0;
	}
}

//重载=号；str1 = str2;
MyString& MyString::operator=(const MyString &str)
{
	//释放当前对象所存储字符串的堆内存；
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
		this->mSize = 0;
	}

	this->mSize = str.mSize;	//获取要拷贝的字符串有效长度
	this->pString = new char[this->mSize + 1];	//分配存储空间
	memset(this->pString, 0, this->mSize + 1);	//清空存储空间（使其拷贝数据前处于安全状态）
	strcpy(this->pString, str.pString);	//拷贝数据

	return *this;
}

MyString& MyString::operator=(const char *str)
{
	//释放当前对象所存储字符串的堆内存；
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
		this->mSize = 0;
	}

	this->mSize = strlen(str);	//获取要拷贝的字符串有效长度
	this->pString = new char[this->mSize + 1];	//分配存储空间
	memset(this->pString, 0, this->mSize + 1);	//清空存储空间（使其拷贝数据前处于安全状态）
	strcpy(this->pString, str);	//拷贝数据

	return *this;
}


//拼接字符串: ret = str1 + str2
MyString MyString::operator+(const MyString &str)
{
	MyString newstr;	//创建一个临时对象
	if (newstr.pString != NULL)
	{
		delete[] newstr.pString;
		newstr.mSize = 0;
	}

	newstr.mSize = this->mSize + str.mSize;	//获取两个字符串的总长度
	newstr.pString = new char[newstr.mSize + 1];	//分配存储空间
	memset(newstr.pString, 0, newstr.mSize + 1);	//清空内存；置于安全状态
	strcat(newstr.pString, this->pString);	//追加当前对象的字符串到新对象中
	strcat(newstr.pString, str.pString);	//追加右操作数对象的字符串到新对象中

	return newstr;
}

MyString MyString::operator+(const char *str)
{
	MyString newstr;	//创建一个临时对象
	if (newstr.pString != NULL)
	{
		delete[] newstr.pString;
		newstr.mSize = 0;
	}

	newstr.mSize = this->mSize + strlen(str);	//获取两个字符串的总长度
	newstr.pString = new char[newstr.mSize + 1];	//分配存储空间
	memset(newstr.pString, 0, newstr.mSize + 1);	//清空内存；置于安全状态
	strcat(newstr.pString, this->pString);	//追加当前对象的字符串到新对象中
	strcat(newstr.pString, str);	//追加右操作数对象的字符串到新对象中

	return newstr;
}


//追加字符串: str1 += str2
MyString& MyString::operator+=(const MyString &str)
{
	int newsize = this->mSize + str.mSize;	//获取追加后的字符串长度
	char *newSpace = new char[newsize + 1];	//分配存储空间
	memset(newSpace, 0, newsize + 1);	//清空数据
	strcat(newSpace, this->pString);	//追加当前字符串
	strcat(newSpace, str.pString);	//追加str2的字符串

	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
		this->mSize = 0;
	}

	this->pString = newSpace;
	this->mSize = newsize;

	return *this;
}

MyString& MyString::operator+=(const char *str)
{
	int newsize = this->mSize + strlen(str);	//获取追加后的字符串长度
	char *newSpace = new char[newsize + 1];	//分配存储空间
	memset(newSpace, 0, newsize + 1);	//清空数据
	strcat(newSpace, this->pString);	//追加当前字符串
	strcat(newSpace, str);	//追加str2的字符串

	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
		this->mSize = 0;
	}

	this->pString = newSpace;
	this->mSize = newsize;

	return *this;
}

//获取字符串长度
int MyString::Size()
{
	return this->mSize;
}


//重载+号；实现字符串拼接
MyString operator+(const char *str1, const MyString &str2)
{
	MyString newstr;	//创建一个临时对象
	if (newstr.pString != NULL)
	{
		delete[] newstr.pString;
		newstr.mSize = 0;
	}

	newstr.mSize = strlen(str1) + str2.mSize;	//获取两个字符串的总长度
	newstr.pString = new char[newstr.mSize + 1];	//分配存储空间
	memset(newstr.pString, 0, newstr.mSize + 1);	//清空内存；置于安全状态
	strcat(newstr.pString, str1);	//追加str1到新对象中
	strcat(newstr.pString, str2.pString);	//追加右操作数对象的字符串到新对象中

	return newstr;
}

//输出字符串
std::ostream& operator<<(std::ostream &os, const MyString &str)
{
	os << str.pString;
	return os;
}

//输入字符串
std::istream& operator>>(std::istream &is, MyString &str)
{
	//定义一个缓冲区；用来接收输入的字符串
	char buf[1024] = { 0 };
	is >> buf;	//接收输入

	if (str.pString != NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
		str.mSize = 0;
	}

	str.mSize = strlen(buf);	//获取输入字符串长度
	str.pString = new char[str.mSize + 1];	//分配存储空间
	memset(str.pString, 0, str.mSize + 1);	//清空数据
	strcpy(str.pString, buf);	//数据拷贝

	return is;
}