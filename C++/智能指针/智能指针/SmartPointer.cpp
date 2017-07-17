#include"SmartPointer.h"

SmartPointer::SmartPointer(Person *person)
{
	this->person = person;
}

SmartPointer::~SmartPointer()
{
	if (this->person != NULL)
	{
		delete this->person;
		this->person = NULL;
	}
}

//ÖØÔØÖ¸ÕëÔËËã·û(*¡¢->)
Person* SmartPointer::operator->()
{
	return person;
}

Person& SmartPointer::operator*()
{
	return *person;
}
