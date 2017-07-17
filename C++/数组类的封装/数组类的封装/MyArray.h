#pragma once
#include<iostream>
using namespace std;

class MyArray
{
	//右移运算符重载
	/*MyArray arr5;
	cin >> arr5;*/
	friend istream& operator>>(istream &is,MyArray &obj);

	//cout << arr1;	重载左移( << )运算符
	friend ostream& operator<<(ostream &os, const MyArray &obj);

public:
	MyArray();
	explicit MyArray(int capacity);	//explicit用来防止隐士类型转换
	MyArray(const MyArray& obj);
	~MyArray();

	//尾部插入
	void PushBack(const int &val);

	//头部插入
	void PushPop(const int &val);

	//获取指定位置元素值
	int& at(int index);

	//删除指定位置元素
	void Remove(int index);

	//获取数组大小
	int Size();

	//arr1[i] = i + 1;	重载[]号运算符
	int& operator[](const int &index);
	
	//arr3 = arr2;=赋值运算符重载
	MyArray& operator=(const MyArray& obj);

	//MyArray arr4; arr4 << 1;	左移运算符重载
	MyArray& operator<<(const int &val);

private:
	int *m_pArray;	//保存数组元素的首地址
	int m_Capacity;		//容量
	int m_Size;		//大小
};