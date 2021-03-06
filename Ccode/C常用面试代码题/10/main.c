#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void proc(char *str)
{
	if (str == NULL)
		return;
	while (1)
	{
		if (*str == '\0')
			return;
		if (strncmp(str, "key:", 4) == 0 && str[4] != '\0')	//判断流中有字符串"key:",打印出来；继续往后面查找
		{
			printf("%c\n", str[4]);
			str += 5;
		}
		else   //没有"key:"
			str++;
	}
}

int main()
{
	/*******************************************************************/
	/*
		void proc (char *str);
		函数用于在一个模块中，每次被调用时处理从流设备中输出的一个字节，
		如果流中有字符串‘key：’，则输
		出它后面的那个字节。
	*/
	/*******************************************************************/
	char str[1024] = { 0 };
	printf("input:\n");
	scanf("%s", str);
	proc(str);
	system("pause");
	return 0;
}