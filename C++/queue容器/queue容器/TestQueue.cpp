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

	cout << q.back() << endl;	//��ȡ��βԪ��
	cout << q.front() << endl;	//��ȡ��ͷԪ��

	q.pop();	//��ͷԪ�س���
	cout << q.front() << endl;

	cout << "size:" << q.size() << endl;
}

int main()
{
	/*******************************************************/
	/*
		Queue����Ԫ�صĽ�����������ϡ��Ƚ��ȳ�����������
		ֻ��queue�Ķ���Ԫ�أ����л��ᱻ���ȡ�á�
		Queue���ṩ�������ܣ�Ҳ���ṩ��������
	*/
	/*******************************************************/
	test01();

	cout << endl;
	system("pause");
	return 0;
}
