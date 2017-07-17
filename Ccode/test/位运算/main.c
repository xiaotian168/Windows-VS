#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	int arr[] = { 1, 2, 3, 1 };
	int m = arr[0];
	int n = arr[3];
	int k = m ^ n;
	printf("%d\n", k);
	printf("\n");
	system("pause");
	return 0;
}
