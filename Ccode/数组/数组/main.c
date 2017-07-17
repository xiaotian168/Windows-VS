#include<stdio.h>
#include<stdlib.h>

int main()	
{
	/************************************************************/
	/*
		求数组中第二大的元素的值。
	*/
	/***********************************************************/
	int arr[10] = {1,0,5,9,3,2,8,6,7,4};
	int max = arr[0];	//最大值
	int sec_max = arr[1];	//第二大

	if (max < sec_max)	//保证sec_max是第二大值
	{
		int temp = max;
		max = sec_max;
		sec_max = temp;
	}

	for (int i = 2; i < 10; ++i)	//遍历数组找出第二大值
	{
		if (arr[i] > max)
		{
			sec_max = max;
			max = arr[i];
		}
		else if (arr[i] > sec_max)
			sec_max = arr[i];
	}
	printf("The sec_max = %d\n", sec_max);

	system("pause");
	return 0;
}