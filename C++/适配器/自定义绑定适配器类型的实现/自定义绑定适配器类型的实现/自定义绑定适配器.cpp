#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//�Զ����������͵Ļ���(�������ڰ�3������)
//ģ�����
template<class First, class Second, class Third, class Fourth, class Result>
struct MyStructBase
{
	//ֻ��Ϊģ����������������
	typedef First	Fir;
	typedef Second	Sec;
	typedef Third	Thi;
	typedef Fourth	Fou;
	typedef Result	Res;
};

//�Զ����������ͣ��̳л��ࣻ��ȷָ��������������
struct Person:public MyStructBase<int, int, int, int, void>
{
	void operator()(const int &containersDate, const int &param2, const int &param3, const int &param4)
	{
		cout << "��������:" << containersDate << "  �󶨲�������1:" << param2
			<< "  �󶨲�������2:" << param3 << "  �󶨲�������3:" << param4 << endl;
	}
};

//��������ģ�壻���ڲ�ͬ�ӿ�����ɺ��ʵĽӿڣ���������4���ӿڵİ�Ϊһ���ӿڵĹ��㷨�������ã�
//�����Ѷ�Ԫ�ĺ�������Ͳ�������һ�𣻣�����ʵ�����Ķ���ΪһԪ��������
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
		//ע�⣺���ﷵ�ص���һԪ��������ĵ��ý��
		//���ǣ�FirTy(containersDate, mSec, mTh, mFour);
		return mFucObj(containersDate, mSec, mTh, mFour);
	}

	FuncTy	mFucObj;
	SecTy	mSec;
	ThiTy	mTh;
	FourTy	mFour;
};

//����������ģ�壻�����Ԫ���������Լ�Ҫ�󶨵����ݣ�����һ��һԪ��������
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
