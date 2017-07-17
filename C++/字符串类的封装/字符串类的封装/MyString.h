#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>


class MyString
{
	//�����ַ���
	friend std::istream& operator>>(std::istream &is, MyString &str);

	//����ַ���
	friend std::ostream& operator<<(std::ostream &os, const MyString &str);

	//����+�ţ�ʵ���ַ���ƴ��
	friend MyString operator+(const char *str1, const MyString &str2);
public:
	MyString();	//�����޲ι��캯����Ĭ��ʵ����һ���մ�����
	MyString(const char *str);
	MyString(const int &n, const char &ch);
	MyString(const MyString &str);
	~MyString();

	//����=�ţ�str1 = str2;
	MyString& operator=(const MyString &str);
	MyString& operator=(const char *str);

	//ƴ���ַ���
	MyString operator+(const MyString &str);
	MyString operator+(const char *str);

	//׷���ַ���
	MyString& operator+=(const MyString &str);
	MyString& operator+=(const char *str);

	//��ȡ�ַ�������
	int Size();

private:
	char *pString;	//ָ�������洢�ַ����Ķѿռ�
	int mSize;	//�ַ�������Ч����('\0'����)
};