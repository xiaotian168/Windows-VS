#include"SeqStack.h"

//ջ�ĳ�ʼ��
SeqStack Init_SeqStack()
{
	SStack *stack = (SStack *)calloc(1, sizeof(SStack));	//Ϊջ����ռ�
	//��ʼ���������ݵ�����
	for (int i = 0; i < MAXSIZE; ++i)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;

	return stack;
}

//��ջ
void Push_SeqStack(SeqStack stack, void *data)
{
	if (NULL == stack)
	{
		return;
	}

	if (NULL == stack)
	{
		return;
	}

	SStack *s = (SStack *)stack;	//����ջ�ĵ�ַ
	if (s->size >= MAXSIZE)
	{
		return;
	}

	s->data[s->size++] = data;
}

//��ջ
void Pop_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	SStack *s = (SStack *)stack;	//����ջ�ĵ�ַ
	if (0 == s->size)
	{
		return;
	}

	s->size--;
}

//��ȡջ��Ԫ��
void *Top_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return NULL;
	}

	SStack *s = (SStack *)stack;	//����ջ�ĵ�ַ
	if (0 == s->size)
	{
		printf("ջ��û��Ԫ��\n");
		return NULL;
	}

	return s->data[s->size - 1];
}

//���ջ��Ԫ�ظ���
int Size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}

	SStack *s = (SStack *)stack;	//����ջ�ĵ�ַ
	return s->size;
}

//����ջ
void Destroy_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	free(stack);
	stack = NULL;
}