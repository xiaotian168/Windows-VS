#pragma once
#include<stdio.h>
#include<stdlib.h>

//������нڵ�����ݽṹ
typedef struct QueueNode
{
	void* data;		//������
	struct QueueNode *next;		//ָ����
}QueueNode;

//������е����ݽṹ
typedef struct LQueue
{
	QueueNode header;	//ͷ���
	QueueNode *rear;	//β���
	int size;
}LQueue;

typedef void* LinkQueue;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	//��ʼ������
	LinkQueue Init_LinkQueue();

	//���
	int Push_LinkQueue(LinkQueue queue, void* data);

	//����
	int Pop_LinkQueue(LinkQueue queue);

	//��ȡ��ͷԪ��
	void* Front_LinkQueue(LinkQueue queue);

	//��ȡ��βԪ��
	void* Rear_LinkQueue(LinkQueue queue);

	//��ȡ���д�С
	int Size_LinkQueue(LinkQueue queue);

	//���ٶ���
	int Destroy_LinkQueue(LinkQueue queue);

#ifdef __cplusplus
}
#endif // __cplusplus
