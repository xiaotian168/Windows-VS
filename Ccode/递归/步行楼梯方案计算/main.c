#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

long double value(int n)
{
	if (n == 1)
		return (long double)1;
	else if(n == 2)
		return	(long double)2;
	else
		return value(n - 1) + value(n - 2);
}

int main()
{
	/************************************************************/
	/*
		Ҫ��
			һ��������Ҫ��¥�����ϵ�¥������ȥ��
			ÿһ��ֻ���߳�1����������������¥�ݲ���Ϊ100����
			����������¥���ܹ��ж������߷�?

		���ɣ�
		1��¥�ݣ�1
		2��¥�ݣ�2
		3��¥�ݣ�3
		4��¥�ݣ�5
		5��¥�ݣ�8
			n��¥�ݣ��߷���n-1��¥�ݵ��߷�����n-2��¥�ݵ��߷���
	*/
	/************************************************************/
	int n;
	long double pro = 0.0;
	printf("input: ");
	scanf("%d", &n);

	long int start = clock();
	printf("%.1lf\n", value(n));
	long int end = clock();

	printf("�����ʱ:%ld\n", end-start);
	system("pause");
	return 0;
}