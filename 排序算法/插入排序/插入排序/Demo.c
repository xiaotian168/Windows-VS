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

	for (int i = 1; i < len; ++i)	//��ʼarr[0]��Ϊ�������У����������Ԫ����Ϊ��������
	{
		if (arr[i] > arr[i-1])	//ÿ���жϵ�ǰԪ�غ�ǰ���������е����һ��Ԫ�ع�ϵ��������н���
		{
			int tmp = arr[i];	//�ȱ��浱ǰԪ��ֵ
			int j;
			for (j = i - 1; j >= 0 && tmp > arr[j]; --j)	//�Ӻ���һ�α����������У����Һ͵�ǰԪ�رȽϣ�С���������ƣ�
			{
				arr[j + 1] = arr[j];
			}

			arr[j+1] = tmp;	//����ǰԪ�ص�ֵ���뵽���ƺ�ճ�����λ����
		}
		
	}

}

int main(void)
{
	/*******************************************************/
	/*
			��������
	*/
	/*******************************************************/
	int arr[] = { 9,7,1,0,2,8,5,3,6,4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, len);

	printf("���������飺\n");
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}
