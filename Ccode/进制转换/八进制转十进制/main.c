#include<stdio.h>
#include<stdlib.h>
#include<math.h>	//包含pow头文件
#include<string.h>

//str是一个八进制数形式的字符串  str[12] = "1314"   最后一个元素是'\0'
//返回值是十进制整数
long int transform(const char *str)	//成功返回十进制整数，失败返回-1；
{
	if (str == NULL)
		return -1;
	int len = strlen(str);	//得到有效长度，不包含'\0'
	long int sum = 0;
	long int value = 0;
	for (int i = 0; i < len; i++)
	{
		value = (str[i] - '0') * pow(8, len-1-i);	//得到数字对应的位置上的数值与权值的乘积
		sum += value;	//累加和
	}
	return sum;
}

int main()
{
	/**********************************************/
	/*
		八进制字符串转化为十进制整数
			八进制："1234"（字符串）
			十进制：668	(整数)
	*/
	/**********************************************/
	char size[12] = "1234";
	printf("%ld\n", transform(size));

	system("pause");
	return 0;
}