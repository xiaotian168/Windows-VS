#include<stdio.h>
#include<stdlib.h>

int main()
{
	char buf[100];
	//跳过整型数据
	sscanf("1234 5678", "%*d %s", buf);
	printf("buf1=%s\n", buf);

	//读指定宽度的数据
	sscanf("12345678", "%4s", buf);
	printf("buf2=%s\n", buf);

	//取仅包含指定字符集的字符串
	sscanf("123abcABC", "%[1-9a-z]", buf);
	printf("buf3=%s\n", buf);

	//取到指定字符集为止的字符串
	sscanf("123abcABC", "%[^A-Z]", buf);
	printf("buf4=%s\n", buf);

	//取到指定字符为止的字符串
	sscanf("123456 abcdedf", "%[^ ]", buf);
	printf("buf5=%s\n", buf);

	system("pause");
	return 0;
}