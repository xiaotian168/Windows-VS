#include"LinkList.h"

//��ʼ������
LinkList *Init_LinkList()
{
	LinkList *list = (LinkList *)calloc(1, sizeof(sizeof(LinkList)));	//Ϊ�������ռ�
	list->header.next = NULL;
	list->size = 0;

	return list;
}

//���뺯��
void Insert_LinkList(LinkList *list, int pos, void *data)
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	if (pos < 0 || pos > list->size)	//����λ�þ���
	{
		pos = list->size;
	}

	LinkNode *pCur = &(list->header);		//���嵱ǰ�ڵ�
	for (int i = 0; i < pos; ++i)	//�ƶ���ǰ�ڵ㵽�����λ��
	{
		pCur = pCur->next;
	}
	LinkNode *pNew = (LinkNode *)data;	//�����½ڵ��ַ
	pNew->next = pCur->next;	//���浱ǰ�ڵ��next
	pCur->next = pNew;	//��ǰ�ڵ�ָ���½ڵ�

	list->size++;
}

//��������
void Foreach_LinkList(LinkList *list, void(*myforeach)(void *))
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}

	LinkNode *pCur = list->header.next;	//����ָ�룻ָ��ǰ�ڵ�
	for (int i = 0; i < list->size; ++i)
	{
		myforeach(pCur);
		pCur = pCur->next;
	}
}

//��������
void Inverted_LinkList(LinkList *list)
{
	if (NULL == list)
	{
		return;
	}

	if (list->size <= 1)
	{
		return;
	}

	LinkNode *pPre = list->header.next;	//����ָ�룻ָ���׽ڵ�
	LinkNode *pCur = pPre->next; // ����ָ�룻ָ����һ���ڵ�
	LinkNode *tmp = NULL;
	while (pCur != NULL)
	{
		tmp = pCur->next;	//���浱ǰ�ڵ��ָ��
		pCur->next = pPre;	//��ǰ�ڵ�ָ��ǰһ���ڵ�
		pPre = pCur;	//pPre�ƶ���pCur
		pCur = tmp;		//pCur�ƶ���pCur.next
	}

	//�ȱ���β���
	list->header.next->next = NULL;
	//����ͷ���
	list->header.next = pPre;
}

//ɾ������
void Remove_LinkList(LinkList *list, int pos)
{
	if (NULL == list)
	{
		return;
	}

	if (pos < 0 || pos >= list->size)
	{
		return;
	}

	LinkNode *pCur = &(list->header);
	for (int i = 0; i < pos; ++i)	//�ƶ���ǰ�ڵ㵽ɾ���ڵ��ǰһ��λ��
	{
		pCur = pCur->next;
	}

	//���½����ڵ��ϵ
	pCur->next = pCur->next->next;

	list->size--;
}

//��������
void Destroy_LinkList(LinkList *list)
{
	if (NULL == list)
	{
		return;
	}

	list->size = 0;
	free(list);
	list = NULL;
}