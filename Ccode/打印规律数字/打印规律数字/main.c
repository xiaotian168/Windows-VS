#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	/*************************************************/
	/*
		input:6
		���
			1	2	3	4	5	6		//���2��0����
			3	5	7	9	11			//���2��1����
			8	12	16	20				//���2��2����
			20	28	36					��������������
			48	64
			112

		˼·��ÿ��������ֵ֮�� ���2��i�η�

	*/
	/*************************************************/
	int n;	
	printf("input: ");
	scanf("%d", &n);	//�����û����������
	if (n < 1)
	{
		printf("input error! USAGE: n > 0\n");
		system("pause");
		return 1;
	}
	int num = 0;	//ÿ�е�����
	int val = 1;	//ÿ�е�һ������
	for (int i = 0; i < n; ++i)
	{
		num = val;	//��ȡÿ�е�һ������
		for (int j = i; j < n; ++j)	//��ӡÿ��
		{
			printf("%-6d", num);
			num += pow(2, i);
		}
		val += val + pow(2, i);		//��ѭ��һ�κ����»�ȡ��һ�е�һ������
		printf("\n");
	}
	system("pause");
	return 0;
}