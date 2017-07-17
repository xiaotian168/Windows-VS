#include<stdio.h>
#include<stdlib.h>

int isisLeapYear(int year)	//判断闰年
{
	//四年一闰，百年不闰；四百年在闰
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 1 : 0;
}

//判断y年m月d日到该年1月1日的天数
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
		写1个函数 并且调用 输出运行结果。
		int getNumbers(int y1,int m1,int d1,int y2,int m2,int d2);

		函数功能: 获取出y1年m1月d1日到y2年m2月d2日之间有多少天？
		返回值:   返回两个日期之间所差的天数。

		思路：判断y年m月d日到该年1月1日的天数
			  计算年差
	*/
	/*************************************************************/
	int y1, m1, d1, y2, m2, d2;
	printf("Please input start date: ");
	//scanf返回值：返回匹配到正确输入的数据个数（下面正常应该返回3）
	int k1 = scanf("%d %d %d", &y1, &m1, &d1);
	printf("Please input end date: ");
	int k2 = scanf("%d %d %d", &y2, &m2, &d2);

	if (k1 != 3 || k2 != 3)		//起始日期格式输入错误则退出程序
	{
		printf("input error! USAGE: year month day\n");
		system("pause");
		return 1;
	}

	printf("%d\n", getNumbers(y1, m1, d1, y2, m2, d2));

	system("pause");
	return 0;
}