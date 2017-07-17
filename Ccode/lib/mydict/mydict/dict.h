#pragma once

struct dict
{
	char *key;
	char *content;
	struct dict *next;	//增加一个next指针域
};

__declspec(dllexport)void format_string(char *str);	//去掉字符串结尾的回车，空格字符

//打开字典文件，并读取文件内容
__declspec(dllexport)int open_dict(struct dict **p, const char *dict_filename);

//根据关键字key,在字典中查找内容
__declspec(dllexport)int search_dict(const struct dict *p, int size, const char *key, char *content);

//释放内存
__declspec(dllexport)void free_dict(struct dict *p, int size);

__declspec(dllexport)int start();
