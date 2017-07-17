#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int mystrlen(const char *str)
{
	int len = 0;
	if (str == NULL)
		return len;
	while (*str++)
		len++;
	return len;
}

/*
���ܣ����ַ���haystack�в����ַ���needle���ֵ�λ��
������
haystack��Դ�ַ����׵�ַ
needle��ƥ���ַ����׵�ַ
����ֵ��
�ɹ������ص�һ�γ��ֵ�needle��ַ
ʧ�ܣ�NULL
*/
char *my_strstr(const char *haystack, const char *needle)
{
	if (haystack == NULL || needle == NULL)
		return NULL;
	int len2 = mystrlen(needle);
	int len = 0;	//��Ϊ�����ж��Ƿ����ƥ���ַ����ı�־
	while (*haystack && *needle)	//�����ַ������бȽ�
	{
		if (*haystack == *needle)	//��������ַ���Ŀ���ַ�ָ���ƶ�����ȵ��ַ���������1
		{
			len++;
			needle++;
		}
		else    //���ֲ����ַ�
		{
			needle -= len;	//Ŀ���Ӵ�ָ��ص����
			len = 0;	//��ȵ��ַ���������
		}	
		haystack++;
	}
	if (len == len2)	//�ж��ҵ�����Ӵ�
		return haystack -= len2;
	else
		return NULL;
}

int main()
{
	/************************************************************/
	/*
		ʵ��my_strstr()���������ܺ�strstr()����һ����
		a. �����в�ʹ���κβ����ַ����ĺ���(�磺strcpy��strcmp��)
		b. �����е��κεط���ʹ���±ꡣ
	*/
	/************************************************************/
	char *haystack = "hello worldjfal";
	char *needle = "ld";
	printf(my_strstr(haystack, needle));
	system("pause");
	return 0;
}

/*
���ܣ�
��ֵ�ԣ���key = value�����ַ������Ӽ�key���Ҷ�Ӧ��ֵvalue
������
keyval����ֵ�ԣ���key = value�����ַ���
pkey����
buf��ƥ�������Ӧ������
len��ƥ�������Ӧ���ݵĳ���
����ֵ��
�ɹ���0
ʧ�ܣ���0
*/
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int* valuebuflen)
{
	//�쳣����
	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)
		return -1;
	int key_len = strlen(keybuf);	//��keyֵ����
	keyvaluebuf = strstr(keyvaluebuf, keybuf);	//���Ӵ���"key = value"�����׵�ַ���¸�ֵ����ֵ��
	if (keyvaluebuf == NULL)	//������Ŀ���Ӵ�
		return -1;

	keyvaluebuf = keyvaluebuf + key_len;	//�ƶ���Ŀ���Ӵ�
	int len = strlen(keyvaluebuf);	//��δȥ���ո��Ŀ���ַ�������
	*valuebuflen = 0;
	for (int i = 0; i < len; ++i)	//����Ŀ���Ӵ���valuebuf��
	{
		if ((isspace(keyvaluebuf[i]) || keyvaluebuf[i] == '=') && *valuebuflen == 0)
			continue;
		else
			valuebuf[(*valuebuflen)++] = keyvaluebuf[i];
	}
	return 0;
}

int main01()
{
	/*************************************************************/
	/*
		��ֵ�ԣ�"key = value"���ַ������ڿ����о���ʹ��
		Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡ
		Ҫ��2����д��������
		Ҫ��3����ֵ���м������n��ո���ȥ���ո�	
		ע�⣺��ֵ���ַ�����ʽ�������£�
		"key1 = value1"
		"key2 =       value2"
		"key3  = value3"
		"key4        = value4"
		"key5   =   "
		"key6   ="
		�ο��⺯����strncpy(), strlen(), strstr(), 
					����ʹ��sscanf()����
	*/
	/************************************************************/
	char buf[128] = { 0 };
	int len = 0;

	// ��"key1 =    valude1"�в���"key1"ƥ����ַ�����
	//����ҵ�����ȡ=������ַ���������ȥ������ո�
	int ret = getKeyByValue("key1 =    valude1 ", "key1", buf, &len);
	//���ú�����buf="valude1", len=7
	printf("%s %d", buf, len);

	system("pause");
	return 0;
}