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
		要求：
			一个人现在要从楼梯下上到楼梯上面去，
			每一步只能走出1步或者两步，建设楼梯步数为100步。
			求解这个人上楼梯总共有多少种走法?

		规律：
		1步楼梯：1
		2步楼梯：2
		3步楼梯：3
		4步楼梯：5
		5步楼梯：8
			n步楼梯，走法：n-1步楼梯的走法加上n-2步楼梯的走法和
	*/
	/************************************************************/
	int n;
	long double pro = 0.0;
	printf("input: ");
	scanf("%d", &n);

	long int start = clock();
	printf("%.1lf\n", value(n));
	long int end = clock();

	printf("计算耗时:%ld\n", end-start);
	system("pause");
	return 0;
}