#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double getCount(int n)
{
	if (n == 1)
		return 1;
	return getCount(n - 1) * 2;
}

int main(void)
{
	/*******************************************************/
	/*
		�и��������������һֻ������ÿ��һ�������������ͻᷭһ����
		����������Զ����л��30���ʱ��������ȫ������������, 
		���ʵ�23�������ռ�����صļ���֮����
	*/
	/*******************************************************/
	double ret = getCount(23) / getCount(30);
	printf("%lf", ret);

	printf("\n");
	system("pause");
	return 0;
}
