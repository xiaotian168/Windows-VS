#pragma once
#include<iostream>
using namespace std;

class MyArray
{
	//�������������
	/*MyArray arr5;
	cin >> arr5;*/
	friend istream& operator>>(istream &is,MyArray &obj);

	//cout << arr1;	��������( << )�����
	friend ostream& operator<<(ostream &os, const MyArray &obj);

public:
	MyArray();
	explicit MyArray(int capacity);	//explicit������ֹ��ʿ����ת��
	MyArray(const MyArray& obj);
	~MyArray();

	//β������
	void PushBack(const int &val);

	//ͷ������
	void PushPop(const int &val);

	//��ȡָ��λ��Ԫ��ֵ
	int& at(int index);

	//ɾ��ָ��λ��Ԫ��
	void Remove(int index);

	//��ȡ�����С
	int Size();

	//arr1[i] = i + 1;	����[]�������
	int& operator[](const int &index);
	
	//arr3 = arr2;=��ֵ���������
	MyArray& operator=(const MyArray& obj);

	//MyArray arr4; arr4 << 1;	�������������
	MyArray& operator<<(const int &val);

private:
	int *m_pArray;	//��������Ԫ�ص��׵�ַ
	int m_Capacity;		//����
	int m_Size;		//��С
};