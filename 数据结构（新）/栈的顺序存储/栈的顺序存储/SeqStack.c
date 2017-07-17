#include"SeqStack.h"

//ջ�ĳ�ʼ��
SeqStack Init_SeqStack()
{
	SStack *stack = (SStack *)calloc(1, sizeof(SStack));	//Ϊջ����洢�ռ�
	if (NULL == stack)
	{
		return	NULL;
	}

	//��ʼ��
	for (int i = 0; i < MAXSIZE; ++i)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;

	return stack;
}

//��ջ(ѹջ)
void Push_SeqStack(SeqStack stack, void* data)
{
	if (NULL == stack)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	SStack *s = (SStack *)stack;
	if (s->size >= MAXSIZE)
	{
		return;
	}

	s->data[s->size++] = data;
}

//��ջ����ջ��
void Pop_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	SStack *s = (SStack *)stack;
	if (s->size <= 0)
	{
		return;
	}

	s->size--;
}

//��ȡջ��Ԫ��
void* Top_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return NULL;
	}
	
	SStack *s = (SStack *)stack;
	if (s->size <= 0)
	{
		return NULL;
	}

	return s->data[s->size - 1];
}

//��ȡջ�Ĵ�С��ջ��Ԫ�ظ�����
int Size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}

	SStack *s = (SStack *)stack;
	return s->size;
}

//����ջ
void Destroy_SeqStack(SeqStack stack)
{
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}

}