#include"SeqQueue.h"

//��ʼ������
SeqQueue Init_SeqQueue()
{
	//Ϊ���з���洢�ռ�
	SQueue *queue = (SQueue *)calloc(1, sizeof(SQueue));
	//��ʼ��
	for (int i = 0; i < MAXSIZE; ++i)
	{
		queue->data[i] = NULL;
	}
	queue->size = 0;

	return queue;
}

//���
int Push_SeqQueue(SeqQueue queue, void* data)
{
	if (NULL == queue)
	{
		return -1;
	}

	if (NULL == data)
	{
		return -2;
	}

	SQueue *q = (SQueue *)queue;
	if (q->size >= MAXSIZE)
	{
		return -3;
	}

	q->data[q->size] = data;
	q->size++;

	return 0;
}

//����
int Pop_SeqQueue(SeqQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}
	
	SQueue *q = (SQueue *)queue;
	for (int i = 0; i < q->size - 1; ++i)
	{
		q->data[i] = q->data[i + 1];
	}
	q->size--;

	return 0;
}

//��ȡ��ͷԪ��
void* Front_SeqQueue(SeqQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}
	
	SQueue *q = (SQueue *)queue;
	return q->data[0];
}

//��ȡ��βԪ��
void* Rear_SeqQueue(SeqQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}

	SQueue *q = (SQueue *)queue;
	return q->data[q->size - 1];
}

//��ȡ���д�С��������Ԫ�ظ�����
int Size_SeqQueue(SeqQueue queue) 
{
	if(NULL == queue)
	{
		return -1;
	}

	SQueue *q = (SQueue *)queue;
	return q->size;
}

//���ٶ���
int Destroy_SeqQueue(SeqQueue queue)
{
	if (queue != NULL)
	{
		free(queue);
		queue = NULL;
		return 0;
	}

	return -1;
}