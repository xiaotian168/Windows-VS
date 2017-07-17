#pragma once
#include<iostream>

class MyString
{
private:
	char* pAddress; //�ַ���ʵ�ʴ洢��ַ
	int mSize; //�ַ�����С
public:
	MyString(); //�޲ι��� 
	MyString(const char *str);	//�вι��죬�ַ���
	MyString(int n, char c); //�вι��죬ָ����С�ͳ�ʼֵ
	MyString(const MyString& str); //��������
	MyString& operator=(const MyString& str); //��ֵ���������
	MyString& operator=(const char* str); //��ֵ���������
	~MyString(); //��������


	MyString operator+(const MyString& str); //�Ӻ����������
	MyString operator+(const char *s); //�Ӻ����������

	MyString& operator+=(const MyString& str); //�ӵ����������
	MyString& operator+=(const char *s); //�ӵ����������

	char& operator[](int index); //�±����������
	int Size(); //�����ַ�������
	friend std::ostream& operator<<(std::ostream &out, MyString &str); //������������
	friend std::istream& operator >> (std::istream &in, MyString &str); //�������������
};