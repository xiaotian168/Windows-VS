#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkQueue.h"

typedef struct Person
{
	char name[64];
	int age;
}Person;

void test()
{
	LQueue *queue = NULL;
	//��������
	int ret = Init_LinkQueue(&queue);

	if (0 == ret)
	{
		printf("���д����ɹ�\n");
	}

	//��������
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };
	Person p4 = { "ddd", 40 };
	Person p5 = { "eee", 50 };
	Person p6 = { "fff", 60 };

	//���
	Push_LinkQueue(queue, &p1);
	Push_LinkQueue(queue, &p2);
	Push_LinkQueue(queue, &p3);
	Push_LinkQueue(queue, &p4);
	Push_LinkQueue(queue, &p5);
	Push_LinkQueue(queue, &p6);
	

	Person *p = Back_LinkQueue(queue);	//��ȡ��βԪ��
	printf("��βԪ��Ϊ��Name = %s, Age = %d\n", p->name, p->age);

	p = Front_LinkQueue(queue);
	printf("��ͷԪ��Ϊ��Name = %s, Age = %d\n", p->name, p->age);

	int size = Size_LinkQueue(queue);	//��ȡ����Ԫ�ظ���
	printf("����Ԫ�ظ�����%d\n", size);

	//���г���
	ret = Pop_LinkQueue(queue);
	if (0 == ret)
	{
		printf("���г��ӳɹ�\n");
	}
	
	size = Size_LinkQueue(queue);	//��ȡ����Ԫ�ظ���
	printf("��ǰ����Ԫ�ظ���Ϊ��%d\n",size);

	//���ٶ���
	ret = Destroy_LinkQueue(queue);
	if (0 == ret)
	{
		printf("�������ٳɹ�\n");
	}
}

int main(void)
{
	/*******************************************************/
	/*
		���в���
	*/
	/*******************************************************/
	test();

	printf("\n");
	system("pause");
	return 0;
}
