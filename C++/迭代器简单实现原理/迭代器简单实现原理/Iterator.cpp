#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
public:
	typedef T* iterator;
public:
	MyArray()
	{
		mCapacity = 10;
		mSize = 10;
		pAddress = new T[mSize];

		for (int i = 0; i < mSize; ++i)	//本例外部用int基本数据测；不用考虑深浅拷贝问题
		{
			pAddress[i] = i + 1;
		}
	}

	T* beg()
	{
		return this->pAddress;
	}

	T* end()
	{
		return this->pAddress + mSize;
	}

private:
	T *pAddress;
	int mCapacity;
	int mSize;
};


void test()
{
	MyArray<int> arr;
	MyArray<int>::iterator beg = arr.beg();
	MyArray<int>::iterator end = arr.end();

	while (beg != end)
	{
		cout << *beg << " ";
		++beg;
	}

}

void test1()
{
	MyArray<int> arr;
	/*auto beg = arr.beg();
	auto end = arr.end();*/
	
	for (auto beg = arr.beg(); beg != arr.end(); ++beg)
	{
		cout << *beg << " ";
	}

}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	//test();
	test1();

	cout << endl;
	system("pause");
	return 0;
}
