#include<iostream>
#include<string>
#include<stack>
using namespace std;

void test01()
{
	stack<int> s;
	//Ԫ����ջ
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout << s.top() << "\n";
	s.pop();
	cout << s.top() << "\n";

	cout << "��ǰջ��СΪ: " << s.size() << endl;
}

int main()
{
	/*******************************************************/
	/*
		û�е�����
	*/
	/*******************************************************/
	test01();

	cout << endl;
	system("pause");
	return 0;
}
