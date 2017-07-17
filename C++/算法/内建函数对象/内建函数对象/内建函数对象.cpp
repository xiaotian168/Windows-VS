#include<iostream>
#include<functional>
using namespace std;

void test()
{
	/*
	constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator+ to operands
	return (_Left + _Right);
	}
	*/
	plus<int> myAdd;
	cout << myAdd(10, 11) << "\n";

	//使用匿名对象
	cout << modulus<int>()(7, 10) << "\n";

	/*
	constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator% to operands
	return (_Left % _Right);
	}
	*/

	cout << divides<int>()(2, 0) << "\n";	//程序中断；内部实现没有判断除数为0的情况
	/*
	constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator/ to operands
	return (_Left / _Right);
	}
	*/
}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	test();

	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}
