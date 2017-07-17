#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
	char name[64];
	char address[256];
	int age;
}std;

void add_info(std **p, unsigned int *p_count)
{
	std *temp = (std *)realloc(*p, sizeof(std)*(*p_count+1));
	if (temp == NULL)
	{
		printf("realloc filed\n");
		return;
	}
	unsigned int index = *p_count;
	scanf("%s%d%s", temp[index].name, &temp[index].age, temp[index].address);
	(*p_count)++;
	*p = temp;
}

void free_info(std *p)
{
	if (p)
		free(p);
}

void print_info(std *p, unsigned int count)
{
	if (p)
		for (int i = 0; i < count; ++i)
			printf("%s %d %s\n", p[i].name, p[i].age, p[i].address);
}

int main()
{
	/*************************************************************/
	/*
		ʵ��һ�������ܴ���Ļ�Ͻ����������������Ϣ���¼�롣
		�ںڴ������ܹ�֧��print���� �����е��˵���Ϣ��ӡ
		�ٺڴ������ܹ�֧��exit����   �˳�����
		��ʾ������������֮�䶼���ÿո�ֿ��ġ�

		ʾ����
			input:
			add tom  23  beijing
			add  jay    33  taiwan
			add andy  55  HK
			input:
			print
			output:
			tom  23  beijing
			jay    33  taiwan
			andy 55  HK
			input:
			add jj 28 malaixiya
			input:
			print
			output:
			tom  23  beijing
			jay    33  taiwan
			andy 55  HK
			add jj 28 malaixiya
			input:
			exit
			Ӧ�ó����˳� �ݰ�
	*/
	/*************************************************************/
	std *p_std = NULL;
	unsigned int count = 0;
	char command[64] = { 0 };

	while (1)
	{
		printf("input(exit�˳�):\n");
		scanf("%s", command);
		if (strcmp(command, "add") == 0)
		{
			add_info(&p_std, &count);
		}
		else if (strcmp(command, "print") == 0)
		{
			print_info(p_std, count);
		}
		else if (strcmp(command, "exit") == 0)
		{
			printf("Ӧ�ó����˳����ݰ�\n");
			free_info(p_std);
			break;
		}
		else
			printf("input error!\n");
	}

	system("pause");
	return 0;
}