#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student();
	~Student();
	void func()const
	{
		cout << "Hello World" << endl;
	}
	void test()
	{
		(*this).m_iA = 10;
		cout << this->m_iA << endl;
	}
private:

public:
	int m_iA;
};

Student::Student()
{
}

Student::~Student()
{
}

int main01()
{
	/*******************************************************/
	/*
		
	*/
	/*******************************************************/
	const Student s1;
	s1.func();
	s1.m_iA;

	Student s2;
	s2.test();

	cout << endl;
	system("pause");
	return 0;
}

class Teacher
{
public:
	Teacher();
	~Teacher();
	void func()
	{
		cout << "Hello World" << endl;
	}

private:

};

Teacher::Teacher()
{
}

Teacher::~Teacher()
{
}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	cout << sizeof(Teacher) << endl;
	Teacher *t1 = NULL;
	t1->func();		//func(Teacher *const this);

	cout << endl;
	system("pause");
	return 0;
}
