#include<stdio.h>
#include<stdlib.h>

int main()
{
	/************************************************************/
	/*
		有1个数组:
		int arr[] = {10,20,30,40,50,60,70,80,90,100};

		使用不同的方法遍历数组元素
	*/
	/************************************************************/
	int arr[] = { 10,20,30,40,50,60,70,80,90,100 };
	int len = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < len; ++i)	//使用arr[i]方式遍历
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < len; ++i)		//使用*(arr+i)方式遍历
	{
		printf("%d ", *(arr+i));
	}
	printf("\n");

	int *p = arr;
	for (int i = 0; i < len; ++i)		//使用p[i]方式遍历
	{
		printf("%d ", p[i]);
	}
	printf("\n");

	for (int i = 0; i < len; ++i)		//使用*(p+i)方式遍历
	{
		printf("%d ", *(p+i));
	}
	printf("\n");

	for (int i = 0; i < len; ++i)		//使用*p++方式遍历
	{
		printf("%d ", *p++);
	}
	printf("\n");


	system("pause");
	return 0;
}