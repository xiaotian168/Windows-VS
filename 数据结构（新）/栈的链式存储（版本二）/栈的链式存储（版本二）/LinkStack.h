#pragma once
#include<stdio.h>
#include<stdlib.h>

//����ڵ�����ݽṹ
typedef struct StackNode
{
	struct StackNode *next;
}StackNode;

//����ջ�����ݽṹ
typedef struct LStack
{
	StackNode header;
	int size;
}LStack;

//���ݱ���
typedef void* LinkStack;


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

	//ջ��С��ջ��Ԫ�ظ�����
	int Size_LinkStack(LinkStack stack);

	//����ջ
	void Destroy_LinkStack(LinkStack stack);

#ifdef __cplusplus
}
#endif // __cplusplus

