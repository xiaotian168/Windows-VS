#include<stdio.h>
#include<stdlib.h>

int main()
{
	/***************************************************************/
	/*
		n级指针只能解引用n次；超过会报错；
			超过后可以通过强转其他类型的数据为指针类型进行访问
	*/
	/***************************************************************/
	int n = 100;
	int *p = &n;
	int **pp = &p;
	int ***ppp = &pp;
	int ****pppp = &ppp;
	int *****ppppp = &pppp;
	int ******pppppp = &ppppp;

	******pppppp = 77;

	printf("%d\n", ******pppppp);

	system("pause");
	return 0;
}