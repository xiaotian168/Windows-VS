#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>


class MyString
{
	//输入字符串
	friend std::istream& operator>>(std::istream &is, MyString &str);

	//输出字符串
	friend std::ostream& operator<<(std::ostream &os, const MyString &str);

	//重载+号；实现字符串拼接
	friend MyString operator+(const char *str1, const MyString &str2);
public:
	MyString();	//调用无参构造函数，默认实例化一个空串出来
	MyString(const char *str);
	MyString(const int &n, const char &ch);
	MyString(const MyString &str);
	~MyString();

	//重载=号；str1 = str2;
	MyString& operator=(const MyString &str);
	MyString& operator=(const char *str);

	//拼接字符串
	MyString operator+(const MyString &str);
	MyString operator+(const char *str);

	//追加字符串
	MyString& operator+=(const MyString &str);
	MyString& operator+=(const char *str);

	//获取字符串长度
	int Size();

private:
	char *pString;	//指向真正存储字符串的堆空间
	int mSize;	//字符串的有效长度('\0'除外)
};