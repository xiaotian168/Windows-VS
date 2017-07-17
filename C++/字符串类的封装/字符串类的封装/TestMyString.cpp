#include<iostream>
#include<string>
#include"MyString.h"

using namespace std;

void test1()
{
	MyString str1;
	//cout << str1 << endl;
	str1 = "aaaaa";
	cout << "str1: " << str1 << endl;

	MyString str2 = "hello world";
	cout << "str2: " << str2 << endl;

	str2 = str1;
	cout << "str2: " << str2 << endl;

	MyString str3;
	str3 = str1 + str2;
	cout << "str3: " << str3 << endl;

	MyString str4;
	str4 += "bbb";
	cout << "str4: " << str4 << endl;
	str4 += str3;
	cout << "str4: " << str4 << endl;

	cout << str4.Size() << endl;

	MyString str5;
	cin >> str5;
	cout << str5 << endl;

	MyString str6(7, 'h');
	cout << str6 << endl;
}


int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	test1();


	cout << endl;
	system("pause");
	return 0;
}
