#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

struct myPrint:public binary_function<int, int, void>
{
	void operator()(const int &val, const int &param)const
	{
		cout << val + param << " ";
	}
};

//1.bind1st bind2nd 函数对象适配器（绑定函数对象参数）
void test01()
{
	vector<int> v = { 1,3,2,6,4,7,5 };
	for_each(v.begin(), v.end(), bind2nd(myPrint(), 100));
	//绑定适配器可以把二元函数对象适配成一元函数对象
	//bind1st将100绑定函数对象的第一个参数上  bind2nd把100绑定到函数对象的第二个参数上

}

//2. not1 not2 取反适配器
void test02()
{
	//如果是二元谓词 使用not2取反适配
	//如果是一元谓词 使用not1取反适配
	vector<int> v = { 1, 2, 3, 4, 5, 6 };
	sort(v.begin(), v.end(), greater<>());
	//lambda表达式  [](int val,int val){  }
	for_each(v.begin(), v.end(), [](const int &val) {cout << val << " "; });
	cout << endl;
}

//3. ptr_fun普通函数适配器
void PrintInfo(const int &val)
{
	cout << val << " ";
}
void PrintInfo2(int val1, int param)
{
	cout << val1 + param << " ";
}

void test03()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6 };
	//bin2nd bind1st只能对函数对象进行适配，所以不能直接对普通函数适配
	//1. 先把普通函数转换为函数对象 ptr_fun(myPrintFunction)
	//2. 再适配转换后的函数对象
	//for_each(v.begin(), v.end(), ptr_fun(PrintInfo));
	for_each(v.begin(), v.end(), bind1st(ptr_fun(PrintInfo2), 10));
}

//4. mem_fun mem_fun_ref 成员函数适配器
class Person
{
public:
	Person(string name, int age)
	{
		mName = name;
		mAge = age;
	}
	~Person()
	{
		cout << "析构函数被调用\n";
	}
	void printPerson()
	{
		cout << "Name:" << mName << " Age:" << mAge << endl;
	}
public:
	string mName;
	int mAge;
};
void test04()
{
	//mem_fun mem_fun_ref 如果容器存储的是对象或者对象指针，我们希望使用成员函数来操作数据
	//如果是对象实体 使用mem_fun_ref
	//如果存储的是对象指针， 使用mem_fun
#if 0
	vector<Person> v;
	v.push_back(Person("aaa", 10));
	v.push_back(Person("bbb", 20));
	v.push_back(Person("ccc", 30));
	v.push_back(Person("aaa", 40));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::printPerson));
#endif
	vector<Person*> v;
	v.push_back(new Person("aaa", 10));
	v.push_back(new Person("aaa", 10));
	v.push_back(new Person("aaa", 10));
	v.push_back(new Person("aaa", 10));
	for_each(v.begin(), v.end(), mem_fun(&Person::printPerson));

	//释放内存
	for (auto &val : v)	//更高效
	{
		delete val;
	}
	/*for (auto val : v)
	{
		delete val;
	}*/

}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	//test01();
	//test02();
	//test03();
	test04();

	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}
