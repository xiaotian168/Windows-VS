#include"MyArray.h"

MyArray::MyArray()
{
	//默认数组容量为20
	this->m_Capacity = 20;
	this->m_Size = 0;
	this->m_pArray = new int[this->m_Capacity];
}

MyArray::MyArray(int capacity)	//explicit用来防止隐士类型转换
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
	this->m_pArray = new int[this->m_Capacity];		//分配空间

	for (int i = 0; i < this->m_Size; ++i)	//拷贝数据
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

//尾部插入
void MyArray::PushBack(const int &val)
{
	if (this->m_Size >= this->m_Capacity)
	{
		return;
	}

	this->m_pArray[this->m_Size] = val;
	this->m_Size++;
}

//头部插入
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

//获取指定位置元素值
int& MyArray::at(int index)
{
	return this->m_pArray[index];
}

//删除指定位置元素
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

//获取数组大小
int MyArray::Size()
{
	return this->m_Size;
}

//重载[]号运算符
int& MyArray::operator[](const int &index)
{
	return this->m_pArray[index];
}

//重载 << 运算符
ostream& operator<<(ostream &os, const MyArray &obj)
{
	for (int i = 0; i < obj.m_Size; ++i)
	{
		os << obj.m_pArray[i] << " ";
	}

	return os;
}

//重载 = 运算符
MyArray& MyArray::operator=(const MyArray& obj)
{
	//释放当前数组对象内存
	delete[] this->m_pArray;
	this->m_Capacity = obj.m_Capacity;
	this->m_Size = obj.m_Size;

	//重新开辟空间
	this->m_pArray = new int[this->m_Capacity];
	for (int i = 0; i < this->m_Size; ++i)	//拷贝数据
	{
		this->m_pArray[i] = obj.m_pArray[i];
	}

	return *this;
}

//MyArray arr4; arr4 << 1;	左移运算符重载
MyArray&  MyArray::operator<<(const int &val)
{
	/*this->m_pArray[this->m_Size] = val;
	this->m_Size++;*/
	PushBack(val);	//直接调用尾插函数

	return *this;
}

//右移运算符重载
istream& operator>>(istream &is, MyArray &obj)
{
	for (int i = 0; obj.m_Capacity; ++i)
	{
		is >> obj.m_pArray[i];
		obj.m_Size++;
	}

	return is;
}