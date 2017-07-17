#include<iostream>
#include<map>
#include<set>
using namespace std;

class Employee;

//显示某部门员工分组信息
void ShowDepartmentWorkers(multimap<int, Employee> &groups, const int &depId)
{
	multimap<int, Employee>::iterator pos = groups.find(depId); //返回第一个满足key值pair对组的地址
	int cnt = groups.count(depId);  //返回所有满足key值的个数
	
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
