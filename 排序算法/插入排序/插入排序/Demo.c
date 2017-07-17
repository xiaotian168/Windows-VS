#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void InsertSort(int arr[], int len)
{
	if (NULL == arr)
	{
		return;
	}

	if (len < 0)
	{
		return;
	}

	for (int i = 1; i < len; ++i)	//开始arr[0]作为有序序列，后面的数组元素作为无序序列
	{
		if (arr[i] > arr[i-1])	//每次判断当前元素和前面无序序列的最后一个元素关系（这里进行降序）
		{
			int tmp = arr[i];	//先保存当前元素值
			int j;
			for (j = i - 1; j >= 0 && tmp > arr[j]; --j)	//从后面一次遍历有序序列；并且和当前元素比较（小就依次右移）
			{
				arr[j + 1] = arr[j];
			}

			arr[j+1] = tmp;	//将当前元素的值插入到右移后空出来的位置上
		}
		
	}

}

int main(void)
{
	/*******************************************************/
	/*
			插入排序
	*/
	/*******************************************************/
	int arr[] = { 9,7,1,0,2,8,5,3,6,4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, len);

	printf("排序后的数组：\n");
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}
