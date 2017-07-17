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
		实现一个代码能从屏幕上接收任意多人数的信息添加录入。
		在黑窗口中能够支持print命令 将所有的人的信息打印
		再黑窗口中能够支持exit命令   退出程序
		提示：命令与数据之间都是用空格分开的。

		示例：
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
			应用程序退出 拜拜
	*/
	/*************************************************************/
	std *p_std = NULL;
	unsigned int count = 0;
	char command[64] = { 0 };

	while (1)
	{
		printf("input(exit退出):\n");
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
			printf("应用程序退出，拜拜\n");
			free_info(p_std);
			break;
		}
		else
			printf("input error!\n");
	}

	system("pause");
	return 0;
}