#pragma once

#include<stdlib.h>


//��������һϵ�нڵ����
//��������ڵ����������
struct LinkNode
{
	void *data;
	struct LinkNode *next;
};

typedef void* LinkList;
typedef void* LinkNode;

//Ϊ��C++�е��ô˺���
//c++����Ҫд�˺꣬C��������Ҫд
#ifdef __cplusplus
extern "C"{
#endif

	//��ʼ�� 
	LinkList Init_LinkList();
	//����
	void Insert_LinkList(LinkList list, int pos,void *data);
	//ɾ��
	void Remove_LinkList(LinkList list, int pos);
	//����
	void Foreach_LinkList(LinkList list, void(*myforeach)(void *));
	//����
	void Destroy_LinkList(LinkList list);
	//��ȡ�����С
	int Size_LinkList(LinkList list);
	//������ڵ���Ѱ��һ���ض���ֵ��������ָ��ýڵ�ֵ��ָ�롣
	LinkNode Get_Value(LinkList list, int(*valfound)(void *, int *), void *val);
	//�����ӡ����
	void print_LinkList(LinkList list);

	//�����ӡ���ݹ麯��
	void Lnvers(void *node, void(*myforeach)(void *));

#ifdef __cplusplus
}
#endif