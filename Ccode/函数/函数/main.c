#include<stdio.h>
#include<stdlib.h>

int is0ddNumber(unsigned int number)
{
	//if (number %= 2)	//������
	//	return 0;
	//else    //��������
	//	return 1;
	return (number %= 2) ? 0 : 1;
}

int main()
{
	/*********************************************************/
	/*
		�Զ���һ�������� Ҫ���ж��Ƿ�Ϊ����

		������
		����ԭ�� int isOddNumber(unsigned int number);
		�������� �жϲ���number�Ƿ������� �����ж��������Ƿ��ܹ���2������
		��������ֵ �������������0;���������������1
	*/
	/*********************************************************/
	int n;
	printf("input:");
	scanf("%d", &n);
	if (n < 0)
	{
		printf("input error! USAGE: n > 1\n");
		system("pause");
		return 1;
	}

	printf("%d\n",is0ddNumber(n));	//���ú���,���Ҵ�ӡ�����ķ���ֵ

	system("pause");
	return 0;
}