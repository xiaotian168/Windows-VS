#include<stdio.h>
#include<stdlib.h>

int main()
{
	/**************************************************************/
	/*
		编写代码求出给定的整数中bit位上值为1的位数
	*/
	/*************************************************************/
	int n;
	printf("input: ");
	scanf("%d", &n);

	if (n < 0)
	{
		printf("input error! USAGE: n > 0\n");
		system("pause");
		return 1;
	}
	int count = 0;
	while (n)
	{
		if (1 == n % 2)
			count++;
		n /= 2;
	}
	printf("%d\n", count);

	system("pause");
	return 0;
}