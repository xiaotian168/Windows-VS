#include"MyArray.h"

MyArray::MyArray()
{
	//Ĭ����������Ϊ20
	this->m_Capacity = 20;
	this->m_Size = 0;
	this->m_pArray = new int[this->m_Capacity];
}

MyArray::MyArray(int capacity)	//explicit������ֹ��ʿ����ת��
{
	if (capacity < 0)
	{
		capacity = 0;
	}
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->m_pArray = new int[this->m_Capacity];
}

MyArray::MyArray(const MyArray& obj)
{
	this->m_Capacity = obj.m_Capacity;
	this->m_Size = obj.m_Size;
	this->m_pArray = new int[this->m_Capacity];		//����ռ�

	for (int i = 0; i < this->m_Size; ++i)	//��������
	{
		this->m_pArray[i] = obj.m_pArray[i];
	}
}

MyArray::~MyArray()
{
	if (this->m_pArray != NULL)
	{
		delete[] this->m_pArray;
		this->m_pArray = NULL;
	}
}

//β������
void MyArray::PushBack(const int &val)
{
	if (this->m_Size >= this->m_Capacity)
	{
		return;
	}

	this->m_pArray[this->m_Size] = val;
	this->m_Size++;
}

//ͷ������
void MyArray::PushPop(const int &val)
{
	if (this->m_Size >= this->m_Capacity)
	{
		return;
	}

	for (int i = this->m_Size; i > 0; --i)
	{
		this->m_pArray[i] = this->m_pArray[i - 1];
	}
	this->m_pArray[0] = val;
	this->m_Size++;
}

//��ȡָ��λ��Ԫ��ֵ
int& MyArray::at(int index)
{
	return this->m_pArray[index];
}

//ɾ��ָ��λ��Ԫ��
void MyArray::Remove(int index)
{
	if (index < 0 || index >= this->m_Size)
	{
		return;
	}

	for (int i = index; i < this->m_Size - 1; ++i)
	{
		this->m_pArray[i] = this->m_pArray[i + 1];
	}

	this->m_Size--;
}

//��ȡ�����С
int MyArray::Size()
{
	return this->m_Size;
}

//����[]�������
int& MyArray::operator[](const int &index)
{
	return this->m_pArray[index];
}

//���� << �����
ostream& operator<<(ostream &os, const MyArray &obj)
{
	for (int i = 0; i < obj.m_Size; ++i)
	{
		os << obj.m_pArray[i] << " ";
	}

	return os;
}

//���� = �����
MyArray& MyArray::operator=(const MyArray& obj)
{
	//�ͷŵ�ǰ��������ڴ�
	delete[] this->m_pArray;
	this->m_Capacity = obj.m_Capacity;
	this->m_Size = obj.m_Size;

	//���¿��ٿռ�
	this->m_pArray = new int[this->m_Capacity];
	for (int i = 0; i < this->m_Size; ++i)	//��������
	{
		this->m_pArray[i] = obj.m_pArray[i];
	}

	return *this;
}

//MyArray arr4; arr4 << 1;	�������������
MyArray&  MyArray::operator<<(const int &val)
{
	/*this->m_pArray[this->m_Size] = val;
	this->m_Size++;*/
	PushBack(val);	//ֱ�ӵ���β�庯��

	return *this;
}

//�������������
istream& operator>>(istream &is, MyArray &obj)
{
	for (int i = 0; obj.m_Capacity; ++i)
	{
		is >> obj.m_pArray[i];
		obj.m_Size++;
	}

	return is;
}