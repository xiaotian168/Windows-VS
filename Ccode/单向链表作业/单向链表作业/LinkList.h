#pragma once

#include<stdlib.h>
#include<stdbool.h>


//��������һϵ�нڵ����
//��������ڵ����������
struct LinkNode
{
	void *data;
	struct LinkNode *next;
};

typedef void* LinkList;


//Ϊ��C++�е��ô˺���
//c++����Ҫд�˺꣬C��������Ҫд
#ifdef __cplusplus
extern "C"{
#endif

	//��ʼ��  ��׺��ҪΪ�˷�ֹ������ͻ
	LinkList Init_LinkList();
	//����
	void Insert_LinkList(LinkList list, int pos,void *data);
	//ɾ��
	void Remove_LinkList(LinkList list, int pos);
	//����
	void Foreach_LinkList(LinkList list, void(*myforeach)(void *));
	//����
	void Destroy_LinkList(LinkList list);

	int Size_LinkList(LinkList list);

	//���� bool���� true false
	void* Search_LinkList(LinkList list, void *data, bool(*compare)(void*,void*) );
	//�����ӡ
	void ReverseForeach_LinkList(LinkList list, void(*myforeach)(void *));

	static void RecursionForeach(struct LinkNode *node, void(*myforeach)(void *));

#ifdef __cplusplus
}
#endif