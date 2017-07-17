#include<stdio.h>
#include<stdlib.h>

int main01()	//整形变量转IP地址
{
	unsigned int ip = 2130706433;	//127.0.0.1
	//16777216;	->256*256*256	->1.0.0.0
	unsigned char *p = (unsigned char *)&ip;

	for (int i = 3; i > 0; --i)
		printf("%d.", p[i]);
	printf("%d\n", p[0]);

	system("pause");
	return 0;
}

int main()	//IP地址转为整型变量
{
	char str[] = "127.0.0.1";
	int a, b, c, d;
	sscanf(str, "%d.%d.%d.%d", &a, &b, &c, &d);
	//printf("%d.%d.%d.%d\n", a, b, c, d);
	unsigned int ip;
	unsigned char *p = (unsigned char *)&ip;
	p[0] = d;
	p[1] = c;
	p[2] = b;
	p[3] = a;

	printf("%u\n", ip);

	system("pause");
	return 0;
}