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
	//Ϊ�½ڵ����洢�ռ�
	QueueNode *pNew = (QueueNode *)calloc(1, sizeof(QueueNode));
	pNew->data = data;
	pNew->next = NULL;

	//β�巨
	q->rear->next = pNew;
	//����β���
	q->rear = pNew;
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
	QueueNode *pDel = q->header.next;
	q->header.next = q->header.next->next;
	free(pDel);
	pDel = NULL;
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
	if (q->size <= 0)
	{
		return NULL;
	}
	return q->header.next->data;
}

//��ȡ��βԪ��
void* Rear_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}

	LQueue *q = (LQueue *)queue;
	if (q->size <= 0)
	{
		return NULL;
	}
	return q->rear->data;
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
	if (NULL == queue)
	{
		return -1;
	}

	LQueue *q = (LQueue *)queue;
	QueueNode *pCur = q->header.next;
	QueueNode *pDel = NULL;
	while (pCur != NULL)
	{
		pDel = pCur;
		pCur = pCur->next;
		free(pDel);
		pDel = NULL;
	}

	free(queue);
	queue = NULL;

	return 0;
}
