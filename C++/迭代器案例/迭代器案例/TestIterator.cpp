#include<iostream>
#include<string>
#include<vector>
#include<algorithm>	//�㷨ͷ�ļ�
using namespace std;

//STL�еĵ������������㷨
void test1()
{
	//ʵ����һ��vector����
	vector<int> v;	//STL�еı�׼����֮һ����̬����
	//��vector�����в�������
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//��������
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = v.begin();
	auto endit = v.end();
	//ͳ��Ԫ���������г��ֵĸ���
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

//vector(��̬����)�洢�������ָ��
void test2()
{
	//�洢�����
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

	//�洢��ָ��
	vector<Person*> v1;	//ʵ����һ������(������)
	//��������
	Person p1 = Person("ddd", 40);
	Person p2 = Person("ccc", 30);
	Person p3 = Person("bbb", 20);
	Person p4 = Person("aaa", 10);
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);

	//��������
	auto it = v1.begin();
	while (it != v1.end())
	{
		cout << *(*it) << endl;
		++it;
	}

}

//����Ƕ������
void test3()
{
	vector<vector<Person>> v;	//������Ƕ������
	//���������ʼ������
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

	//���������ʼ������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//����
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
		������������:
		���������	�ṩ�����ݵ�ֻ������	ֻ����֧��++��==����=
		���������	�ṩ�����ݵ�ֻд����	ֻд��֧��++
		ǰ�������	�ṩ��д������������ǰ�ƽ�������	��д��֧��++��==����=
		˫�������	�ṩ��д������������ǰ��������	��д��֧��++��--��
		������ʵ�����	�ṩ��д����������������������ƶ�	��д��֧��++��--��[n]��-n��<��<=��>��>=
	*/
	/*******************************************************/
	//test1();
	//test2();
	test3();

	cout << endl;
	system("pause");
	return 0;
}
