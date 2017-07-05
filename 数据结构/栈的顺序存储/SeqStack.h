#pragma once
#include<stdlib.h>
#include<stdio.h>

#define MAXSIZE 1024

//����ջ�����ݽṹ
typedef struct SStack
{
	void *data[MAXSIZE];	//�������ݵ�����
	int size;	//��С
}SStack;

typedef void* SeqStack;

#ifdef __cplusplus
extern "C" {
#endif

	//ջ�ĳ�ʼ��
	SeqStack Init_SeqStack();

	//��ջ
	void Push_SeqStack(SeqStack stack, void *data);

	//��ջ
	void Pop_SeqStack(SeqStack stack);

	//��ȡջ��Ԫ��
	void *Top_SeqStack(SeqStack stack);

	//���ջ��Ԫ�ظ���
	int Size_SeqStack(SeqStack stack);

	//����ջ
	void Destroy_SeqStack(SeqStack stack);

#ifdef __cplusplus
}
#endif
