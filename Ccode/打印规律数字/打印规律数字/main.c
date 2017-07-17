#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	/*************************************************/
	/*
		input:6
		结果
			1	2	3	4	5	6		//相差2的0次幂
			3	5	7	9	11			//相差2的1次幂
			8	12	16	20				//相差2的2次幂
			20	28	36					。。。。。。。
			48	64
			112

		思路：每行相邻数值之间 相差2的i次方

	*/
	/*************************************************/
	int n;	
	printf("input: ");
	scanf("%d", &n);	//接收用户输入的数字
	if (n < 1)
	{
		printf("input error! USAGE: n > 0\n");
		system("pause");
		return 1;
	}
	int num = 0;	//每行的数字
	int val = 1;	//每行第一个数字
	for (int i = 0; i < n; ++i)
	{
		num = val;	//获取每行第一个数字
		for (int j = i; j < n; ++j)	//打印每行
		{
			printf("%-6d", num);
			num += pow(2, i);
		}
		val += val + pow(2, i);		//内循环一次后，重新获取下一行第一个数字
		printf("\n");
	}
	system("pause");
	return 0;
}