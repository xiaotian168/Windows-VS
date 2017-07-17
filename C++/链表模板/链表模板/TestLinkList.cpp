#include<iostream>
#include<string>
#include"LinkList.hpp"
using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

//��������α�������º�����������һ���ࣩ
struct myForeach
{
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//���Ի������͵�����
void test01()
{
	LinkList<int> list;
	list.Insert(0, 1);
	list.Insert(0, 2);
	list.Insert(0, 3);
	list.Insert(0, 4);

	//1.��������������
	list.Foreach(myForeach());
	cout << endl;

	//2.����ָ��������
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

//�ȽϺ���������
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

//�����Զ�����������
void test2()
{
	LinkList<Person> list;
	list.Insert(0, Person("aaa", 10));
	list.Insert(0, Person("bbb", 20));
	list.Insert(0, Person("ccc", 30));
	list.Insert(0, Person("ddd", 40));
	list.Insert(0, Person("eee", 50));

	//list.Foreach(Print());	//������������������������Ĭ�Ϲ��������������
	//cout << endl;

	Print print;
	list.Foreach(print);	//��������(��ʵ��������һ������)����������
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
