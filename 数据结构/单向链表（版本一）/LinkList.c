#include"LinkList.h"

//��������ݽṹ
struct LList
{
	struct LinkNode Header;	//ͷ���
	int size;	//�����С
};

//��ʼ�� 
LinkList Init_LinkList()
{
	//Ϊ�����ٿռ�
	struct LList *list = malloc(sizeof(struct LList));
	if (NULL == list)	//�쳣����
		return NULL;
	list->Header.data = NULL;
	list->Header.next = NULL;
	list->size = 0;
}
//����
void Insert_LinkList(LinkList list, int pos, void *data)
{
	if (NULL == list || NULL == data )	//�쳣����
	{
		return;
	}
	struct LList *pList = (struct LList *)list;

	if (pos > pList->size || pos < 0)	//��������λ�ô��������С����С��0�����β������
	{
		pos = pList->size;
	}
	
	//Ϊ�½ڵ����ռ�
	struct LinkNode *pNew = (struct LinkNode *)calloc(1, sizeof(struct  LinkNode));
	if (NULL == pNew)
	{
		printf("û�п����ڴ�Ϊ�½ڵ����ռ���\n");
	}
	pNew->data = data;	//��ֵ
	pNew->next = NULL;

	//�ҵ�posλ�õĲ����
	struct LinkNode *pCur = &(pList->Header);
	for (int i = 0; i < pos; ++i)
	{
		pCur = pCur->next;
	}

	//�����ڵ��ϵ
	pNew->next = pCur->next;
	pCur->next = pNew;

	pList->size++;	//����������
}
//ɾ��
void Remove_LinkList(LinkList list, int pos)
{
	struct LList *pList = (struct LList *)list;
	if (NULL == list || pos < 0 || pos >= pList->size || pList->size == 0)	//�쳣����
	{
		return;
	}

	struct LinkNode *pCur = &(pList->Header);
	//�ƶ��ڵ㵽ɾ����λ�õ�ǰһ���ڵ�
	for (int i = 0; i < pos; ++i)
	{
		pCur = pCur->next;
	}

	//�Ȼ���Ҫɾ���Ľڵ�
	struct LinkNode *pTmp = pCur->next;
	//���½�����ϵ
	pCur->next = pTmp->next;
	//�ͷ�Ҫɾ���Ľڵ�
	free(pTmp);
	pTmp = NULL;
	
	pList->size--;

}
//����
void Foreach_LinkList(LinkList list, void(*myforeach)(void *))
{
	if (NULL == list || NULL == myforeach)	//�쳣����
	{
		return;
	}

	struct LList *pList = (struct LList *)list;

	//����ָ�룬ָ��ǰ�ڵ㣨���׽ڵ㿪ʼ��
	struct LinkNode *pCur = pList->Header.next;
	while (pCur != NULL)
	{
		myforeach(pCur->data);
		pCur = pCur->next;
	}
}
//����
void Destroy_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}

	struct LList *pList = (struct LList *)list;

	//����ָ�룬ָ�������׽ڵ�
	struct LinkNode *pCur = pList->Header.next;
	struct LinkNode *Del = NULL;
	while (pCur != NULL)	//�ͷŽڵ�ռ�
	{
		Del = pCur->next;
		free(pCur);
		pCur = Del;
	}
	free(pList);	//�ͷ�����ռ�
	pList = NULL;

}
//��ȡ�����С
int Size_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return 0;
	}
	struct LList *pList = (struct LList *)list;
	return pList->size;
}

//������ڵ���Ѱ��һ���ض���ֵ��������ָ��ýڵ�ֵ��ָ�롣
LinkNode Get_Value(LinkList list, int(*valfound)(void *, int *), void *val)
{
	if (NULL == list || NULL == valfound)	//�쳣����
	{
		return;
	}

	struct LList *pList = (struct LList *)list;
	int *my_val = (int *)val;	

	//����ָ�룬ָ��ǰ�ڵ㣨���׽ڵ㿪ʼ��
	struct LinkNode *pCur = pList->Header.next;
	while (pCur != NULL)
	{
		if (0 == valfound(pCur->data, my_val))	//�ҵ��ض���ֵ
		{
			return pCur->data;
		}
		pCur = pCur->next;
	}
	return NULL;
}

//�����ӡ���ݹ麯����ص�����һ��ʹ��
void Lnvers(void *node, void(*myforeach)(void *))
{
	struct LinkNode *pCur = (struct LinkNode*)node;
	if (pCur->next == NULL)
	{
		myforeach(pCur->data);	//���ûص���������ӡβ��������Ϣ
		return;
	}
	Lnvers(pCur->next, myforeach);
	myforeach(pCur->data);	//���ûص���������ӡ��ǰ�ڵ���Ϣ
}

//�����ӡ����
void print_LinkList(LinkList list, void(*myforeach)(void *))
{
	if (NULL == list)
		return;

	struct LList *pList = (struct LList *)list;
	if (NULL == pList->Header.next)
		return;
	//����ָ�룬ָ��ǰ�ڵ㣨���׽ڵ㿪ʼ��
	struct LinkNode *pCur = pList->Header.next;
	//for (int j = pList->size; j > 0; --j)
	//{
	//	for (int i = 1; i < j; ++i)
	//	{
	//		pCur = pCur->next;
	//	}
	//	//���ûص�����
	//	myforeach(pCur->data);
	//	pCur = pList->Header.next;	//pCur����ָ���׽ڵ�
	//}
	
	//���������ݹ�
	Lnvers(pCur, myforeach);
}
