#pragma once
#include<iostream>
#include"Person.h"

class SmartPointer
{
public:
	SmartPointer(Person *person);
	~SmartPointer();
	
	//����ָ�������(*��->)
	Person* operator->();
	Person& operator*();

private:
	Person *person;
};