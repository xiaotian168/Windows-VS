#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void proc(char *str)
{
	if (str == NULL)
		return;
	while (1)
	{
		if (*str == '\0')
			return;
		if (strncmp(str, "key:", 4) == 0 && str[4] != '\0')	//�ж��������ַ���"key:",��ӡ�������������������
		{
			printf("%c\n", str[4]);
			str += 5;
		}
		else   //û��"key:"
			str++;
	}
}

int main()
{
	char str[1024] = { 0 };
	printf("input:\n");
	scanf("%s", str);
	proc(str);
	system("pause");
	return 0;
}