#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int format(char *str)
{
	if (NULL == str)
		return 0;
	int len = strlen(str);	//���ַ�����Ч���ȣ�������'\0'
	char *p = str;	//ָ���ַ����׵�ַ
	char *r = p;
	char *q = str + len - 1;	//ָ���ַ���β��ַ

	while (isspace(*p))	//isspace�ж��ַ��Ƿ�Ϊ�հ��ַ����Ƿ����棻������ctype.hͷ�ļ���
		p++;

	while (isspace(*q))
		q--;

	while (p <= q)
		*r++ = *p++;

	*r = '\0';
	return 1;
}

int main()
{
	char buf[] = "\n\t flfhwie , fab \n";
	printf("%s", buf);
	format(buf);
	printf("%s", buf);
	system("pause");
	return 0;
}