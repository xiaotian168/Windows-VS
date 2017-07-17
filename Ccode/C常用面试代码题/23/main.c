#include<stdio.h>
#include<stdlib.h>

int main()
{
	/**************************************************************/
	/*
		斐波纳契数列的非递归代码实现。
	*/
	/*************************************************************/
	int n;
	unsigned long long value = 0;		//value为对应项的值
	int n1 = 1, n2 = 1;
	printf("input:");
	scanf("%d", &n);
	if (n < 1)
	{
		printf("input error! USAGE: n > 0\n");
		system("pause");
		return 0;
	}
	if (n == 1)
		printf("%d", n1);
	else if (n == 2)
		printf("%d %d", n1, n2);
	else
	{
		printf("%d %d ", n1, n2);
		for (int i = 3; i <= n; ++i)
		{
			value = n1 + n2;
			printf("%d ", value);
			n1 = n2;
			n2 = value;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}