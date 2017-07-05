#pragma once
#include<stdlib.h>

//����ڵ����ݽṹ
typedef struct LinkNode
{
	void *data;
	struct LinkNode *next;
}LinkNode;

//����������ݽṹ
typedef struct LQueue
{
	LinkNode Header;	//ͷ���
	int size;
	LinkNode *rear;	//β���
}LQueue;

typedef void* LinkQueue;

#ifdef __cplusplus
extern "C" {
#endif 
	
	//��ʼ������
	int Init_LinkQueue(void **q);

	//���
	int Push_LinkQueue(LinkQueue queue, void *data);

	//����
	int Pop_LinkQueue(LinkQueue queue);

	//��ȡ��βԪ��
	void* Back_LinkQueue(LinkQueue queue);

	//��ȡ��ͷԪ��
	void* Front_LinkQueue(LinkQueue queue);

	//��ȡ���д�С
	int Size_LinkQueue(LinkQueue queue);

	//���ٶ���
	int Destroy_LinkQueue(LinkQueue queue);

#ifdef __cplusplus
}
#endif
