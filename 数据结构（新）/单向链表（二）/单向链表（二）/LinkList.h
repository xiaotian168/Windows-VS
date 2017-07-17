#pragma once
#include<stdio.h>
#include<stdlib.h>

//����ڵ���������
typedef struct LinkNode
{
	struct LinkNode *next;
}LinkNode;

//����������������
typedef struct LinkList
{
	LinkNode header;
	int size;
}LinkList;

#ifdef __cplusplus
extern "C" {
#endif 

	//��ʼ��
	/*
	�����ʼ��
	@return ��������ָ��
	*/
	LinkList *Init_LinkList();

	//����
	/*
	��������ָ��λ�ò�������
	@param list ����ָ��
	@param pos ����λ��
	@param data ��������
	*/
	void Insert_LinkList(LinkList *list, int pos, void *data);


	//����
	/*
	��������
	@param list ����ָ��
	@param myforeach �����ص�����
	*/
	void Foreach_LinkList(LinkList *list, void (*myforeach)(void *));

	//�������򣨷�ת��
	void Inverted_LinkList(LinkList *list);

	//��������
	void Sort_LinkList(LinkList *list, int (*mycompare)(void *, void *));

	//ɾ��
	/*
	ɾ��ָ��λ�õĽڵ�
	@param list ����ָ��
	@param pos ɾ��λ��
	*/
	void Remove_LinkList(LinkList *list, int pos);

	//��������
	/*
	��������
	@param list ����ָ��
	*/
	void Destroy_LinkList(LinkList *list);

#ifdef __cplusplus
}
#endif
