#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "cfg.h"

void menu()
{
	printf("=============================\n");
	printf("1 д�����ļ�\n");
	printf("2 �������ļ�\n");
	printf("3 ����\n");
	printf("4 �˳�\n");
	printf("=============================\n");
}

void write_cfg_file()
{
	char key[128] = { 0 };
	char value[256] = { 0 };
	int ret = 0;

	printf("������keyֵ��");
	scanf("%s", key);

	printf("������valueֵ��");
	scanf("%s", value);

	ret = my_write(key, value); //����д��������
	if (ret != 0)
	{
		printf("my_write err = %d\n", ret);
		return;
	}

	//�����ָ�����˵����д�ɹ�
	printf("д�ɹ���д������Ϊ: %s = %s\n", key, value);

}

void read_cfg_file()
{
	char key[128] = { 0 };
	char value[256] = { 0 };
	int ret = 0;
	int len;

	printf("������keyֵ��");
	scanf("%s", key);

	ret = my_read(key, value, &len); //���ö���������
	if (ret != 0)
	{
		printf("my_read err = %d\n", ret);
		return;
	}

	//�����ָ�����˵����д�ɹ�
	printf("��ȡ����Ϊ: %s = %s�� len = %d\n", key, value, len);

}