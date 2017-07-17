#pragma once
#include<iostream>

class Person
{
public:
	Person();
	Person(const int &n);
	Person(const Person &obj);
	void Test();
	~Person();
};
