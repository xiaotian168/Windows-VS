#include<stdio.h>
#include<stdlib.h>

int isisLeapYear(int year)	//�ж�����
{
	//����һ�򣬰��겻���İ�������
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 1 : 0;
}

//�ж�y��m��d�յ�����1��1�յ�����
int diduoshaotian(int y, int m, int d)
{
	int sum = 0;
	int index = 1;
	while (index < m)
	{
		switch (m)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			sum += 31;
			break;
		case 2:
			sum += 28 + isisLeapYear(y);
			break;
		case 4:case 6:case 9:case 11:
			sum += 30;
			break;
		default:
			break;
		}
		index++;
	}
	return sum+d;
}

int getNumbers(int y1, int m1, int d1, int y2, int m2, int d2)
{
	int y;
	int sum = 0;
	for (y = y1; y < y2; ++y)
	{
		sum += 365 + isisLeapYear(y);
	}
	return (sum - diduoshaotian(y1, m1, d1) + diduoshaotian(y2, m2, d2));
}

int main()
{
	/*************************************************************/
	/*
		д1������ ���ҵ��� ������н����
		int getNumbers(int y1,int m1,int d1,int y2,int m2,int d2);

		��������: ��ȡ��y1��m1��d1�յ�y2��m2��d2��֮���ж����죿
		����ֵ:   ������������֮�������������

		˼·���ж�y��m��d�յ�����1��1�յ�����
			  �������
	*/
	/*************************************************************/
	int y1, m1, d1, y2, m2, d2;
	printf("Please input start date: ");
	//scanf����ֵ������ƥ�䵽��ȷ��������ݸ�������������Ӧ�÷���3��
	int k1 = scanf("%d %d %d", &y1, &m1, &d1);
	printf("Please input end date: ");
	int k2 = scanf("%d %d %d", &y2, &m2, &d2);

	if (k1 != 3 || k2 != 3)		//��ʼ���ڸ�ʽ����������˳�����
	{
		printf("input error! USAGE: year month day\n");
		system("pause");
		return 1;
	}

	printf("%d\n", getNumbers(y1, m1, d1, y2, m2, d2));

	system("pause");
	return 0;
}