#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	/************************************************************/
	/*
		����һ���ַ���\(����Ϊn\)
		ͳ�����г��ֵĴ�д��ĸ��Сд��ĸ�������ַ���
		�հ��ַ�\(' '\b'\n'��'\t'��\)�ȵ�������
	*/
	/************************************************************/
	char str[] = "I love you\n    5201314\t       ,;  ";
	int len = strlen(str);	//����ַ�����Ч���ȣ�������'\0' string.h ��
	int count[5] = { 0 };
	for (int i = 0; i < len; ++i)
	{
		if (isupper(str[i]))	//isupper �ж��Ƿ�Ϊ��д��ĸ��������Ϊ��д��������ctype.h��
			count[0]++;
		else if (iswlower(str[i]))	//iswlower �ж��Ƿ�ΪСд��ĸ��������ΪСд��������ctype.h��
			count[1]++;
		else if (str[i] >= '0' && str[i] <= '9')	//�հ��ַ��ж�
			count[2]++;
		else if (isspace(str[i]))	//isspace �ж��Ƿ�Ϊ�հ��ַ���������Ϊ�հ��ַ���������ctype.h��
			count[3]++;
		else    //�����ַ�
			count[4]++;
	}

	printf("��д��ĸ����: %d\n", count[0]);
	printf("Сд��ĸ����: %d\n", count[1]);
	printf("�����ַ�����: %d\n", count[2]);
	printf("�հ��ַ�����: %d\n", count[3]);
	printf("�����ַ�����: %d\n", count[4]);

	system("pause");
	return 0;
}