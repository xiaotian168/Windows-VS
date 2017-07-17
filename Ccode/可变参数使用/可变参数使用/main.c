#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

//1������ָ�����
//2������ָ���������ָ�����ĸ�λ�ÿ�ʼȡ����
//3��ѭ����ָ��λ�ÿ�ʼ����ȥָ�����͵�����
//4����������

void fun(int m, int n, ...)		//ȡint�Ͳ���
{
	int num;
	int i = 0;

	//1������һ���ɱ�������͵ı�����ָ�����
	va_list ap;		//va_listʵ��Ϊchar *���͵ı���

	//2��ָ��ָ��ɱ������һ������
		//a����һ������Ϊ�ɱ�����ı���
		//b���ڶ�������Ϊ...ǰ��ı�����
	va_start(ap, n);

	//3��ȡ������ָ������
	for (int i = 0; i < 3; ++i)	//ȡ���������������Լ�ָ��ȡ���ٸ���
	{
		//ȡ�������������������ȡ��ap�Զ��ƶ�����һ������λ��
		num = va_arg(ap, int);	//��int����ȡ����
		printf("num = %d\n", num);
	}

	//4����������
	va_end(ap);
}

void fun1(const char *str,...)	//ȡ�ַ����Ͳ���
{
	const char *arg = str;

	//1������һ���ɱ�������͵ı�����ָ�����
	va_list ap;

	//2��ָ��ָ��ɱ������һ������
	va_start(ap,str);

	//3��ȡ������ָ������
	while (arg)
	{
		printf("arg = %s\n", arg);
		arg = va_arg(ap, const char *);
	}

	//4����������
	va_end(ap);
}

int main(void)
{
	/*******************************************************/
	/*
	���裺
		1������һ���ɱ�������͵ı�����ָ�����
			va_list ap;
		2��ָ��ָ��ɱ������һ������
			a����һ������Ϊ�ɱ�����ı���
			b���ڶ�������Ϊ...ǰ��ı�����
			va_start(ap, n);
		3��ȡ������ָ������
		num = va_arg(ap, int);	//��int����ȡ����
		4����������
		va_end(ap);
	*/
	/*******************************************************/
	fun(3, 1, 2, 3);

	fun1("xiaotian", "hello", "666", NULL);

	printf("\n");
	system("pause");
	return 0;
}
