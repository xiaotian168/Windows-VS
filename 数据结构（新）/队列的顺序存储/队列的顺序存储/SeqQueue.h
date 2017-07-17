#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024

//������е����ݽṹ
typedef struct SQueue
{
	void* data[MAXSIZE];	//�������ݵ�����
	int size;	//��С
}SQueue;

typedef void* SeqQueue;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	//��ʼ������
	SeqQueue Init_SeqQueue();

	//���
	int Push_SeqQueue(SeqQueue queue, void* data);

	//����
	int Pop_SeqQueue(SeqQueue queue);

	//��ȡ��ͷԪ��
	void* Front_SeqQueue(SeqQueue queue);

	//��ȡ��βԪ��
	void* Rear_SeqQueue(SeqQueue queue);

	//��ȡ���д�С��������Ԫ�ظ�����
	int Size_SeqQueue(SeqQueue queue);

	//���ٶ���
	int Destroy_SeqQueue(SeqQueue queue);

#ifdef __cplusplus
}
#endif // __cplusplus


