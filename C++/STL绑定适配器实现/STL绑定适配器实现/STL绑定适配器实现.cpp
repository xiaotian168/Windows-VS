#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

//自定义函数对象
struct myPrint
{
	void operator()(int v, int param)
	{
		cout << v << "\t" << param << "\n";
	}
};

//适配器类
struct myBind:public binary_function<int, int, void>
{
	myBind(myPrint p, int param)
	{
		mP = p;
		mParam = param;
	}

	void operator()(int param)
	{
		mP(mParam, param);
	}

	myPrint mP;
	int		mParam;
};

//绑定适配器函数
myBind myBind1st(myPrint p, int param)
{
	return myBind(p, param);
}

void test()
{
	vector<int> v = {1, 9, 5, 3, 7};
	for_each(v.begin(), v.end(), myBind(myPrint(), 100));
}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	test();

	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}
