#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;

/*
��ֵ���ң��ҵ�����Ԫ�صĵ�������ʧ�ܷ���β�������
find(iterator beg, iterator end, value)
*/
void test01()
{
	vector<int> v = { 1,5,4,3,2 };
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "û���ҵ�" << "\n";
		return;
	}
	cout << *it << endl;
	

}

/*
���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����
adjacent_find(iterator beg, iterator end, _callback);
*/
void test02()
{
	//���������ظ�Ԫ�� 1 2 3 4 4 5 6 7
	vector<int> v = { 1, 2, 3,4, 4, 5 };
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "û���ҵ�" << endl;
		return;
	}

	cout << *it << "\n";
	//���˵vector�зŵ��Ƕ���
	//1. ����==�������
	//2. �ֶ������������ıȽϹ���(��������)

}

/*
���ֲ����㷨
bool binary_search(iterator beg, iterator end, value);
*/
void test03()
{
	//���ֲ��ҷ���ʹ��ǰ�����б����������
	//bianary_searchĬ�ϵ���������������� 1 2 3 4 5 6 7 8
	vector<int> v = { 1, 2, 3, 4, 5 };
	sort(v.begin(), v.end(), greater<>());
	//for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
	bool flag = binary_search(v.begin(), v.end(), 3, [](const int &val1, const int &val2)
	{
		return val1 > val2;
	});
	//bool flag = binary_search(v.begin(), v.end(), 3, greater<>());
	if (flag)
	{
		cout << "�ҵ���\n";
	}
	else
	{
		cout << "û���ҵ�\n";
	}

}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	//test01();
	//test02();
	test03();

	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}
