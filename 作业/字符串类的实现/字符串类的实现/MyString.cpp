#define _CRT_SECURE_NO_WARNINGS
#include"MyString.h"
/*
private:
	char* pAddress; //�ַ���ʵ�ʴ洢��ַ
	int mSize; //�ַ�����С
*/

MyString::MyString() //�޲ι��� 
{
	mSize = 0;
	pAddress = new char[mSize + 1];	//����洢�ռ�
	strcpy(pAddress, "");	//�������ַ�
}

MyString::MyString(int n, char c) //�вι��죬ָ����С�ͳ�ʼֵ
{
	this->mSize = n;
	this->pAddress = new char[this->mSize + 1];
	memset(pAddress, 0, this->mSize + 1);	//����ڴ����ݣ���ȫ
	for (int i = 0; i < this->mSize; ++i)
	{
		pAddress[i] = c;
	}
}

MyString::MyString(const char *str)	//�вι��죬�ַ���
{
	this->mSize = strlen(str);
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, str);
}

MyString::MyString(const MyString& str) //��������
{
	this->mSize = str.mSize;
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, str.pAddress);
}

MyString& MyString::operator=(const MyString& str) //��ֵ���������
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

MyString& MyString::operator=(const char* str) //��ֵ���������
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

MyString::~MyString() //��������
{
	if (pAddress != NULL)
	{
		delete[]pAddress;
		pAddress = NULL;
		mSize = 0;
	}
}


MyString MyString::operator+(const MyString& str) //�Ӻ����������
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

MyString MyString::operator+(const char *s) //�Ӻ����������
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


MyString& MyString::operator+=(const MyString& str) //�ӵ����������
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

MyString& MyString::operator+=(const char *s) //�ӵ����������
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


char& MyString::operator[](int index) //�±����������
{
	return this->pAddress[index];
}

int MyString::Size() //�����ַ�������
{
	return mSize;
}

std::ostream& operator<<(std::ostream &out, MyString &str) //������������
{
	out << str.pAddress;
	return out;
}

std::istream& operator >> (std::istream &in, MyString &str) //�������������
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
