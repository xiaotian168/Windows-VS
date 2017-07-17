#include"LinkQueue.h"

//��ʼ������
LinkQueue Init_LinkQueue()
{
	//Ϊ���з���洢�ռ�
	LQueue *queue = (LQueue *)calloc(1, sizeof(LQueue));
	//��ʼ��
	queue->header.next = NULL;
	queue->rear = &(queue->header);
	queue->size = 0;

	return queue;
}

//���
int Push_LinkQueue(LinkQueue queue, void* data)
{
	if (NULL == queue)
	{
		return -1;
	}

	if (NULL == data)
	{
		return -2;
	}

	LQueue *q = (LQueue *)queue;
	QueueNode *pNew = (QueueNode *)data;
	pNew->next = NULL;
	//β�巨
	q->rear->next = pNew;
	q->rear = pNew;		//����β�ڵ�
	q->size++;

	return 0;
}

//����
int Pop_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	LQueue *q = (LQueue *)queue;
	if (q->size <= 0)
	{
		return -2;
	}
	q->header.next = q->header.next->next;
	q->size--;

	return 0;
}

//��ȡ��ͷԪ��
void* Front_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}

	LQueue *q = (LQueue *)queue;

	return q->header.next;
}

//��ȡ��βԪ��
void* Rear_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}

	LQueue *q = (LQueue *)queue;
	
	return q->rear;
}

//��ȡ���д�С
int Size_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	LQueue *q = (LQueue *)queue;

	return q->size;
}

//���ٶ���
int Destroy_LinkQueue(LinkQueue queue)
{
	if (queue != NULL)
	{
		free(queue);
		queue = NULL;
		return 0;
	}

	return -1;
}