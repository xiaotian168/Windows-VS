#include<iostream>
#include<map>
#include<set>
using namespace std;

class Employee;

//��ʾĳ����Ա��������Ϣ
void ShowDepartmentWorkers(multimap<int, Employee> &groups, const int &depId)
{
	multimap<int, Employee>::iterator pos = groups.find(depId); //���ص�һ������keyֵpair����ĵ�ַ
	int cnt = groups.count(depId);  //������������keyֵ�ĸ���
	
}

class Com;

struct mySort
{
	bool operator()(/*const pair<*/string/*, int>*/ &p1, /*const pair<*/string/*, int>*/ &p2)
	{
		return p1/*.first*/ > p2/*.first*/;
	}
};

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	map<string, int, mySort> m = { { "aaa", 11 },{ "bbb", 22 },{ "ccc", 33 },{ "ddd", 44 } };
	m.insert(pair<string, int>("bbb", 2));
	m["bbb"] = 2;


	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}
