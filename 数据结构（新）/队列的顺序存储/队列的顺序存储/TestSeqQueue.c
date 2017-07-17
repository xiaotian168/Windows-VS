#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqQueue.h"

typedef struct Person
{
	char name[64];
	int age;
}Person;

void test()
{
	//��ʼ������
	SQueue *queue = Init_SeqQueue();

	//��������
	Person p1 = { "aaa", 10 };
	Person p2 = { "bbb", 20 };
	Person p3 = { "ccc", 30 };
	Person p4 = { "ddd", 40 };
	Person p5 = { "eee", 50 };
	Person p6 = { "fff", 60 };

	//���
	Push_SeqQueue(queue, &p1);
	Push_SeqQueue(queue, &p2);
	Push_SeqQueue(queue, &p3);
	Push_SeqQueue(queue, &p4);
	Push_SeqQueue(queue, &p5);
	Push_SeqQueue(queue, &p6);

	Person *p = Rear_SeqQueue(queue);	//��ȡ��βԪ��
	printf("��βԪ��Ϊ��Name = %s, Age = %d\n", p->name, p->age);

	p = Front_SeqQueue(queue);
	printf("��ͷԪ��Ϊ��Name = %s, Age = %d\n", p->name, p->age);

	int size = Size_SeqQueue(queue);	//��ȡ����Ԫ�ظ���
	printf("����Ԫ�ظ�����%d\n", size);

	//���г���
	int ret = Pop_SeqQueue(queue);
	if (0 == ret)
	{
		printf("���г��ӳɹ�\n");
	}

	p = Front_SeqQueue(queue);
	printf("��ǰ��ͷԪ��Ϊ��Name = %s, Age = %d\n", p->name, p->age);

	size = Size_SeqQueue(queue);	//��ȡ����Ԫ�ظ���
	printf("��ǰ����Ԫ�ظ���Ϊ��%d\n", size);

	//���ٶ���
	ret = Destroy_SeqQueue(queue);
	if (0 == ret)
	{
		printf("�������ٳɹ�\n");
	}

}

int main(void)
{
	/*******************************************************/
	/*
	���е�˳��洢
	*/
	/*******************************************************/
	test();

	printf("\n");
	system("pause");
	return 0;
}
