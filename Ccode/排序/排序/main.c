#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//√∞≈›≈≈–Ú“ª
void paixu1(int *arr, unsigned len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
//√∞≈›≈≈–Ú∂˛
void paixu2(int *arr, unsigned len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main()
{
	int arr[] = { 1,3,5,7,9,0,2,4,6,8 };

	long start = clock();
	paixu1(arr, 10);
	long end = clock();
	printf("≈≈–Ú”√ ±: %ld\n", end - start);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	//printf("hello world\n");
	system("pause");
	return 0;
}
