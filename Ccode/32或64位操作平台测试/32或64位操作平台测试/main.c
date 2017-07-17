#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p = NULL;
	if (sizeof(p) == 4)
		printf("32λϵͳ\n");
	else if(sizeof(p) == 8)
		printf("64λϵͳ\n");
	system("pause");
	return 0;
}