#pragma once
#include<stdlib.h>

#define MAXSIZE 1024

//����������ݽṹ
typedef struct SQueue
{
	void *data[MAXSIZE];	//�������ݵ�����
	int size;	//��С
}SQueue;

typedef void* SeqQueue;

#ifdef __cplusplus
extern "C" {
#endif

	//��ʼ������
	int Init_SQueue(SeqQueue *queue);

	//���
	int Push_SQueue(SeqQueue queue, void *data);

	//����
	int Pop_SQueue(SeqQueue queue);

	//��ȡ��ͷԪ��
	void* Front_SQueue(SeqQueue queue);

	//��ȡ��βԪ��
	void* Rear_SQueue(SeqQueue queue);

	//��ȡ����Ԫ�ظ���
	int Size_SQueue(SeqQueue queue);

	//���ٶ���
	int Destroy_SQueue(SeqQueue queue);

#ifdef __cplusplus
}
#endif
