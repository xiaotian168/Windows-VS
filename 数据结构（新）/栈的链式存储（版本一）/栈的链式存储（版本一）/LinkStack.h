#pragma once
#include<stdio.h>
#include<stdlib.h>

//����ڵ�����ݽṹ
typedef struct StackNode
{
	void* data;
	struct StackNode *next;
}StackNode;

//����ջ�����ݽṹ
typedef struct LStack
{
	StackNode header;	//ͷ���
	int size;	//��С
}LStack;

typedef void* LinkStack;	//����ջ�е�Ԫ�أ���ֹ�ⲿֱ�ӷ����޸�

#ifdef __cplusplus
extern "C" {
#endif

	//��ʼ��ջ
	LinkStack Init_LinkStack();

	//��ջ
	void Push_LinkStack(LinkStack stack, void* data);

	//��ջ
	void Pop_LinkStack(LinkStack stack);

	//��ȡջ��Ԫ��
	void* Top_LinkStack(LinkStack stack);

	//��ȡջ��С��ջ��Ԫ�ظ�����
	int Size_LinkStack(LinkStack stack);

	//����ջ
	void Destroy_LinkStack(LinkStack stack);

#ifdef __cplusplus
}
#endif // __cplusplus
