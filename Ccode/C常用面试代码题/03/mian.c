#include<stdio.h>
#include<stdlib.h>

int mystrlen(char *str)	//���ַ�����Ч����
{
	int len = 0;
	if (str == NULL)
		return -1;
	while (*str++)
		len++;
	return len;
}

char *strreplace(char *str, const char *sub, const char *rep)
{
	int len1 = mystrlen(sub);	//������滻�Ӵ�����
	int len = mystrlen(str);
	for (int i = 0; i < len; ++i)	//����ԭ�ַ���
	{
		int n = 0;
		if (str[i] == *sub)	//�жϳ��ֵ�һ����ȵ��ַ�
		{
			for (int j = i; j < len1 + i; ++j)	//�жϺ���������ȵ��ַ��ĸ���
			{
				n++;
				if (str[j] != sub[j - i])
					break;
			}
			if (n == len1)	//�����������滻�Ӵ�
			{
				for (int k = i; k < len1 + i; k++)
					str[k] = rep[k - i];
			}
			i += n;		//��i�ƶ������µıȽ�λ��
		}
	}
}

int main()
{
	/****************************************************************/
	/*
	ʵ��һ��lite����ַ����滻����
	char *strreplace(char *str, const char *sub, const char *rep)

	Ҫ��
	1��strΪԭ�ַ�����subΪ�����滻���Ӵ�, repΪ�滻��ģ�
	Ϊ��������ٶ��ַ���sub��rep����һ��
	2��ֱ�Ӷ�ԭ�ַ���str�����޸Ĳ����أ�����ʹ��malloc/new
	�����µ��ڴ�ռ�
	3������ʹ���κο⺯��/API��������������strlen��strstr,
	strcpy��������Ҫ���ƹ��ܣ�������ʵ��
	*/
	/*****************************************************************/
	char str[] = " hello , world";
	strreplace(str, "llo", "520");
	printf("%s\n", str);

	system("pause");
	return 0;
}