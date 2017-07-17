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

//1.bind1st bind2nd �����������������󶨺������������
void test01()
{
	vector<int> v = { 1,3,2,6,4,7,5 };
	for_each(v.begin(), v.end(), bind2nd(myPrint(), 100));
	//�����������԰Ѷ�Ԫ�������������һԪ��������
	//bind1st��100�󶨺�������ĵ�һ��������  bind2nd��100�󶨵���������ĵڶ���������

}

//2. not1 not2 ȡ��������
void test02()
{
	//����Ƕ�Ԫν�� ʹ��not2ȡ������
	//�����һԪν�� ʹ��not1ȡ������
	vector<int> v = { 1, 2, 3, 4, 5, 6 };
	sort(v.begin(), v.end(), greater<>());
	//lambda���ʽ  [](int val,int val){  }
	for_each(v.begin(), v.end(), [](const int &val) {cout << val << " "; });
	cout << endl;
}

//3. ptr_fun��ͨ����������
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
	//bin2nd bind1stֻ�ܶԺ�������������䣬���Բ���ֱ�Ӷ���ͨ��������
	//1. �Ȱ���ͨ����ת��Ϊ�������� ptr_fun(myPrintFunction)
	//2. ������ת����ĺ�������
	//for_each(v.begin(), v.end(), ptr_fun(PrintInfo));
	for_each(v.begin(), v.end(), bind1st(ptr_fun(PrintInfo2), 10));
}

//4. mem_fun mem_fun_ref ��Ա����������
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
		cout << "��������������\n";
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
	//mem_fun mem_fun_ref ��������洢���Ƕ�����߶���ָ�룬����ϣ��ʹ�ó�Ա��������������
	//����Ƕ���ʵ�� ʹ��mem_fun_ref
	//����洢���Ƕ���ָ�룬 ʹ��mem_fun
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

	//�ͷ��ڴ�
	for (auto &val : v)	//����Ч
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
