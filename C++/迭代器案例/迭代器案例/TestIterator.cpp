#include<iostream>
#include<string>
#include<vector>
#include<algorithm>	//算法头文件
using namespace std;

//STL中的迭代、容器、算法
void test1()
{
	//实例化一个vector对象
	vector<int> v;	//STL中的标准容器之一：动态数组
	//向vector对象中插入数据
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//遍历数据
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = v.begin();
	auto endit = v.end();
	//统计元素在容器中出现的个数
	int n = count(it, endit, 7);
	cout << n << endl;
}

class Person
{
	friend ostream& operator<<(ostream& out, const Person &p)
	{
		out << "name: " << p.mName << "\t";
		out << "age: " << p.mAge << "\t";

		return out;
	}

public:
	Person(string name = "", int age = 0)
	{
		this->mAge = age;
		this->mName = name;
	}

private:
	int		mAge;
	string	mName;
};

//vector(动态数组)存储类对象、类指针
void test2()
{
	//存储类对象
	vector<Person> v;
	v.push_back(Person("aaa", 10));
	v.push_back(Person("bbb", 20));
	v.push_back(Person("ccc", 30));
	v.push_back(Person("ddd", 40));
	auto pStart = v.begin();
	auto pEnd = v.end();
	for (; pStart != pEnd; ++pStart)
	{
		cout << (*pStart) << "\n";
	}
	cout << "-------------------------------\n";

	//存储类指针
	vector<Person*> v1;	//实例化一个容器(空数据)
	//插入数据
	Person p1 = Person("ddd", 40);
	Person p2 = Person("ccc", 30);
	Person p3 = Person("bbb", 20);
	Person p4 = Person("aaa", 10);
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);

	//遍历数据
	auto it = v1.begin();
	while (it != v1.end())
	{
		cout << *(*it) << endl;
		++it;
	}

}

//容器嵌套容器
void test3()
{
	vector<vector<Person>> v;	//容器中嵌套容器
	//里层容器初始化数据
	/*vector<Person> v1;
	v1.push_back(Person("aaa", 10));
	v1.push_back(Person("bbb", 20));
	v1.push_back(Person("ccc", 30));
	v1.push_back(Person("ddd", 40));
	vector<Person> v2;
	v2.push_back(Person("aa", 10));
	v2.push_back(Person("bb", 20));
	v2.push_back(Person("cc", 30));
	v2.push_back(Person("dd", 40));
	vector<Person> v3;
	v3.push_back(Person("a", 10));
	v3.push_back(Person("b", 20));
	v3.push_back(Person("c", 30));
	v3.push_back(Person("d", 40));*/
	vector<Person> v1;
	vector<Person> v2;
	vector<Person> v3;
	for (int i = 0; i < 4; ++i)
	{
		v1.push_back(Person("aaa", 10 + i));
		v2.push_back(Person("bbb", 20 + i));
		v3.push_back(Person("ccc", 30 + i));
	}

	//外层容器初始化数据
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//遍历
	auto pStart = v.begin();
	while (pStart != v.end())
	{
		auto pPer = (*pStart).begin();
		while (pPer != (*pStart).end())
		{
			cout << *pPer << "\n";
			++pPer;
		}
		++pStart;
	}
}

int main()
{
	/*******************************************************/
	/*
		迭代器的种类:
		输入迭代器	提供对数据的只读访问	只读，支持++、==、！=
		输出迭代器	提供对数据的只写访问	只写，支持++
		前向迭代器	提供读写操作，并能向前推进迭代器	读写，支持++、==、！=
		双向迭代器	提供读写操作，并能向前和向后操作	读写，支持++、--，
		随机访问迭代器	提供读写操作，并能在数据中随机移动	读写，支持++、--、[n]、-n、<、<=、>、>=
	*/
	/*******************************************************/
	//test1();
	//test2();
	test3();

	cout << endl;
	system("pause");
	return 0;
}
