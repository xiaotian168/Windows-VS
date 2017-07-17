#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//自定义数据类型的基类(此例用于绑定3个参数)
//模板基类
template<class First, class Second, class Third, class Fourth, class Result>
struct MyStructBase
{
	//只是为模板参数类型起个别名
	typedef First	Fir;
	typedef Second	Sec;
	typedef Third	Thi;
	typedef Fourth	Fou;
	typedef Result	Res;
};

//自定义数据类型；继承基类；明确指定操作数据类型
struct Person:public MyStructBase<int, int, int, int, void>
{
	void operator()(const int &containersDate, const int &param2, const int &param3, const int &param4)
	{
		cout << "容器数据:" << containersDate << "  绑定参数数据1:" << param2
			<< "  绑定参数数据2:" << param3 << "  绑定参数数据3:" << param4 << endl;
	}
};

//适配器类模板；用于不同接口适配成合适的接口；（本例把4个接口的绑定为一个接口的供算法函数调用）
//即：把多元的函数对象和参数绑定在一起；（本类实例化的对象为一元函数对象）
template<class FuncTy>
struct OneFunction
{
	typedef typename FuncTy::Fir FirTy;
	typedef typename FuncTy::Sec SecTy;
	typedef typename FuncTy::Thi ThiTy;
	typedef typename FuncTy::Fou FourTy;
	typedef typename FuncTy::Res ResTy;

	OneFunction(const FuncTy &funobj, const SecTy &sec, const ThiTy &th, const FourTy &four)
		:mFucObj(funobj), mSec(sec), mTh(th), mFour(four)
	{}


	ResTy operator()(const FirTy &containersDate)
	{
		//注意：这里返回的是一元函数对象的调用结果
		//不是：FirTy(containersDate, mSec, mTh, mFour);
		return mFucObj(containersDate, mSec, mTh, mFour);
	}

	FuncTy	mFucObj;
	SecTy	mSec;
	ThiTy	mTh;
	FourTy	mFour;
};

//适配器函数模板；传入多元函数对象以及要绑定的数据；返回一个一元函数对象
template<class FuncTy, class SecTy, class ThrTy, class FourTy>
OneFunction<FuncTy> myBind4params(const FuncTy &Person, const SecTy &param2, const ThrTy &param3, const FourTy &param4)
{
	return OneFunction<FuncTy>(Person, param2, param3, param4);
}

void test()
{
	vector<int> v = {1,3,5,7,9};
	for_each(v.begin(), v.end(), myBind4params(Person(), 11, 22, 33));
	bind2nd
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
