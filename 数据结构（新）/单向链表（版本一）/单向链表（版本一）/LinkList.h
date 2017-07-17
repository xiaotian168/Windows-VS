#pragma once
#include<stdio.h>
#include<stdlib.h>


//��������һϵ�нڵ����
//��������ڵ����������
struct LinkNode
{
	void *data;
	struct LinkNode *next;
};

//������������ݽṹ
struct LList
{
	struct LinkNode Header;	//ͷ���
	int size;	//�����С
};

typedef void* LinkList;
typedef void* LinkNode;

//Ϊ��C++�е��ô˺���
//c++����Ҫд�˺꣬C��������Ҫд
#ifdef __cplusplus
extern "C"{
#endif

	//��ʼ������
	LinkList Init_LinkList();

	//ָ��λ�ò�������
	void Insert_LinkList(LinkList list, int pos,void* data);

	//ͷ����������
	void PushFront_LinkList(LinkList list, void* data);

	//β����������
	void PushBack_LinkList(LinkList list, void* data);

	//ָ��λ��ɾ������ɾ��
	void Remove_LinkList(LinkList list, int pos);

	//ͷ��ɾ������
	void PopFront_LinkList(LinkList list);

	//β��ɾ������
	void PopBack_LinkList(LinkList list);

	//��ֵɾ������
	void RemoveByVal_LinkList(LinkList list, void* data, int (*myCompare)(void* d1, void* d2));

	//����
	void Foreach_LinkList(LinkList list, void(*myForeach)(void *));

	//��ȡ�����С
	int Size_LinkList(LinkList list);
	
	//������ڵ���Ѱ��һ���ض���ֵ��������ָ��ýڵ�ֵ��ָ�롣
	LinkNode Get_Value(LinkList list, int(*valfound)(void *, int *), void *val);
	
	//�����ӡ����
	void print_LinkList(LinkList list, void(*myForeach)(void *));

	//�����ӡ���ݹ麯��
	void Lnvers(void *node, void(*myForeach)(void *));

	//��������
	void Destroy_LinkList(LinkList list);

#ifdef __cplusplus
}
#endif