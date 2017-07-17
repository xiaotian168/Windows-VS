#include"LinkList.h"

//�������������
struct LList
{
	struct LinkNode header; //ͷ���
	int size; //�����С
	//struct LinkNode *rear; //ָ��β���ڵ�
};

//��ʼ��  ��׺��ҪΪ�˷�ֹ������ͻ
LinkList Init_LinkList()
{
	struct LList *list = malloc(sizeof(struct LList));
	list->header.data = NULL;
	list->header.next = NULL;
	list->size = 0;

	return list;
}
//����
void Insert_LinkList(LinkList list, int pos, void *data)
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct LList *mylist = (struct LList *)list;

	if (pos < 0 || pos > mylist->size)
	{
		pos = mylist->size;
	}

	//����ָ�����
	struct LinkNode *pCurrent = &(mylist->header);
	//��λ��
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//1. �����½ڵ�
	struct LinkNode *newnode = malloc(sizeof(struct LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//2. �½��������
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	mylist->size++;

}
//ɾ��
void Remove_LinkList(LinkList list, int pos)
{
	if (NULL == list)
	{
		return;
	}

	struct LList *mylist = (struct LList *)list;

	if (pos < 0 || pos > mylist->size - 1)
	{
		return;
	}

	if (mylist->size == 0)
	{
		return;
	}

	//�ҵ�ɾ��λ�õ�ǰһ��λ�õĽڵ�
	struct LinkNode *pCurrent = &(mylist->header);

	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//�Ȼ����´�ɾ���ڵ�
	struct LinkNode *pDel = pCurrent->next;
	//���½�����ɾ���ڵ��ǰ���ͺ�̽ڵ��ϵ
	pCurrent->next = pDel->next;
	//�ͷ�ɾ���ڵ���ڴ�
	free(pDel);
	pDel = NULL;

	mylist->size--;
}
//����
void Foreach_LinkList(LinkList list, void(*myforeach)(void *))
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}

	struct LList *mylist = (struct LList *)list;

	//����ָ��
	struct LinkNode *pCurrent = mylist->header.next;
	while (pCurrent != NULL)
	{
		myforeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}

}
//����
void Destroy_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}


	struct LList *mylist = (struct LList *)list;
	//����ָ��
	struct LinkNode *pCurrent = mylist->header.next;

	struct LinkNode *pNext = NULL;
	while (pCurrent != NULL)
	{
		//�Ȼ��浱ǰ�ڵ����һ���ڵ�
		pNext = pCurrent->next;
		//���ĵ��ͷŵ�ǰ�ڵ���ڴ�
		free(pCurrent);

		pCurrent = pNext;
	}


	free(mylist);
	mylist = NULL;
}

int Size_LinkList(LinkList list)
{

	if (NULL == list)
	{
		return -1;
	}

	struct LList *mylist = (struct LList *)list;

	return mylist->size;
}

void* Search_LinkList(LinkList list, void *data, bool(*compare)(void*, void*))
{
	if (NULL == list)
	{
		return NULL;
	}

	if (NULL == data)
	{
		return NULL;
	}
	if (NULL == compare)
	{
		return NULL;
	}

	struct LList *mylist = (struct LList *)list;

	//����ָ�����
	struct LinkNode *pCurrent = mylist->header.next;
	while (pCurrent != NULL)
	{
		if (compare(pCurrent->data, data))
		{
			break;
		}

		pCurrent = pCurrent->next;
	}

	if (pCurrent == NULL)
	{
		return NULL;
	}

	return pCurrent->data;
}

void ReverseForeach_LinkList(LinkList list, void(*myforeach)(void *))
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}

	struct LList *mylist = (struct LList *)list;

	RecursionForeach(mylist->header.next, myforeach);

}

static void RecursionForeach(struct LinkNode *node, void(*myforeach)(void *))
{
	if (NULL == node)
	{
		return;
	}

	RecursionForeach(node->next, myforeach);

	myforeach(node->data);
}