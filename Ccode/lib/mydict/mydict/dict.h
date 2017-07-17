#pragma once

struct dict
{
	char *key;
	char *content;
	struct dict *next;	//����һ��nextָ����
};

__declspec(dllexport)void format_string(char *str);	//ȥ���ַ�����β�Ļس����ո��ַ�

//���ֵ��ļ�������ȡ�ļ�����
__declspec(dllexport)int open_dict(struct dict **p, const char *dict_filename);

//���ݹؼ���key,���ֵ��в�������
__declspec(dllexport)int search_dict(const struct dict *p, int size, const char *key, char *content);

//�ͷ��ڴ�
__declspec(dllexport)void free_dict(struct dict *p, int size);

__declspec(dllexport)int start();
