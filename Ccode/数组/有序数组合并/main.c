#include<stdio.h>
#include<stdlib.h>
#define LEN ((sizeof(arr1)+sizeof(arr2))/4)

int main()
{
	/************************************************************/
	/*
		�ô���ʵ�� �ϲ������������������arr1,arr2��arr3��
		���ұ���Ԫ����������
		int arr1[] = {1,2,5,7,8};int arr2[]={2,3,4,6,9};
		�ϲ���arr3���Ϊ{1,2,2,3,4,5,6,7,8,9};	

		˼·�������������αȽϣ���С�ķ����¶�������飻
			  �ж�arr1��arr2˭�ȷ����ˣ�
			  ��û���������ŵ��¶�������ĺ���

	ʹ�ú궨�� #define LEN ((sizeof(a1) + sizeof(a2))/4)
	*/
	/***********************************************************/
	int arr1[] = {1,2,5,7,8};
	int arr2[] = {2,3,4,6,9};
	int arr3[LEN] = { 0 };
	int i = 0, j = 0, index = 0;	//i ->arr1�±ꣻ j ->arr2�±ꣻ index ->arr3�±�
	while ((i < sizeof(arr1) / 4) && (j < sizeof(arr2) / 4))	//�ж�û������Ԫ��ȡ�꣬�����ѭ��
	{
		//˭С˭�ȷ����µ�����
		if (arr1[i] < arr2[j])
			arr3[index++] = arr1[i++];
		else
			arr3[index++] = arr2[j++];
	}
	if (i == sizeof(arr1) / sizeof(arr1[0]))	//�ж�arr1Ԫ�ط���
		while (j < (sizeof(arr2)/sizeof(arr2[0])))
			arr3[index++] = arr2[j++];
	else    //arr2 Ԫ�ط���
		while (i < (sizeof(arr1) / sizeof(arr1[0])))
			arr3[index++] = arr3[i++];
	
	for (int i = 0; i < LEN; ++i)	//��ӡ�ϲ��õ���������
		printf("%d ", arr3[i]);

	system("pause");
	return 0;
}