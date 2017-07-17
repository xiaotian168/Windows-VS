#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define filename "demo.txt" 

typedef struct student
{
	char name[20];
	int age;
}Stu;
//1��ѭ������ṹ����Ϣ��������ageС��0ʱ�����������
//2����ѯ�����û���Ϣ
//3������Ҫɾ����������Ȼ����ļ�����Ӧ�����ֵĽṹɾ��
//4��������ʹ�õڶ����ļ���ֻ��һ���ļ�������������
//5����Ҫʹ�õ��ļ����Ĳ�������fwrite��fread
void menu()
{
	printf("**************************\n");
	printf("* 1 ������Ϣ\n");
	printf("* 2 ��ѯ��Ϣ\n");
	printf("* 3 ɾ���û�\n");
	printf("* 4 �����Ļ\n");
	printf("* 5 �˳�����\n");
	printf("**************************\n");
}

//������Ϣ���ڴ�
void printSpolle()
{
	Stu *p1 = (Stu *)calloc(100, sizeof(Stu));

	FILE *fp = fopen("Student.txt", "ab+");
	if (fp == NULL)
	{
		fprintf(stdout, "Student.txt open faild!\n");
		return -1;
	}
	int k = fread(p1, sizeof(Stu), 100, fp);
	printf("��ǰ��¼����%d\n", k);
	for (int i = 0; i < k; ++i)
	{
		printf("%s %d\n", p1[i].name, p1[i].age);
	}
	fclose(fp);
	if (p1)
	{
		free(p1);
		p1 = NULL;
	}
}

void addInfo(Stu **p, int *count)	//ѭ������ṹ����Ϣ��������ageС��0ʱ�����������
{
	if (p == NULL || *count < 0)
	{
		fprintf(stdout,"p == NULL || *count < 0");
		return;
	}
	printf("Please Input Info(exit 0->�˳���ǰ�˵�):\n");
	int n = *count;
	Stu *tmp = NULL;
	int i = 0;
	while (1)
	{
		char buf[64] = { 0 };
		int age;
		scanf("%s %d", buf, &age);
		if (age < 0 || strncmp(buf, "exit", 4) == 0)
		{
			fprintf(stdout, "��Ϣ��¼�����\n");
			break;
		}
		tmp = (Stu *)realloc(tmp, (++n) * sizeof(Stu));
		if (tmp == NULL)
		{
			fprintf(stdout, "realloc faild!\n");
			exit(-1);
		}
		sprintf(tmp[i].name, "%s", buf);
		tmp[i].age = age;
		i++;
	}
	*p = tmp;
	*count = n;
	//printf("%d\n", *count);
}

void printInfo(Stu *p, int n)	
{
	if (p == NULL || n < 1)
	{
		fprintf(stdout,"Not found Info\n");
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%s\t%d\n", p[i].name, p[i].age);
	}
}

void deleteInfo(Stu *p, int *n)
{
	if (p == NULL || *n < 1)	//�쳣����
	{
		fprintf(stdout, "Info is NULL\n");
		return;
	}
	char tmp_name[64] = { 0 };
	scanf("%s", tmp_name);
	for (int i = 0; i < *n; ++i)
	{
		if (strcmp(p[i].name, tmp_name) == 0)
		{
			for(int j = i; j < *n - 1; ++j)
				p[j] = p[j + 1];
			*n -= 1;
			printf("%s��Ϣɾ���ɹ�\n", tmp_name);
			return;
		}		
	}
	printf("Not found %s\n", tmp_name);
}

void saveInfo(Stu *p, int n)
{
	if (p == NULL || n < 1)	//�쳣����
	{
		fprintf(stdout, "Have no Info to save!\n");
		return;
	}
	FILE *fp = fopen("Student.txt", "ab+");
	if (fp == NULL)
	{
		fprintf(stdout, "Student.txt open faild!\n");
		return;
	}
	fwrite(p,sizeof(Stu),n,fp);	//д���ļ���
	fclose(fp);
}

int main01(void)
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	menu();
	char getInput[64] = { 0 };	//�����û�ָ��
	
	Stu *p = NULL;
	int n = 0;
	//������Ϣ���ڴ�,���Ҵ�ӡ
	printSpolle();
	
	while (1)
	{
		scanf("%s", getInput);
		if (getInput[0] == '1')
			addInfo(&p, &n);
		else if (getInput[0] == '2')
			printInfo(p, n);
		else if (getInput[0] == '3')
			deleteInfo(p, &n);
		else if (getInput[0] == '4')
			system("cls");
		else if (getInput[0] == '5')
		{
			saveInfo(p,n);
			free(p);
			p = NULL;
			exit(0);
		}
		else
		{
			printf("Input Error!\n");
			menu();
		}
	}
	
	printf("\n");
	system("pause");
	return 0;
}


void readFile(char ***p, int *line)
{
	if (p == NULL)	//�쳣����
		return;
	char **tmp = NULL;
	FILE *fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		fprintf(stdout, "not found %s\n", filename);
		return;
	}
	int n = 0;
	int i = 0;
	while (1)
	{
		char buf[1024] = { 0 };
		fgets(buf, sizeof(buf), fp);
		if (feof(fp))	//�жϵ��ļ�β
		{
			break;
		}
		tmp = (char**)realloc(tmp,(++n) * sizeof(char *));	//���з����ܵĿռ�
		if (tmp == NULL)
		{
			fprintf(stdout, "realloc filed!\n");
			break;
		}
		int len = strlen(buf);
		tmp[i++] = (char*)calloc(1, len + 1);	//Ϊÿ���ַ�������ռ�
		if(tmp[i-1] == NULL)
		{
			fprintf(stdout, "�пռ�realloc filed!\n");
			break;
		}
		strcpy(tmp[i-1],buf);	//����ÿ�����ݵ����ٵĶ���
	}
	fclose(fp);
	*p = tmp;
	*line = n;
}

int main(void)
{
	/*******************************************************/
	/*
	��֪ char **p = NULL; int lines ��д���ļ�������
	���ļ��ж�ȡ���ݣ�Ϊÿһ�����ݰ���С����ռ䡣
	void readFile(char ***p,int *line);

	�ļ����ݲο���demo.txt��

	��ʾ��
	����ɨ���ļ�����������������ָ��p����ָ������ռ䡣
	�ٸ���ÿ�����ݣ���̬����ռ䣬���ÿ�����ݡ�

	*/
	/*******************************************************/
	char **p = NULL;
	int lines = 0;
	readFile(&p, &lines);

	for (int i = 0; i < lines; ++i)
	{
		printf("%s", p[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
