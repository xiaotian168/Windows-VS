#include<stdio.h>
#include<stdlib.h>

int main()
{
	/************************************************************/
	/*
		��1������:
		int arr[] = {10,20,30,40,50,60,70,80,90,100};

		ʹ�ò�ͬ�ķ�����������Ԫ��
	*/
	/************************************************************/
	int arr[] = { 10,20,30,40,50,60,70,80,90,100 };
	int len = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < len; ++i)	//ʹ��arr[i]��ʽ����
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < len; ++i)		//ʹ��*(arr+i)��ʽ����
	{
		printf("%d ", *(arr+i));
	}
	printf("\n");

	int *p = arr;
	for (int i = 0; i < len; ++i)		//ʹ��p[i]��ʽ����
	{
		printf("%d ", p[i]);
	}
	printf("\n");

	for (int i = 0; i < len; ++i)		//ʹ��*(p+i)��ʽ����
	{
		printf("%d ", *(p+i));
	}
	printf("\n");

	for (int i = 0; i < len; ++i)		//ʹ��*p++��ʽ����
	{
		printf("%d ", *p++);
	}
	printf("\n");


	system("pause");
	return 0;
}