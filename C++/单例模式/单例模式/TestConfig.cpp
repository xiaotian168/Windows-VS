#include<iostream>
#include<string>
#include"Config.h"
using namespace std;


int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	Config *c1 = Config::getInstance();
	Config *c2 = Config::getInstance();
	
	cout << (int)c1 << endl;
	cout << (int)c2 << endl;
	cout << sizeof(Config) << endl;

	cout << endl;
	system("pause");
	return 0;
}
