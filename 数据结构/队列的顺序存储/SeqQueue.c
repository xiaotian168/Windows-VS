#include"SeqQueue.h"

//初始化队列
int Init_SQueue(SeqQueue *queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	SQueue *p = (SQueue *)calloc(1,sizeof(SQueue));	//为队列分配空间
	if (NULL == p)
	{
		return -2;
	}

	//初始化存放数据的数组
	for (int i = 0; i < MAXSIZE; ++i)
	{
		p->data[i] = NULL;
	}
	p->size = 0;

	*queue = p;
	return 0;
}

//入队
int Push_SQueue(SeqQueue queue, void *data)
{
	if (NULL == queue)
	{
		return -1;
	}

	if (NULL == data)
	{
		return -2;
	}

	SQueue *p = (SQueue *)queue;
	if (MAXSIZE == p->size)
	{
		return -3;
	}
	p->data[p->size] = data;	//数据入队
	p->size++;	//更新大小

	return 0;
}

//出队
int Pop_SQueue(SeqQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	SQueue *p = (SQueue *)queue;
	if (0 == p->size)
	{
		return 0;
	}

	//元素出队；
	for (int i = 0; i < p->size - 1; ++i)
	{
		p->data[i] = p->data[i + 1];
	}
	p->size--;

	return 0;
}

//获取队头元素
void* Front_SQueue(SeqQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}

	SQueue *p = (SQueue *)queue;
	if (0 == p->size)
	{
		return NULL;
	}

	return p->data[0];
}

//获取队尾元素
void* Rear_SQueue(SeqQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}

	SQueue *p = (SQueue *)queue;
	if (0 == p->size)
	{
		return NULL;
	}
	return p->data[p->size - 1];
}

//获取队列元素个数
int Size_SQueue(SeqQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	SQueue *p = (SQueue *)queue;
	return p->size;
}

//销毁队列
int Destroy_SQueue(SeqQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	free(queue);
	queue = NULL;

	return 0;
}
