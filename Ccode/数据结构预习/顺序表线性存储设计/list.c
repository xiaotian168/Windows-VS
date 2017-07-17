#include <stdio.h>
#include <stdlib.h>
#include "list.h"


//����������һ���յ����Ա�����ָ�����Ա��ܳ���,�ڵ������������
List* List_Create(int Cay)
{
	if (Cay <= 0)	//�쳣����
	{
		fprintf(stdout, "��������������������0\n");
		return NULL;
	}
	Sql_list *pList = (Sql_list *)calloc(1, sizeof(Sql_list));	//Ϊ���Ա����洢�ռ�
	if (pList == NULL)
	{
		fprintf(stdout, "����ռ����ʧ�ܣ�calloc failed\n");
		return NULL;
	}
	pList->node = (unsigned int *)calloc(Cay, sizeof(unsigned int));
	if(pList->node == NULL)
	{
		fprintf(stdout, "����ڵ�ռ����ʧ�ܣ�calloc failed\n");
		free(pList);
		pList = NULL;
	}
	pList->Cay = Cay;
	pList->len = 0;
	return pList;	//���ؿ������׵�ַ
}

//����һ�����Ա�
void List_Destroy(List* list)
{
	Sql_list *tmp = (Sql_list *)list;
	if (tmp)
	{
		if (tmp->node)
		{
			free(tmp->node);	//�ͷŽڵ�ռ�
			tmp->node = NULL;
		}
		free(tmp);	//�ͷŶ��з��������ռ�
	}
}

//��һ�����Ա�list�е�����Ԫ����գ����Ա�ص�����ʱ�ĳ�ʼ״̬
int List_Clear(List* list)
{
	Sql_list *tmp = (Sql_list *)list;
	if (tmp == NULL )	//�쳣����
		return -1;
	tmp->len = 0;
	return 1;
}

//����һ�����Ա�list�е�����Ԫ�ظ���
int List_Length(List* list)
{
	Sql_list *tmp = (Sql_list *)list;
	if (tmp == NULL)	//�쳣����
		return -1;
	return tmp->len;
}

//��һ�����Ա�list��posλ�ô�������Ԫ��node
int List_Insert(List* list, ListNode* node, int pos)
{
	Sql_list *tmp = (Sql_list *)list;
	unsigned int t_node = *(unsigned int*)node;
	if (tmp == NULL || node == NULL || pos < 0)
	{
		fprintf(stdout, "û�д������Ա�\n");
		return -1;
	}
	if (tmp->len < tmp->Cay)	//�ж����Ա�û��������Բ���ָ��λ��Ԫ��
	{
		if (pos >= tmp->len)	//����λ����ʵ��λ�ú��棬����Ϊ��β������
			pos = tmp->len;
		for (int i = tmp->len; i > pos; --i)
		{
			tmp->node[i] = tmp->node[i - 1];
		}
		tmp->node[pos] = t_node;	//��posλ�ò���Ԫ��
		tmp->len++;
		return 0;
	}
	else
	{
		fprintf(stdout, "���Ա������������޷�����ڵ�\n");
		return -2;
	}
}

//��ȡһ�����Ա�list��posλ�ô���Ԫ�صĵ�ַ
ListNode *List_Get(List *list, int pos)
{
	if (list == NULL || pos < 0)
	{
		fprintf(stdout, "list == NULL || pos < 0");
		return NULL;
	}
	Sql_list *tmp = (Sql_list *)list;
	if (pos < tmp->len)
		return &tmp->node[pos];
	else
	{
		fprintf(stdout, "%d��λ��û��ֵ\n", pos);
		return NULL;
	}
}

//��ȡһ�����Ա�list��posλ�ô���Ԫ�� ����ֵΪ��ɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
ListNode* List_Delete(List* list, int pos)
{
	if (list == NULL || pos < 0)
	{
		fprintf(stdout, "list == NULL || pos < 0");
		return NULL;
	}
	Sql_list *tmp = (Sql_list *)list;
	if (pos < tmp->len)
	{
		unsigned int *tnode = &tmp->node[pos];	//���汻ɾ��Ԫ�ص�ַ
		printf("\n��%d��λ�õ�Ԫ��ɾ���ɹ�\n", pos);
		for (int i = pos; i < tmp->len - 1; ++i)
		{
			tmp->node[i] = tmp->node[i + 1];
		}
		tmp->len--;
		return &tmp->node[pos];
	}
	else
	{
		fprintf(stdout, "%d��λ��û��ֵ\n", pos);
		return NULL;
	}
}