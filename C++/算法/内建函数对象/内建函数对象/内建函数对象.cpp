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

	//ʹ����������
	cout << modulus<int>()(7, 10) << "\n";

	/*
	constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator% to operands
	return (_Left % _Right);
	}
	*/

	cout << divides<int>()(2, 0) << "\n";	//�����жϣ��ڲ�ʵ��û���жϳ���Ϊ0�����
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
