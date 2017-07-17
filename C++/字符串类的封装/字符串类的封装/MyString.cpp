#include"MyString.h"

MyString::MyString()
{	
	mSize = 0;
	pString = new char[1];	//����洢�ռ�
	memset(pString, 0, 1);	//������ݣ��մ�""
}

MyString::MyString(const char *str)
{
	this->mSize = strlen(str);	//��ȡ�ַ�������
	this->pString = new char[this->mSize + 1];	//�����ַ����洢�ռ�
	memset(this->pString, 0, this->mSize + 1);	//����ڴ棨��ȫ��
	strcpy(this->pString, str);	//��������
}

MyString::MyString(const int &n, const char &ch)
{
	this->mSize = n;
	this->pString = new char[this->mSize + 1];	//�����ڴ�
	memset(this->pString, 0, this->mSize + 1);	//�������
	
	for (int i = 0; i < n; ++i)	//��������
	{
		this->pString[i] = ch;
	}

}

MyString::MyString(const MyString &str)
{
	this->mSize = str.mSize;	//��ȡ�ַ�����Ч����
	this->pString = new char[this->mSize + 1];	//�����ַ����洢�ռ�
	memset(this->pString, 0, this->mSize + 1);	//����ڴ棨��ȫ��
	strcpy(this->pString, str.pString);	//��������
}

MyString::~MyString()
{
	if (pString != NULL)
	{
		delete[] pString;
		mSize = 0;
	}
}

//����=�ţ�str1 = str2;
MyString& MyString::operator=(const MyString &str)
{
	//�ͷŵ�ǰ�������洢�ַ����Ķ��ڴ棻
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
		this->mSize = 0;
	}

	this->mSize = str.mSize;	//��ȡҪ�������ַ�����Ч����
	this->pString = new char[this->mSize + 1];	//����洢�ռ�
	memset(this->pString, 0, this->mSize + 1);	//��մ洢�ռ䣨ʹ�俽������ǰ���ڰ�ȫ״̬��
	strcpy(this->pString, str.pString);	//��������

	return *this;
}

MyString& MyString::operator=(const char *str)
{
	//�ͷŵ�ǰ�������洢�ַ����Ķ��ڴ棻
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
		this->mSize = 0;
	}

	this->mSize = strlen(str);	//��ȡҪ�������ַ�����Ч����
	this->pString = new char[this->mSize + 1];	//����洢�ռ�
	memset(this->pString, 0, this->mSize + 1);	//��մ洢�ռ䣨ʹ�俽������ǰ���ڰ�ȫ״̬��
	strcpy(this->pString, str);	//��������

	return *this;
}


//ƴ���ַ���: ret = str1 + str2
MyString MyString::operator+(const MyString &str)
{
	MyString newstr;	//����һ����ʱ����
	if (newstr.pString != NULL)
	{
		delete[] newstr.pString;
		newstr.mSize = 0;
	}

	newstr.mSize = this->mSize + str.mSize;	//��ȡ�����ַ������ܳ���
	newstr.pString = new char[newstr.mSize + 1];	//����洢�ռ�
	memset(newstr.pString, 0, newstr.mSize + 1);	//����ڴ棻���ڰ�ȫ״̬
	strcat(newstr.pString, this->pString);	//׷�ӵ�ǰ������ַ������¶�����
	strcat(newstr.pString, str.pString);	//׷���Ҳ�����������ַ������¶�����

	return newstr;
}

MyString MyString::operator+(const char *str)
{
	MyString newstr;	//����һ����ʱ����
	if (newstr.pString != NULL)
	{
		delete[] newstr.pString;
		newstr.mSize = 0;
	}

	newstr.mSize = this->mSize + strlen(str);	//��ȡ�����ַ������ܳ���
	newstr.pString = new char[newstr.mSize + 1];	//����洢�ռ�
	memset(newstr.pString, 0, newstr.mSize + 1);	//����ڴ棻���ڰ�ȫ״̬
	strcat(newstr.pString, this->pString);	//׷�ӵ�ǰ������ַ������¶�����
	strcat(newstr.pString, str);	//׷���Ҳ�����������ַ������¶�����

	return newstr;
}


//׷���ַ���: str1 += str2
MyString& MyString::operator+=(const MyString &str)
{
	int newsize = this->mSize + str.mSize;	//��ȡ׷�Ӻ���ַ�������
	char *newSpace = new char[newsize + 1];	//����洢�ռ�
	memset(newSpace, 0, newsize + 1);	//�������
	strcat(newSpace, this->pString);	//׷�ӵ�ǰ�ַ���
	strcat(newSpace, str.pString);	//׷��str2���ַ���

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
	int newsize = this->mSize + strlen(str);	//��ȡ׷�Ӻ���ַ�������
	char *newSpace = new char[newsize + 1];	//����洢�ռ�
	memset(newSpace, 0, newsize + 1);	//�������
	strcat(newSpace, this->pString);	//׷�ӵ�ǰ�ַ���
	strcat(newSpace, str);	//׷��str2���ַ���

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

//��ȡ�ַ�������
int MyString::Size()
{
	return this->mSize;
}


//����+�ţ�ʵ���ַ���ƴ��
MyString operator+(const char *str1, const MyString &str2)
{
	MyString newstr;	//����һ����ʱ����
	if (newstr.pString != NULL)
	{
		delete[] newstr.pString;
		newstr.mSize = 0;
	}

	newstr.mSize = strlen(str1) + str2.mSize;	//��ȡ�����ַ������ܳ���
	newstr.pString = new char[newstr.mSize + 1];	//����洢�ռ�
	memset(newstr.pString, 0, newstr.mSize + 1);	//����ڴ棻���ڰ�ȫ״̬
	strcat(newstr.pString, str1);	//׷��str1���¶�����
	strcat(newstr.pString, str2.pString);	//׷���Ҳ�����������ַ������¶�����

	return newstr;
}

//����ַ���
std::ostream& operator<<(std::ostream &os, const MyString &str)
{
	os << str.pString;
	return os;
}

//�����ַ���
std::istream& operator>>(std::istream &is, MyString &str)
{
	//����һ������������������������ַ���
	char buf[1024] = { 0 };
	is >> buf;	//��������

	if (str.pString != NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
		str.mSize = 0;
	}

	str.mSize = strlen(buf);	//��ȡ�����ַ�������
	str.pString = new char[str.mSize + 1];	//����洢�ռ�
	memset(str.pString, 0, str.mSize + 1);	//�������
	strcpy(str.pString, buf);	//���ݿ���

	return is;
}