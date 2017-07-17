#include<stdio.h>
#include<stdlib.h>

int mystrlen(char *str)	//求字符串有效长度
{
	int len = 0;
	if (str == NULL)
		return -1;
	while (*str++)
		len++;
	return len;
}

char *strreplace(char *str, const char *sub, const char *rep)
{
	int len1 = mystrlen(sub);	//求出待替换子串长度
	int len = mystrlen(str);
	for (int i = 0; i < len; ++i)	//遍历原字符串
	{
		int n = 0;
		if (str[i] == *sub)	//判断出现第一个相等的字符
		{
			for (int j = i; j < len1 + i; ++j)	//判断后面连续相等的字符的个数
			{
				n++;
				if (str[j] != sub[j - i])
					break;
			}
			if (n == len1)	//满足条件，替换子串
			{
				for (int k = i; k < len1 + i; k++)
					str[k] = rep[k - i];
			}
			i += n;		//将i移动到最新的比较位置
		}
	}
}

int main()
{
	/****************************************************************/
	/*
	实现一个lite版的字符串替换函数
	char *strreplace(char *str, const char *sub, const char *rep)

	要求：
	1、str为原字符串，sub为待被替换的子串, rep为替换后的；
	为简单起见，假定字符串sub和rep长度一样
	2、直接对原字符串str进行修改并返回，不得使用malloc/new
	开辟新的内存空间
	3、不得使用任何库函数/API，包括但不限于strlen，strstr,
	strcpy，如有需要类似功能，请自行实现
	*/
	/*****************************************************************/
	char str[] = " hello , world";
	strreplace(str, "llo", "520");
	printf("%s\n", str);

	system("pause");
	return 0;
}