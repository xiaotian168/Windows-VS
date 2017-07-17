#include<iostream>
#include<string>
#include"MyArray.h"
using namespace std;

void test()
{
	MyArray arr1;

	for (int i = 0; i < 20; ++i)
	{
		arr1.PushBack(i + 1);
	}
	cout << arr1 << endl;

	MyArray arr2(arr1);
	cout << arr2 << endl;

	MyArray arr3(15);
	for (int i = 0; i < 15; ++i)
	{
		arr3.PushPop(i + 1);
	}
	cout << arr3 << endl;

	arr3 = arr2;
	arr3[0] = 77;
	cout << arr3 << endl;

	/*const MyArray arr4;
	arr3 = arr4;*/

	MyArray arr4;
	arr4 << 1 << 2 << 3 << 4;
	cout << arr4 << endl;

	/*MyArray arr5;
	cin >> arr5;
	cout << arr5;*/
}


int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	test();
	/*int a = 5;
	cout << (a << 2) << endl;*/

	
	cout << endl;
	system("pause");
	return 0;
}
