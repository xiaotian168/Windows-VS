#include<iostream>
using namespace std;

//ѡ������
void test1(int arr[], const int &len)
{
	if (len <= 1)
	{
		return;
	}

	for (int i = 0; i < len - 1; ++i)
	{
		int min = i;	//min��Ϊ��ʼ�Ƚ���Сֵ���±�
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[min] > arr[j])	//����
			{
				min = j; //������Сֵ�±�
			}
		}
		if (min != i)	//˵����Ҫ����ֵ
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
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
