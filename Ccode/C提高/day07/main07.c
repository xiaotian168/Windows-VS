#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double getCount(int n)
{
	if (n == 1)
		return 1;
	return getCount(n - 1) * 2;
}

int main(void)
{
	/*******************************************************/
	/*
		有个莲花池里起初有一只莲花，每过一天莲花的数量就会翻一倍。
		假设莲花永远不凋谢，30天的时候莲花池全部长满了莲花, 
		请问第23天的莲花占莲花池的几分之几？
	*/
	/*******************************************************/
	double ret = getCount(23) / getCount(30);
	printf("%lf", ret);

	printf("\n");
	system("pause");
	return 0;
}
