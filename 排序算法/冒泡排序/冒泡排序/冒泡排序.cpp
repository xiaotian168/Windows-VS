#include<iostream>
using namespace std;

//ð������һ
void test1(int arr[], const int &len)
{
	if (len <= 1)
	{
		return;
	}

	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[i] < arr[j])	//����
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

//ð�������
void test2(int arr[], const int &len)
{
	if (len <= 1)
	{
		return;
	}

	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (arr[j] > arr[j+1])	//����
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

//����
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
}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	int arr[] = { 1, 3, 9, 7, 8, 6, 2, 5, 4};
	int len = sizeof(arr) / sizeof(arr[0]);
	test2(arr, len);
	Foreach(arr, len);
	cout << endl;
	test1(arr, len);
	Foreach(arr, len);

	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}
