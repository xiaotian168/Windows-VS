#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

//1、定义指针变量
//2、传入指针变量并且指定从哪个位置开始取数据
//3、循环从指定位置开始往后去指定类型的数据
//4、结束处理

void fun(int m, int n, ...)		//取int型参数
{
	int num;
	int i = 0;

	//1、定义一个可变参数类型的变量，指针变量
	va_list ap;		//va_list实际为char *类型的别名

	//2、指定指向可变参数第一个参数
		//a、第一个参数为可变参数的变量
		//b、第二个参数为...前面的变量名
	va_start(ap, n);

	//3、取参数，指定类型
	for (int i = 0; i < 3; ++i)	//取参数个数（可以自己指定取多少个）
	{
		//取出变量，把这个变量提取后，ap自动移动到下一个变量位置
		num = va_arg(ap, int);	//按int类型取参数
		printf("num = %d\n", num);
	}

	//4、结束处理
	va_end(ap);
}

void fun1(const char *str,...)	//取字符串型参数
{
	const char *arg = str;

	//1、定义一个可变参数类型的变量，指针变量
	va_list ap;

	//2、指定指向可变参数第一个参数
	va_start(ap,str);

	//3、取参数，指定类型
	while (arg)
	{
		printf("arg = %s\n", arg);
		arg = va_arg(ap, const char *);
	}

	//4、结束处理
	va_end(ap);
}

int main(void)
{
	/*******************************************************/
	/*
	步骤：
		1、定义一个可变参数类型的变量，指针变量
			va_list ap;
		2、指定指向可变参数第一个参数
			a、第一个参数为可变参数的变量
			b、第二个参数为...前面的变量名
			va_start(ap, n);
		3、取参数，指定类型
		num = va_arg(ap, int);	//按int类型取参数
		4、结束处理
		va_end(ap);
	*/
	/*******************************************************/
	fun(3, 1, 2, 3);

	fun1("xiaotian", "hello", "666", NULL);

	printf("\n");
	system("pause");
	return 0;
}
