#include"SeqQueue.h"

//初始化队列
SeqQueue Init_SeqQueue()
{
	//为队列分配存储空间
	SQueue *queue = (SQueue *)calloc(1, sizeof(SQueue));
	//初始化
	for (int i = 0; i < MAXSIZE; ++i)
	{
		queue->data[i] = NULL;
	}
	queue->size = 0;

	return queue;
}

//入队
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

//出队
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

//获取队头元素
void* Front_SeqQueue(SeqQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}
	
	SQueue *q = (SQueue *)queue;
	return q->data[0];
}

//获取队尾元素
void* Rear_SeqQueue(SeqQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}

	SQueue *q = (SQueue *)queue;
	return q->data[q->size - 1];
}

//获取队列大小（队列中元素个数）
int Size_SeqQueue(SeqQueue queue) 
{
	if(NULL == queue)
	{
		return -1;
	}

	SQueue *q = (SQueue *)queue;
	return q->size;
}

//销毁队列
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