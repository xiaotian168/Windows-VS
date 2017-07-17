#include<iostream>
#include<string>
#include<queue>
using namespace std;

void test01()
{
	queue<int> q;
	q.push(7);
	q.push(6);
	q.push(5);
	q.push(4);
	q.push(3);

	cout << q.back() << endl;	//获取队尾元素
	cout << q.front() << endl;	//获取队头元素

	q.pop();	//队头元素出队
	cout << q.front() << endl;

	cout << "size:" << q.size() << endl;
}

int main()
{
	/*******************************************************/
	/*
		Queue所有元素的进出都必须符合”先进先出”的条件，
		只有queue的顶端元素，才有机会被外界取用。
		Queue不提供遍历功能，也不提供迭代器。
	*/
	/*******************************************************/
	test01();

	cout << endl;
	system("pause");
	return 0;
}
