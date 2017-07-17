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
//1、循环输入结构体信息，当输入age小于0时，则结束输入
//2、查询所有用户信息
//3、输入要删除的姓名，然后把文件中相应的名字的结构删除
//4、不可以使用第二个文件，只用一个文件来完成这个任务
//5、需要使用的文件核心操作函数fwrite、fread
void menu()
{
	printf("**************************\n");
	printf("* 1 输入信息\n");
	printf("* 2 查询信息\n");
	printf("* 3 删除用户\n");
	printf("* 4 清除屏幕\n");
	printf("* 5 退出程序\n");
	printf("**************************\n");
}

//加载信息到内存
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
	printf("当前记录数：%d\n", k);
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

void addInfo(Stu **p, int *count)	//循环输入结构体信息，当输入age小于0时，则结束输入
{
	if (p == NULL || *count < 0)
	{
		fprintf(stdout,"p == NULL || *count < 0");
		return;
	}
	printf("Please Input Info(exit 0->退出当前菜单):\n");
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
			fprintf(stdout, "信息已录入更新\n");
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
	if (p == NULL || *n < 1)	//异常处理
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
			printf("%s信息删除成功\n", tmp_name);
			return;
		}		
	}
	printf("Not found %s\n", tmp_name);
}

void saveInfo(Stu *p, int n)
{
	if (p == NULL || n < 1)	//异常处理
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
	fwrite(p,sizeof(Stu),n,fp);	//写入文件中
	fclose(fp);
}

int main01(void)
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	menu();
	char getInput[64] = { 0 };	//接收用户指令
	
	Stu *p = NULL;
	int n = 0;
	//加载信息到内存,并且打印
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
	if (p == NULL)	//异常处理
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
		if (feof(fp))	//判断到文件尾
		{
			break;
		}
		tmp = (char**)realloc(tmp,(++n) * sizeof(char *));	//堆中分配总的空间
		if (tmp == NULL)
		{
			fprintf(stdout, "realloc filed!\n");
			break;
		}
		int len = strlen(buf);
		tmp[i++] = (char*)calloc(1, len + 1);	//为每行字符串分配空间
		if(tmp[i-1] == NULL)
		{
			fprintf(stdout, "行空间realloc filed!\n");
			break;
		}
		strcpy(tmp[i-1],buf);	//拷贝每行内容到开辟的堆中
	}
	fclose(fp);
	*p = tmp;
	*line = n;
}

int main(void)
{
	/*******************************************************/
	/*
	已知 char **p = NULL; int lines 编写读文件函数，
	从文件中读取内容，为每一行内容按大小分配空间。
	void readFile(char ***p,int *line);

	文件内容参考《demo.txt》

	提示：
	首先扫描文件行数，根据行数给指针p分配指针数组空间。
	再根据每行内容，动态分配空间，存放每行内容。

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
