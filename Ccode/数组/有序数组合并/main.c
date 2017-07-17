#include<stdio.h>
#include<stdlib.h>
#define LEN ((sizeof(arr1)+sizeof(arr2))/4)

int main()
{
	/************************************************************/
	/*
		用代码实现 合并两个增序有序的数组arr1,arr2到arr3中
		并且保持元素增序有序。
		int arr1[] = {1,2,5,7,8};int arr2[]={2,3,4,6,9};
		合并后arr3结果为{1,2,2,3,4,5,6,7,8,9};	

		思路：两个数组依次比较，将小的放入新定义的数组；
			  判断arr1和arr2谁先放完了；
			  将没放完的数组放到新定义数组的后面

	使用宏定义 #define LEN ((sizeof(a1) + sizeof(a2))/4)
	*/
	/***********************************************************/
	int arr1[] = {1,2,5,7,8};
	int arr2[] = {2,3,4,6,9};
	int arr3[LEN] = { 0 };
	int i = 0, j = 0, index = 0;	//i ->arr1下标； j ->arr2下标； index ->arr3下标
	while ((i < sizeof(arr1) / 4) && (j < sizeof(arr2) / 4))	//判断没有数组元素取完，则继续循环
	{
		//谁小谁先放入新的数组
		if (arr1[i] < arr2[j])
			arr3[index++] = arr1[i++];
		else
			arr3[index++] = arr2[j++];
	}
	if (i == sizeof(arr1) / sizeof(arr1[0]))	//判断arr1元素放完
		while (j < (sizeof(arr2)/sizeof(arr2[0])))
			arr3[index++] = arr2[j++];
	else    //arr2 元素放完
		while (i < (sizeof(arr1) / sizeof(arr1[0])))
			arr3[index++] = arr3[i++];
	
	for (int i = 0; i < LEN; ++i)	//打印合并好的有序数组
		printf("%d ", arr3[i]);

	system("pause");
	return 0;
}