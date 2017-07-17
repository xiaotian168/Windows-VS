#include<iostream>
#include<string>
#include<deque>
#include<vector>
using namespace std;

//遍历双向队列
void printDeque(deque<int> &dq)
{
	for (auto val : dq)
	{
		cout << val << " ";
	}
	cout << endl;

	/*for (auto dstart = dq.end(); dstart != dq.begin(); --dstart)
	{
		cout << dstart[-1] << " ";
	}*/
}

void test01()
{
	/*deque<int> d;
	d.resize(10);
	cout << "size: " << d.size() << endl;
	printDeque(d);*/
	int arr[] = { 1,3,9,5,7 };
	deque<int> d(arr, arr + sizeof(arr) / sizeof(int));
	cout << "size: " << d.size() << endl;
	printDeque(d);
	//vector<int> v = {10,20,30,40};	//列表初始化
	//d.assign(v.begin(), v.end());
	//printDeque(d);

}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	test01();

	cout << endl;
	system("pause");
	return 0;
}
