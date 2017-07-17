#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *replace_char(const char *str)
{
	if (str == NULL)
		return NULL;
	int len = strlen(str);
	char *p = calloc(len, sizeof(char));
	if (p == NULL)
	{
		printf("calloc filed!\n");
		return NULL;
	}
	int index = 0;
	while (*str)
	{
		if (*str == 'a' && *(str + 1) == 'a')
		{
			p[index++] = 'A';
			str++;
		}
		else
			p[index++] = *str;
		str++;
	}
	return p;
}

int main()
{
	/**********************************************************/
	/*
		��ԭ�ַ����д���Ľ����ŵ�һ����̬���ٵĶѿռ��С�
		��������̣���ԭ�ַ��е�aa�滻ΪA��
		����ԭ�ͣ�char *replace_char(const char *str);
		��������ֵ: 
		���滻����ַ�����ӡ�����������ͷŶ�̬���ٵ��ڴ�ռ䡣
	*/
	/*********************************************************/
	char str[] = "fljflfaaafjkdlaa12";
	char *ptr = replace_char(str);
	printf("%s\n",ptr);
	free(ptr);

	system("pause");
	return 0;
}