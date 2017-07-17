#include<stdio.h>
#include<stdlib.h>

int str_len_cmp(const char *str1, const char *str2)		//str1长则返回1；相等返回0；str2长返回-1
{
	if (str1 == NULL || str2 == NULL)
	{
		fprintf(stdout,"str1 == NULL || str2 == NULL\n");	//输出异常提示
		exit(-1);	//程序退出
	}

	while (*str1 && *str2)		//当有一个字符串遍历完时，循环退出
		str1++, str2++;

	if (*(str1) == *(str2))	//说明str1和str2长度相等    *(str1) == '\0' && *(str2) == '\0'
		return 0;
	else if (*(str1) == '\0')		//str2长
		return -1;
	else
		return 1;
}

int main()
{
	/*************************************************************/
	/*
		编写一个函数比较两个字符串的长度谁长(不使用库函数)。
	*/
	/*************************************************************/
	char str1[] = "hed   d";
	char str2[] = "jfl900";
	printf("%d\n",str_len_cmp(str1,str2));
	system("pause");
	return 0;
}