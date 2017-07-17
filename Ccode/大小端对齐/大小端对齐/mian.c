#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0x11223344;
	unsigned char *p = (unsigned char *)&a;
	for (int i = 0; i < 4; ++i)
		printf("%X", p[i]);
	system("pause");
	return 0;
}