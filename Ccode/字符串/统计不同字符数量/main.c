#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	/************************************************************/
	/*
		给定一串字符串\(长度为n\)
		统计其中出现的大写字母、小写字母、数字字符、
		空白字符\(' '\b'\n'、'\t'等\)等的数量。
	*/
	/************************************************************/
	char str[] = "I love you\n    5201314\t       ,;  ";
	int len = strlen(str);	//求出字符串有效长度，不包括'\0' string.h 中
	int count[5] = { 0 };
	for (int i = 0; i < len; ++i)
	{
		if (isupper(str[i]))	//isupper 判断是否为大写字母，返回真为大写；包含在ctype.h中
			count[0]++;
		else if (iswlower(str[i]))	//iswlower 判断是否为小写字母，返回真为小写；包含在ctype.h中
			count[1]++;
		else if (str[i] >= '0' && str[i] <= '9')	//空白字符判断
			count[2]++;
		else if (isspace(str[i]))	//isspace 判断是否为空白字符，返回真为空白字符；包含在ctype.h中
			count[3]++;
		else    //其它字符
			count[4]++;
	}

	printf("大写字母个数: %d\n", count[0]);
	printf("小写字母个数: %d\n", count[1]);
	printf("数字字符个数: %d\n", count[2]);
	printf("空白字符个数: %d\n", count[3]);
	printf("其它字符个数: %d\n", count[4]);

	system("pause");
	return 0;
}