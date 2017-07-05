#include"SeqQueue.h"

//��ʼ������
int Init_SQueue(SeqQueue *queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	SQueue *p = (SQueue *)calloc(1,sizeof(SQueue));	//Ϊ���з���ռ�
	if (NULL == p)
	{
		return -2;
	}

	//��ʼ��������ݵ�����
	for (int i = 0; i < MAXSIZE; ++i)
	{
		p->data[i] = NULL;
	}
	p->size = 0;

	*queue = p;
	return 0;
}

//���
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
	p->data[p->size] = data;	//�������
	p->size++;	//���´�С

	return 0;
}

//����
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

	//Ԫ�س��ӣ�
	for (int i = 0; i < p->size - 1; ++i)
	{
		p->data[i] = p->data[i + 1];
	}
	p->size--;

	return 0;
}

//��ȡ��ͷԪ��
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

//��ȡ��βԪ��
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

//��ȡ����Ԫ�ظ���
int Size_SQueue(SeqQueue queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	SQueue *p = (SQueue *)queue;
	return p->size;
}

//���ٶ���
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
