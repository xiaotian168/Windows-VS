#include<stdio.h>
#include<stdlib.h>

int main()
{
	//char *str = NULL;

	//printf("%s\n", str);	//null
	//printf("%d\n", str);	//0
	//printf("%p\n", str);	//00000000
	//printf("%x\n", str);	//0
	//printf("%o\n", str);	//0

	//int a = 248;
	//int const *const f  = &a;	//错误写法
	//int a[2][3] = {0};
	//for (int i = 0; i < 3; ++i)		//错误
	//	for (int j = 0; j < 2; ++j)
	//		printf("%d ", a[i][j]);

	/*char a[1000];
	for (int i = 0; i < 1000; ++i)
		a[i] = -1 - i;
	printf("%d\n", strlen(a));*/

	//char a[4] = { 1, 2, 3, 4 };
	//char *p = a;
	//printf("%d, %d, %d, %d\n", *p, *(p + 1), *(p + 2), *(p + 3));

	//int *p1 = (int *)a;//把a的地址强转为int *类型
	//printf("%d\n", *p1);
	//printf("%x\n", *p1);

	char str[] = "hello 123 world";
	char str1[20] = "";
	scanf("%2s%*s%s", str1, str);
	//scanf("%*d%s",str1);
	printf("%s\n%s\n", str1,str);
	system("pause");
	return 0;
}