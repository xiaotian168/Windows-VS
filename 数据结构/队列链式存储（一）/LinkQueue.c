#include"LinkQueue.h"

//初始化队列
int Init_LinkQueue(void **q)
{
	if (NULL == q)
	{
		return -1;
	}

	LQueue *queue = (LQueue *)calloc(1, sizeof(LQueue));	//为队列分配空间
	if (NULL == queue)
	{
		return -2;
	}
	queue->Header.next = NULL;
	queue->size = 0;
	queue->rear = &(queue->Header);		//rear为尾结点；开始是指向头结点

	*q = queue;
	return 0;
}

//入队
int Push_LinkQueue(LinkQueue queue, void *data)
{
	if (NULL == queue)
	{
		return -1;
	}

	if (NULL == data)
	{
		return -2;
	}

	LQueue *pQue = (LQueue *)queue;
	//为新节点元素开辟空间
	LinkNode *pNew = (LinkNode *)calloc(1, sizeof(LinkNode));
	if (NULL == pNew)
	{
		return -3;
	}
	pNew->data = data;	//赋值
	pNew->next = NULL;

	pQue->rear->next = pNew;	//入队
	pQue->rear = pNew;	//更新尾结点
	pQue->size++;
	return 0;
}

//出队
int Pop_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	LQueue *pQue = (LQueue *)queue;
	if (0 == pQue->size)	//队列中没有元素
	{
		return 0;
	}

	LinkNode *pDel = pQue->Header.next;	//保存删除的节点
	pQue->Header.next = pDel->next;	//更新首节点
	free(pDel);//释放要删除的节点
	pDel = NULL;

	if (1 == pQue->size)	//只有一个节点要更新尾结点信息
	{
		pQue->rear = &(pQue->Header);	//重置尾结点
	}

	pQue->size--;	//更新大小
	return 0;
}

//获取队尾元素
void* Back_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}

	LQueue *pQue = (LQueue *)queue;
	if (0 == pQue->size)
	{
		return NULL;
	}

	return pQue->rear->data;
}

//获取队头元素
void* Front_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return NULL;
	}

	LQueue *pQue = (LQueue *)queue;
	if (0 == pQue->size)
	{
		return NULL;
	}

	return pQue->Header.next->data;
}

//获取队列大小
int Size_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	LQueue *pQue = (LQueue *)queue;
	return pQue->size;
}

//销毁队列
int Destroy_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	LQueue *pQue = (LQueue *)queue;
	LinkNode *pCur = pQue->Header.next;	//辅助指针，指向当前节点
	LinkNode *pDel = NULL;
	while (pCur != NULL)
	{
		pDel = pCur;	//保存要释放节点的地址
		pCur = pCur->next;	//更新当前节点的指向
		free(pDel);//释放要释放的节点
	}

	free(queue);	//释放队列内存
	queue = NULL;
}
