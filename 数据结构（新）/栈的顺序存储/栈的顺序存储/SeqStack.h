#pragma once
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1024

//����ջ�����ݽṹ
typedef struct SStack
{
	void *data[MAXSIZE];	//�������ݵ�����
	int size;	//��С
}SStack;

typedef void* SeqStack;		//���ݱ����������ⲿֱ�ӷ���ջ���ݽṹ�����Ԫ��

//����ʽ���룻���߱����������c++���룻������������c�ķ�ʽ����
#ifdef __cplusplus
extern "C" {
#endif

	//ջ�ĳ�ʼ��
	SeqStack Init_SeqStack();

	//��ջ(ѹջ)
	void Push_SeqStack(SeqStack stack, void* data);

	//��ջ����ջ��
	void Pop_SeqStack(SeqStack stack);

	//��ȡջ��Ԫ��
	void* Top_SeqStack(SeqStack stack);

	//��ȡջ�Ĵ�С��ջ��Ԫ�ظ�����
	int Size_SeqStack(SeqStack stack);

	//����ջ
	void Destroy_SeqStack(SeqStack stack);

#ifdef __cplusplus
}
#endif // __cplusplus
