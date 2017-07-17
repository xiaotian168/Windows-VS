#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	int age;
	char buf[64] = { 0 };
	scanf("%d %s", &age, buf);
	FILE *fp = fopen("a.txt", "ab+");
	//fprintf(fp,"%d %s", age, buf);
	fwrite(&age, sizeof(int), 1, fp);
	fclose(fp);

	printf("\n");
	system("pause");
	return 0;
}
