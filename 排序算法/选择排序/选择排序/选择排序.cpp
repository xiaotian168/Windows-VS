#include<iostream>
using namespace std;

//选择排序
void test1(int arr[], const int &len)
{
	if (len <= 1)
	{
		return;
	}

	for (int i = 0; i < len - 1; ++i)
	{
		int min = i;	//min作为开始比较最小值的下标
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[min] > arr[j])	//升序
			{
				min = j; //更新最小值下标
			}
		}
		if (min != i)	//说明需要交换值
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

//遍历
void Foreach(int arr[], const int &len)
{
	if (len <= 0)
	{
		return;
	}

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	int arr[] = {1,7,3,6,2,5,4};
	int len = sizeof(arr) / sizeof(arr[0]);
	test1(arr, len);
	Foreach(arr, len);

	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}
