#pragma once
#include<iostream>
#include"Person.h"

class SmartPointer
{
public:
	SmartPointer(Person *person);
	~SmartPointer();
	
	//ÖØÔØÖ¸ÕëÔËËã·û(*¡¢->)
	Person* operator->();
	Person& operator*();

private:
	Person *person;
};