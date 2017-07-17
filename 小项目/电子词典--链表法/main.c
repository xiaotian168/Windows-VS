#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct dict
{
	char *key;
	char *content;
	struct dict *next;	//增加一个next指针域
};

void format_string(char *str)//去掉字符串结尾的回车，空格字符
{
	size_t i;
	for (i = strlen(str) - 1; i >= 0; i--)
	{
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '\r')
		{
			str[i + 1] = '\0';
			break;
		}
	}
}

//打开字典文件，并读取文件内容
int open_dict(struct dict **p, const char *dict_filename)
{
	FILE *pfile = fopen(dict_filename, "r");
	if (pfile == NULL)
		return 0;//打开文件失败，函数返回

				 //分配一个头结点
	struct dict * head = (struct dict *)calloc(1, sizeof(struct dict)); //struct dict *指向struct dict
	if (head == NULL)
	{
		return 0;
	}

	*p = head; //间接赋值

	struct dict *tmp = NULL; //新节点
	struct dict *cur = NULL; //尾节点
	cur = head;


	char buf[2048] = { 0 };
	size_t len = 0;
	int i = 0;//计数器
	while (!feof(pfile))//循环读取文件，直到文件末尾
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), pfile);//读取文件一行
		len = strlen(buf);//得到读取到字符串长度
		if (len > 0)
		{
			//有内容，需要新节点
			tmp = (struct dict *)calloc(1, sizeof(struct dict));

			//保存单词
			tmp->key = (char *)calloc(1, len);//根据字符串长度分配内存

			format_string(buf);//去掉字符串结尾的空格和回车
			strcpy(tmp->key, &buf[1]);//将读取到的内容拷贝到key中
		}

		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), pfile);
		len = strlen(buf);
		if (len > 0)
		{
			//新节点，保存单词的解析
			tmp->content = (char *)calloc(1, len);
			strcpy(tmp->content, &buf[6]);

			//节点建立关系
			cur->next = tmp;
			tmp->next = NULL; //作为尾结点
			cur = tmp; //保存尾结点
		}

		i++;//计数器加1
	}
	fclose(pfile);//关闭字典文件

	return i;//返回读取到的字典词条数
}

//根据关键字key,在字典中查找内容
int search_dict(const struct dict *p, int size, const char *key, char *content)
{
	if (p == NULL)
	{
		return 0;
	}

	const struct dict * tmp = p->next;
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			strcpy(content, tmp->content);
			return 1;//找到符合条件记录，返回1
		}

		//指针往后移动
		tmp = tmp->next;
	}

	return 0;//没有找到符合条件记录，返回0
}

//释放内存
void free_dict(struct dict *p, int size)
{
	if (p == NULL)
	{
		return;
	}

	struct dict *del = p;
	struct dict *tmp = p;
	while (tmp != NULL)
	{
		//释放当前节点前，先保存下一个节点
		tmp = tmp->next;

		//先释放成员
		if (del->key != NULL)
		{
			free(del->key);
			del->key = NULL;
		}
		if (del->content != NULL)
		{
			free(del->content);
			del->content = NULL;
		}

		//再释放结构体本身
		free(del);

		del = tmp; //保存下一个节点
	}

}


int main(int argc, char *args[])
{

	long start_ms = 0;//记录函数执行的开始时间
	long end_ms = 0;//记录函数执行的结束时间
	struct dict *p = NULL; //p就是链表的头结点
	start_ms = clock();
	int dict_size = open_dict(&p, "./dict_gbk.txt");//根据命令行第一个参数做为字典文件名，打开字典文件
	if (dict_size == 0)
	{
		fprintf(stdout, "电子词典打开失败\n");
		system("pause");
		return 0;//打开字典文件失败，程序退出
	}
		

	end_ms = clock();
	printf("加载成功，用时: %ld ms\n\t\t输入xiaotian退出程序\n", end_ms - start_ms);//打印函数执行时间，单位：毫秒

	char key[1024];
	char content[1024];
	while (1)
	{
		memset(key, 0, sizeof(key));
		memset(content, 0, sizeof(content));
		fgets(key, sizeof(key), stdin);//从键盘得到用户输入
		format_string(key);//去掉字符串结尾的空格和回车
		if (strncmp(key, "xiaotian", 8) == 0)
			break;

		start_ms = clock();
		if (search_dict(p, dict_size, key, content))//根据用户输入，在字典中检索
		{
			printf("%s", content);
		}
		else
		{
			printf("没有次单词\n");
			continue;
		}
		end_ms = clock();
		printf("查找耗时: %ld ms\n", end_ms - start_ms);//打印函数执行时间，单位：毫秒
	}

	start_ms = clock();
	free_dict(p, dict_size);
	end_ms = clock();
	printf("释放空间耗时: %ld ms\n", end_ms - start_ms);//打印函数执行时间，单位：毫秒
	system("pause");
	return 0;
}
