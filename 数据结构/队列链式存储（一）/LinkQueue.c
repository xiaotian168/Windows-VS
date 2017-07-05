#include"LinkQueue.h"

//��ʼ������
int Init_LinkQueue(void **q)
{
	if (NULL == q)
	{
		return -1;
	}

	LQueue *queue = (LQueue *)calloc(1, sizeof(LQueue));	//Ϊ���з���ռ�
	if (NULL == queue)
	{
		return -2;
	}
	queue->Header.next = NULL;
	queue->size = 0;
	queue->rear = &(queue->Header);		//rearΪβ��㣻��ʼ��ָ��ͷ���

	*q = queue;
	return 0;
}

//���
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
	//Ϊ�½ڵ�Ԫ�ؿ��ٿռ�
	LinkNode *pNew = (LinkNode *)calloc(1, sizeof(LinkNode));
	if (NULL == pNew)
	{
		return -3;
	}
	pNew->data = data;	//��ֵ
	pNew->next = NULL;

	pQue->rear->next = pNew;	//���
	pQue->rear = pNew;	//����β���
	pQue->size++;
	return 0;
}

//����
int Pop_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	LQueue *pQue = (LQueue *)queue;
	if (0 == pQue->size)	//������û��Ԫ��
	{
		return 0;
	}

	LinkNode *pDel = pQue->Header.next;	//����ɾ���Ľڵ�
	pQue->Header.next = pDel->next;	//�����׽ڵ�
	free(pDel);//�ͷ�Ҫɾ���Ľڵ�
	pDel = NULL;

	if (1 == pQue->size)	//ֻ��һ���ڵ�Ҫ����β�����Ϣ
	{
		pQue->rear = &(pQue->Header);	//����β���
	}

	pQue->size--;	//���´�С
	return 0;
}

//��ȡ��βԪ��
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

//��ȡ��ͷԪ��
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

//��ȡ���д�С
int Size_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	LQueue *pQue = (LQueue *)queue;
	return pQue->size;
}

//���ٶ���
int Destroy_LinkQueue(LinkQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	LQueue *pQue = (LQueue *)queue;
	LinkNode *pCur = pQue->Header.next;	//����ָ�룬ָ��ǰ�ڵ�
	LinkNode *pDel = NULL;
	while (pCur != NULL)
	{
		pDel = pCur;	//����Ҫ�ͷŽڵ�ĵ�ַ
		pCur = pCur->next;	//���µ�ǰ�ڵ��ָ��
		free(pDel);//�ͷ�Ҫ�ͷŵĽڵ�
	}

	free(queue);	//�ͷŶ����ڴ�
	queue = NULL;
}
