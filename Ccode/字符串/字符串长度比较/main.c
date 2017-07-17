#include<stdio.h>
#include<stdlib.h>

int str_len_cmp(const char *str1, const char *str2)		//str1���򷵻�1����ȷ���0��str2������-1
{
	if (str1 == NULL || str2 == NULL)
	{
		fprintf(stdout,"str1 == NULL || str2 == NULL\n");	//����쳣��ʾ
		exit(-1);	//�����˳�
	}

	while (*str1 && *str2)		//����һ���ַ���������ʱ��ѭ���˳�
		str1++, str2++;

	if (*(str1) == *(str2))	//˵��str1��str2�������    *(str1) == '\0' && *(str2) == '\0'
		return 0;
	else if (*(str1) == '\0')		//str2��
		return -1;
	else
		return 1;
}

int main()
{
	/*************************************************************/
	/*
		��дһ�������Ƚ������ַ����ĳ���˭��(��ʹ�ÿ⺯��)��
	*/
	/*************************************************************/
	char str1[] = "hed   d";
	char str2[] = "jfl900";
	printf("%d\n",str_len_cmp(str1,str2));
	system("pause");
	return 0;
}