#include<stdio.h>
#include<stdlib.h>

int number(int n)	//����쳲��������е�n���ֵ��  �ݹ麯��
{
	if (1 == n || 2 == n)
		return 1;
	return number(n - 1) + number(n - 2);
} 

int sum(int n)	//�����е���������
{
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += number(i);
	}
	return sum;
}

int main01()	//���õݹ麯��
{
	/*************************************************************/
	/*
		쳲��������У�
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


int main()	//��ʹ�õݹ麯����쳲��������е�ÿ��ֵ
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
