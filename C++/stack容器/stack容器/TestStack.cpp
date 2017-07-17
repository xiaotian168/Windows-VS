#include<iostream>
#include<string>
#include<stack>
using namespace std;

void test01()
{
	stack<int> s;
	//元素入栈
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout << s.top() << "\n";
	s.pop();
	cout << s.top() << "\n";

	cout << "当前栈大小为: " << s.size() << endl;
}

int main()
{
	/*******************************************************/
	/*
		没有迭代器
	*/
	/*******************************************************/
	test01();

	cout << endl;
	system("pause");
	return 0;
}
