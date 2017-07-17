#include<stdio.h>
#include<stdlib.h>

int is0ddNumber(unsigned int number)
{
	//if (number %= 2)	//是奇数
	//	return 0;
	//else    //不是奇数
	//	return 1;
	return (number %= 2) ? 0 : 1;
}

int main()
{
	/*********************************************************/
	/*
		自定义一个函数； 要求：判断是否为奇数

		奇数。
		函数原型 int isOddNumber(unsigned int number);
		函数功能 判断参数number是否是奇数 奇数判断依据是是否能够被2整除。
		函数返回值 如果是奇数返回0;如果不是奇数返回1
	*/
	/*********************************************************/
	int n;
	printf("input:");
	scanf("%d", &n);
	if (n < 0)
	{
		printf("input error! USAGE: n > 1\n");
		system("pause");
		return 1;
	}

	printf("%d\n",is0ddNumber(n));	//调用函数,并且打印函数的返回值

	system("pause");
	return 0;
}