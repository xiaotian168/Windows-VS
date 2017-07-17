#pragma once	//��ֹͷ�ļ��ظ�����

typedef void List;
typedef void ListNode;

typedef struct Sql_list	//���Ա�ṹ
{
	int len;	//����
	int Cay;	//����
	unsigned int *node;	//���Ա�ڵ�
}Sql_list;

//����������һ���յ����Ա�
List* List_Create(int Cay);

//����һ�����Ա�
void List_Destroy(List* list);

//��һ�����Ա�list�е�����Ԫ����գ����Ա�ص�����ʱ�ĳ�ʼ״̬
int List_Clear(List* list);

//����һ�����Ա�list�е�����Ԫ�ظ���
int List_Length(List* list);

//��һ�����Ա�list��posλ�ô�������Ԫ��node
int List_Insert(List* list, ListNode* node, int pos);

ListNode *List_Get(List *list, int pos);

//��ȡһ�����Ա�list��posλ�ô���Ԫ�� ����ֵΪ��ɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
ListNode* List_Delete(List* list, int pos);