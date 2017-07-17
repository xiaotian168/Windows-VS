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
	while (pCur != NULL) 
	{
		myforeach(pCur);
		pCur = pCur->next;
	}
}

//�������򣨷�תA->B->C-D��Ϊ��D->C->B-A��
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

//��������
void Sort_LinkList(LinkList *list, int(*myCompare)(void *, void *))
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == myCompare)
	{
		return;
	}

	if (list->size < 2)
	{
		return;
	}

	//��������
	LinkNode *pPre = list->header.next;		//��һ���ڵ�
	LinkNode *pCur = pPre->next;	//��ǰ�ڵ�
	LinkNode *tmp = NULL;
	
	while(pCur != NULL)	//(����)
	{
		tmp = &(list->header);
		int pos = 0;	//��¼������λ��
		if (myCompare(pPre, pCur) > 0)	//˵����Ҫ����
		{
			while (myCompare(tmp->next, pCur) < 0 )		//���Ҳ����λ��
			{
				pos++;
				tmp = tmp->next;
			}
			pPre->next = pCur->next;	//�Ȼ��嵱ǰ�ڵ��next,���Ҷϵ���ǰ�ڵ�����			
			Insert_LinkList(list, pos, pCur);	//����ڵ㣨����ǰ�ڵ���뵽�ҵ��Ĳ���λ�ã�		
			pCur = pPre->next;	//��ǰ�ڵ��ƶ���next
			list->size--;

			//LinkNode *p1 = pCur->next;	//�Ȼ��嵱ǰ�ڵ��next
			//Insert_LinkList(list, pos, pCur);	//����ڵ�
			//pPre->next = p1;	//��һ���ڵ��nextָ��ǰ�ڵ��next
			//pCur = p1;	//��ǰ�ڵ��ƶ���next
		}
		else
		{
			pPre = pPre->next;
			pCur = pCur->next;
		}
	}
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