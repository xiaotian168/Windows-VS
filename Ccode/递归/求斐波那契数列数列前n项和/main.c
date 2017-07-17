#include<stdio.h>
#include<stdlib.h>

int number(int n)	//返回斐波那契数列第n项的值、  递归函数
{
	if (1 == n || 2 == n)
		return 1;
	return number(n - 1) + number(n - 2);
} 

int sum(int n)	//将所有的项相加求和
{
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += number(i);
	}
	return sum;
}

int main01()	//调用递归函数
{
	/*************************************************************/
	/*
		斐波那契数列：
		1 1 2 3 5 8 13 21 34 ......
	*/
	/************************************************************/
	int n;
	printf("input:");
	scanf("%d", &n);
	printf("sum = %d\n", sum(n));

	system("pause");
	return 0;
}


int main()	//不使用递归函数求斐波那契数列的每项值
{
	int n;
	int value[3] = { 0 };
	value[0] = 1;
	value[1] = 1;
	printf("input:");
	scanf("%d", &n);
	if (n < 1)
		printf("input error! USAGE: n > 0\n");
	else if (n == 1 || n == 2)
	{
		printf("%d\n", 1);
		system("pause");
		return 0;
	}
	else
	{
		for (int i = 3; i <= n; ++i)
		{
			value[2] = value[0] + value[1];
			value[0] = value[1];
			value[1] = value[2];
		}	
	}

	printf("%d\n", value[2]);

	system("pause");
	return 0;
}
