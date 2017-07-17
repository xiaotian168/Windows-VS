#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//2. ���ַ��������������
//ret = sort(p1, len1, buf2, len2, &p3, &len3);
int sort(char **array1, int len1, char (*buf2)[30], int len2, char ***p3, int *len3)
{
	if (array1 == NULL || buf2 == NULL || len1 <= 0 || len2 <= 0)	//�쳣����
		return -1;
	*len3 = len1 + len2;	//��ȡ���ַ�������
	char **tmp3 = (char**)calloc(*len3,sizeof(char*));
	if (tmp3 == NULL)
		return -1;
	for (int i = 0; i < len1; ++i)
	{
		tmp3[i] = (char *)calloc(strlen(array1[i])+1,sizeof(char));	//���з���ռ�
		strcpy(tmp3[i],array1[i]);	//�����ַ���
	}
	for (int i = len1; i < *len3; ++i)
	{
		tmp3[i] = (char *)calloc(strlen(buf2[i - len1]) + 1, sizeof(char));
		strcpy(tmp3[i], buf2[i-len1]);	//�����ַ���
	}
	
	for (int i = 0; i < *len3 - 1; ++i)	//ѡ������
	{
		for (int j = i + 1; j < *len3; ++j)
		{
			if (strcmp(tmp3[i], tmp3[j]) > 0)	//����;����
			{
				char *tmp = tmp3[i];
				tmp3[i] = tmp3[j];
				tmp3[j] = tmp;
			}
		}
	}
	*p3 = tmp3;
}

void printBuf(char **p3, int len)
{
	if (p3 == NULL || len <= 0)	//�쳣����
		return;
	for (int i = 0; i < len; ++i)
		printf("%s\n", p3[i]);
}

void free_buf(char ***p3, int len)
{
	if (p3 == NULL || len <= 0)
		return;
	char **tmp = *p3;
	for (int i = 0; i < len; ++i)
	{
		if (tmp[i])
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}	
	}
	free(tmp);
	tmp = NULL;
	*p3 = tmp;
}

int  main01()
{
	int ret = 0;
	char *p1[] = { "aa", "ccccccc", "bbbbbb" };
	char buf2[][30] = { "111111", "3333333", "222222" };
	char **p3 = NULL;
	int len1, len2, len3, i = 0;

	len1 = sizeof(p1) / sizeof(*p1);
	len2 = sizeof(buf2) / sizeof(buf2[0]);

	/*
	���ܣ�
	1����ָ������p1���ַ���ȡ������
	2���Ѷ�ά����buf2���ַ�ȡ������
	3��������ַ������� p3��p3 ���ڶ���ָ������(ÿ��Ԫ��ͬʱ��ָ�����)
	4���� p3 ���ַ�����������ͨ�� strcmp() ��������
	������
	p1�� ָ�������׵�ַ��char *p1[] = {"aa", "ccccccc", "bbbbbb"};
	len1��p1Ԫ�ظ���
	buf2����ά������Ԫ�ص�ַ��char buf2[][30] = {"111111", "3333333", "222222"};
	len2��buf2�ַ���������
	p3������ָ��ĵ�ַ����Ҫ�ں����ڷ������ָ�����飬����p1��buf2���ַ���������Ҫ����
	len3������p3�е��ַ�������
	����ֵ���ɹ�Ϊ0�� ʧ��Ϊ����
	*/
	ret = sort(p1, len1, buf2, len2, &p3, &len3);

	//��ӡ����
	printBuf(p3, len3);

	//�ͷ�p3��ָ���ڴ�
	//�ں����ڲ���p3��ֵ��ֵΪNULL
	//len3������p3�е��ַ�������
	free_buf(&p3, len3);

	printf("\n");
	system("pause");
	return 0;
}

int count_one_bits(unsigned int tmp)
{
	int n = 0;
	while (tmp)
	{
		if (tmp % 2)
		{
			n++;	
		}
		tmp /= 2;
	}
	return n;
}

int count_one_bits1(unsigned int tmp)
{
	int n = 0;
	for (int i = 0; i < 32; ++i)
	{
		if ((tmp >> 31) ^ 0)//���αȽ�ÿ��λ�ϵ����Ƿ�Ϊ1(�Ӹ�λ��ʼ);ÿ�αȽ�һλ����0���ֵΪ����
			n++;
		tmp = tmp << 1;	//���±Ƚϵ�bitλ,������λ
	}
	return n;
}

int main(void)
{
	/*******************************************************/
	/*
		����һ���޷��ŵ����У�������λ��ֵΪ 1 �ĸ���
		��ʾ��>>

		int count_one_bits(unsigned int tmp)
		{

		}
	*/
	/*******************************************************/
	int n;
	printf("input:");
	scanf("%d", &n);
	printf("%d", count_one_bits1(n));
	printf("\n");
	system("pause");
	return 0;
}


char **getMem(int n) //��̬����ָ������
{
	char **buf = (char**)calloc(n, sizeof(char *));
	if (buf == NULL)
		return NULL;
	for (int i = 0; i < n; ++i)
	{
		buf[i] = (char*)calloc(30,sizeof(char));
	}
	return buf;
}

/*
���ܣ��� "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"����","�ָ����ַ�����������ڶ�ά����buf��
������
str��	ԭ�ַ�����"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
c��	 	�ָ���־��','
buf: 	ָ��������Ԫ�ص�ַ����ռ���������������
count������buf�ַ����ĸ���
����ֵ��
�ɹ���0
ʧ�ܣ���0
*/
int spitString(const char *str, char c, char **buf, int *count)
{
	int n = 0;
	int i = 0;
	while (*str)
	{
		if (*str != c)
		{
			buf[n][i] = *str;
			i++;
			if (*(str + 1) == '\0')	//�жϽ�β�ַ�����c������油'\0'
				buf[n][i] = '\0';
		}
		else
		{
			buf[n][i] = '\0';
			i = 0;
			n++;
			(*count)++;
		}
		str++;
	}
	return 0;
}

void getMemFree(char ***buf, int n) //�ͷſռ�
{
	if (buf == NULL || n <= 0)
		return;
	char **tmp = *buf;
	for (int i = 0; i < n; ++i)
	{
		if (tmp[i])
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}
	}
	free(tmp);
	tmp = NULL;
	*buf = tmp;
}

int main03(void)
{
	/************************************************************************/
	/*	��һ���ַ��������������� "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
		a) �Զ���, �����ִ����ִ��������ᳬ��10����ÿ���ִ����Ȳ��ᳬ��30
		b) �Զ��ŷָ��ַ��������ѽ������
		c)�ο��⺯����strchr(), strncpy(), strcpy(), strlen()
		����ʹ��strtok()
	*/
	/************************************************************************/
	char *p = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char **buf = getMem(10); //��̬����ָ������
	int n = 0;
	int ret = 0;

	ret = spitString(p, ',', buf, &n);
	if (ret != 0)
	{
		system("pause");
		return ret;	
	}

	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", buf[i]); //��ӡ�ָ�����ַ���
	}

	getMemFree(&buf, n); //�ͷſռ�

	system("pause");
	return 0;
}

