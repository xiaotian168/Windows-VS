#include<stdio.h>
#include<stdlib.h>

int main()	
{
	/************************************************************/
	/*
		�������еڶ����Ԫ�ص�ֵ��
	*/
	/***********************************************************/
	int arr[10] = {1,0,5,9,3,2,8,6,7,4};
	int max = arr[0];	//���ֵ
	int sec_max = arr[1];	//�ڶ���

	if (max < sec_max)	//��֤sec_max�ǵڶ���ֵ
	{
		int temp = max;
		max = sec_max;
		sec_max = temp;
	}

	for (int i = 2; i < 10; ++i)	//���������ҳ��ڶ���ֵ
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