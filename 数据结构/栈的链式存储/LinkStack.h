#pragma once
#include<stdlib.h>

//����ڵ�����
typedef struct StackNode
{
	struct StackNode *next;
}StackNode;

//����ջ�����ݽṹ
typedef struct LinkStack
{
	StackNode header;
	int size;
}LinkStack;


#ifdef __cplusplus
extern "C" {
#endif

	/*
	ջ��ʼ��
	@return ����ջָ��
	*/
	//��ʼ��
	LinkStack *Init_LinkStack();

	//��ջ
	void Push_LinkStack(LinkStack *stack, void *data);

	//��ջ
	void Pop_LinkStack(LinkStack *stack);

	//��ȡջ��Ԫ��
	void* Top_LinkStack(LinkStack *stack);

	//���ջ��Ԫ�ظ���
	int Size_LinkStack(LinkStack *stack);

	//����ջ
	void Destroy_LinkStack(LinkStack *stack);

#ifdef __cplusplus
}
#endif