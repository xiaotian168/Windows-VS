#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *replace_char(const char *str)
{
	if (str == NULL)
		return NULL;
	int len = strlen(str);
	char *p = calloc(len, sizeof(char));
	if (p == NULL)
	{
		printf("calloc filed!\n");
		return NULL;
	}
	int index = 0;
	while (*str)
	{
		if (*str == 'a' && *(str + 1) == 'a')
		{
			p[index++] = 'A';
			str++;
		}
		else
			p[index++] = *str;
		str++;
	}
	return p;
}

int main()
{
	/**********************************************************/
	/*
		将原字符串中处理的结果存放到一个动态开辟的堆空间中。
		（处理过程：将原字符中的aa替换为A）
		函数原型：char *replace_char(const char *str);
		函数返回值: 
		将替换后的字符串打印出来，并且释放动态开辟的内存空间。
	*/
	/*********************************************************/
	char str[] = "fljflfaaafjkdlaa12";
	char *ptr = replace_char(str);
	printf("%s\n",ptr);
	free(ptr);

	system("pause");
	return 0;
}