#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main()
{
	//定义一个二维数组，3行5列
	//可以把第一个[]的数字当做标志位，代表有3个一维数组 int a[5]
	//二维数组是一个特殊的一维数组，共有3个元素，每个元素都是一维数组int a[5]
	int a[3][5];

	//a也是数组第0个元素（首元素）地址，只有二维数组的每个元素都是一维数组
	//所以，二维数组的a，相当于一维数组int b[5]的&b
	int b[5];
	printf("&b:%d,&b+1:%d\n", &b, &b+1);	//步长为5*4 = 20

	//跳过一个元素，一个元素的长度为 5*4 = 20
	printf("a: %d, a+1: %d\n", a, a+1);	//步长为 5*4 = 20

	//&a代表整个二维数组的地址，步长为整个数组长度：3*5*4 = 60
	printf("&a:%d, &a+1:%d\n", &a, &a + 1);

	int n1 = sizeof(a); //整个二维数组的长度：3*5*4 = 60
	printf("n1 = %d\n", n1);

	int n2 = sizeof(a[0]); //第0个元素，第0个一维数组的长度：5*4  = 20
	printf("n2 = %d\n", n2);

	int n3 = sizeof(a[0][0]); //第0行0列元素，它是int类型，4
	printf("n3 = %d\n", n3);

	system("pause");
	return 0;
}