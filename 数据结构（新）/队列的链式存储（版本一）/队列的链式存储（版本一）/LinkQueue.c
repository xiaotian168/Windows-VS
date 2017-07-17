#include"LinkQueue.h"

//初始化队列
LinkQueue Init_LinkQueue()
{
	//为队列分配存储空间
	LQueue *queue = (LQueue *)calloc(1, sizeof(LQueue));
	//初始化
	queue->header.next = NULL;
	queue->rear = &(queue->header);
	queue->size = 0;

	return queue;
}

//入队
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
	//为新节点分配存储空间
	QueueNode *pNew = (QueueNode *)calloc(1, sizeof(QueueNode));
	pNew->data = data;
	pNew->next = NULL;

	//尾插法
	q->rear->next = pNew;
	//更新尾结点
	q->rear = pNew;
	q->size++;

	return 0;
}

//出队
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

//获取队头元素
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

//获取队尾元素
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

//获取队列大小
int Size_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	LQueue *q = (LQueue *)queue;
	return q->size;
}

//销毁队列
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
