#include<iostream>
#include<string>
#include"LinkList.hpp"
using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

//函数对象（伪函数；仿函数；本质是一个类）
struct myForeach
{
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//测试基本类型的数据
void test01()
{
	LinkList<int> list;
	list.Insert(0, 1);
	list.Insert(0, 2);
	list.Insert(0, 3);
	list.Insert(0, 4);

	//1.函数对象做参数
	list.Foreach(myForeach());
	cout << endl;

	//2.函数指针做参数
	list.Foreach(myPrint);
	cout << endl;
}

struct Person
{
	Person(string name = "", int age = 0) { this->name = name; this->age = age; }
	string name;
	int age;
};

void printPerson(const Person &p1)
{
	cout << "name: " << p1.name << "  age: " << p1.age << endl;
}

struct Print
{
	void operator()(const Person &p1)
	{
		cout << "name: " << p1.name << "  age: " << p1.age << endl;
	}
};

//比较函数对象类
//struct Compare
//{
//	bool operator()(const Person &p2)
//	{
//		if (this->mP.name == p2.name)
//		{
//			return true;
//		}
//
//		return false;
//	}
//
//	Person mP;
//};


bool myCompare(const Person &p1, const Person &p2)
{
	return p1.name == p2.name ? true : false;
}

//测试自定义类型数据
void test2()
{
	LinkList<Person> list;
	list.Insert(0, Person("aaa", 10));
	list.Insert(0, Person("bbb", 20));
	list.Insert(0, Person("ccc", 30));
	list.Insert(0, Person("ddd", 40));
	list.Insert(0, Person("eee", 50));

	//list.Foreach(Print());	//匿名对象做函数参数；调用默认构造产生匿名对象
	//cout << endl;

	Print print;
	list.Foreach(print);	//函数对象(类实例化出的一个对象)做函数参数
	cout << endl;

	list.RemoveByPos(0);
	list.RemoveByPos(3);
	list.Foreach(printPerson);
	cout << endl;

	list.Insert(0, Person("ccc", 30));
	list.Insert(2, Person("ccc", 30));
	list.Foreach(printPerson);
	cout << endl;

	list.RemoveByVal(Person("ccc", 30), myCompare);

	list.Foreach(printPerson);

}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	test2();

	cout << endl;
	system("pause");
	return 0;
}
