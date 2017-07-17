#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int format(char *str)
{
	if (NULL == str)
		return 0;
	int len = strlen(str);	//求字符串有效长度，不包括'\0'
	char *p = str;	//指向字符串首地址
	char *r = p;
	char *q = str + len - 1;	//指向字符串尾地址

	while (isspace(*p))	//isspace判断字符是否为空白字符，是返回真；包含在ctype.h头文件中
		p++;

	while (isspace(*q))
		q--;

	while (p <= q)
		*r++ = *p++;

	*r = '\0';
	return 1;
}

int main()
{
	char buf[] = "\n\t flfhwie , fab \n";
	printf("%s", buf);
	format(buf);
	printf("%s", buf);
	system("pause");
	return 0;
}