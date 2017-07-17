#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;

/*
按值查找；找到返回元素的迭代器；失败返回尾后迭代器
find(iterator beg, iterator end, value)
*/
void test01()
{
	vector<int> v = { 1,5,4,3,2 };
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "没有找到" << "\n";
		return;
	}
	cout << *it << endl;
	

}

/*
查找相邻重复元素；返回相邻元素的第一个位置的迭代器
adjacent_find(iterator beg, iterator end, _callback);
*/
void test02()
{
	//查找相邻重复元素 1 2 3 4 4 5 6 7
	vector<int> v = { 1, 2, 3,4, 4, 5 };
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "没有找到" << endl;
		return;
	}

	cout << *it << "\n";
	//如果说vector中放的是对象
	//1. 重载==号运算符
	//2. 手动添加两个对象的比较规则(函数对象)

}

/*
二分查找算法
bool binary_search(iterator beg, iterator end, value);
*/
void test03()
{
	//二分查找法，使用前提序列必须是有序的
	//bianary_search默认的我们序列是升序的 1 2 3 4 5 6 7 8
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
		cout << "找到了\n";
	}
	else
	{
		cout << "没有找到\n";
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
