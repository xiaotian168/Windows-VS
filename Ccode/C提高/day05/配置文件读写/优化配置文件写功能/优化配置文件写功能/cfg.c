#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CFGPATH "cfg.ini"

/*
���ܣ���ȡ�ǿ��ַ���
������
inbuf�� ԭʼ�ַ���buf�׵�ַ
outbuf���ǿ��ַ���buf�׵�ַ
����ֵ��
�ɹ���0
ʧ�ܣ���0
*/
int trimSpace(char *inbuf, char *outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char *p = inbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (end < 0){
		return -2;
	}

	//���������ƶ��������ǰ�ַ�Ϊ�գ�����û�н���
	while (p[begin] == ' ') //����ʹ�� isspace()
	{
		begin++; //λ�ô����ƶ�һλ
	}

	//���������ƶ��������ǰ�ַ�Ϊ��
	while (p[end] == ' ' && end > 0)
	{
		end--; //�����ƶ�
	}

	if (end == 0)
	{
		return -2;
	}

	n = end - begin + 1; //�ǿ�Ԫ�ظ���

	strncpy(outbuf, p + begin, n);
	outbuf[n] = '\0'; //������

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
int getKeyByValue(char *keyval, char *pkey, char *buf, int *len)
{
	if (keyval == NULL || pkey == NULL || buf == NULL || len == NULL)
	{
		return -1;
	}

	//�����������βνӹ���
	char *p = keyval; //"key1 =    valude1"

	//�鿴key�Ƿ���ĸ��
	//���� key1 �Ƿ��� "key1 =    valude1"
	p = strstr(p, pkey);
	if (NULL == p) //û��ƥ���
	{
		return -2;
	}

	//�����������λ�ã��ַ�������keyֵ
	//"key1 =    valude1" -> " =    valude1"
	p = p + strlen(pkey);

	//�����Ƿ����=��
	p = strstr(p, "=");
	if (NULL == p)//û��
	{
		return -3;
	}

	//�ַ�������"="
	//" =    valude1" -> "    valude1"
	p = p + strlen("=");

	//��ȡ�ǿ��ַ���
	int ret = trimSpace(p, buf);
	if (ret != 0)
	{
		return ret;
	}

	//ͨ��*�����������ڴ�
	//��Ӹ�ֵ
	*len = strlen(buf);

	return 0;
}


//����ʱ������ڶ�����������С����һ���Ծͷ���ã�����ͨ��realloc���䣬��������
int my_write(char *key, char *value)
{
	//1�����ļ�
	FILE *fp = NULL;
	int ret = 0;

	//a������ļ����ڣ������ԡ�w���򿪣���Ϊ�����
	//b������ļ������ڣ������ԡ�r����
	fp = fopen(CFGPATH, "r+");
	if (fp == NULL) //˵���ļ������ڣ���Ҫ�½��ļ�
	{
		fp = fopen(CFGPATH, "w+"); //����д�ķ�ʽ���򿪣�Ŀ��Ϊ���½��ļ�
		if (fp == NULL)
		{
			perror("fopen");
			ret = -1;
			goto END;
		}
	}

	//д�ļ�
	//a���ļ�������
	//b���ļ�û������

	char *tmp = NULL;
	int n = 0;
	int len = 0;
	char buf[1024] = { 0 };
	char *p = NULL;
	int flag = 0;

	//ѭ����ȡ�ļ����ݣ�ÿ�ζ�ȡһ��
	while (1)
	{
		memset(buf, 0 , sizeof(buf));
		fgets(buf, sizeof(buf), fp);
		len = strlen(buf);
		tmp = (char *)realloc(tmp, n + len + 1);	//���з���ռ�
		if (tmp == NULL)	//���пռ�����ʧ��
		{
			perror("realloc");
			ret = -2;
			goto END;
		}
		
		//�����չ�Ŀռ��ֵ; ��Ϊ0
		memset(tmp+n, 0, len+1);

		if (   feof(fp) ) //������ļ���β������
		{
			break;
		}

		//buf = "k2 = vvvvvv\n"
		p = strstr(buf, key); //�����ַ�������û�а���key
		if (p == NULL) //û��
		{
			strcat(tmp+n, buf);
			n += len;
			//�жϱ���ѭ��
			continue;
		}

		//�ҵ�����ִ��
		p = strstr(p, "="); //������û��=
		if (p == NULL)	//û��
		{
			strcat(tmp+n, buf);
			n += len;
			//�жϱ���ѭ��
			continue;
		}
		//ִ�е��⣬˵�����key����Ҫ�Ķ�Ӧ��value
		memset(buf, 0, sizeof(buf));	//�����buf
		sprintf(buf, "%s = %s\n", key, value);	//д���޸ĺú��key -> value��buf��

		strcat(tmp+n, buf);
		n += len;
		printf(tmp);
		flag = 1; //˵������key������׷��
	}

	if (0 == flag) //׷��
	{
		sprintf(buf, "%s = %s\n", key, value);
		len = strlen(buf);
		tmp = (char *)realloc(tmp, n + len + 1);	//���з���ռ�
		if (tmp == NULL)
		{
			perror("realloc");
			ret = -3;
		}
		strcat(tmp+n, buf);
		n += len;	//�������ַ���С
	}

	//�ر��ļ�����д��д��ʽ�򿪣���д�ļ�
	fclose(fp);
	fp = NULL;

	fp = fopen(CFGPATH, "w+"); //����д�ķ�ʽ���򿪣�Ŀ��Ϊ������ļ�
	if (fp == NULL)
	{
		perror("fopen");
		ret = -4;
		goto END;
	}

	//һ��д���ļ�
	fputs(tmp, fp);

	//�ͷŶ����ڴ�
	free(tmp);
	tmp = NULL;
	
END:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return ret;
}

int my_read(char *key, char *value, int *len)
{
	FILE *fp = NULL;
	int ret = 0;

	//ֻ����ʽ��
	fp = fopen(CFGPATH, "r");
	if (fp == NULL)
	{
		perror("fopen");
		ret = -1;
		goto END;
	}

	char buf[1024] = { 0 };
	char * p;
	int flag = 0;

	while (1)
	{
		fgets(buf, sizeof(buf), fp);
		if (feof(fp)) //������ļ���β
		{
			break;
		}

		//buf = "k2 = vvvvvv\n"
		p = strstr(buf, key); //�����ַ�������û�а���key
		if (p == NULL) //û��
		{
			//�жϱ���ѭ��
			continue;
		}

		//�ҵ�����ִ��
		p = strstr(p, "="); //������û��=
		if (p == NULL)
		{
			//�жϱ���ѭ��
			continue;
		}
		else //����keyֵ
		{
			flag = 1;
			break;
		}
	}

	if (0 == flag)
	{
		printf("û�����keyֵ\n");
		ret = -2;
		goto END;
	}

	//�У���key����Ӧ��valueȡ����
	ret = getKeyByValue(buf, key, value, len);
	if (ret != 0)
	{
		goto END;
	}


END:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return ret;
}