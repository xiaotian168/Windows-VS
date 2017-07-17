#include"LinkStack.h"

//��ʼ��ջ
LinkStack Init_LinkStack()
{
	//Ϊջ����洢�ռ�
	LStack *stack = (LStack *)calloc(1, sizeof(LStack));
	//��ʼ��
	stack->header.next = NULL;
	stack->size = 0;

	return stack;
}

//��ջ
void Push_LinkStack(LinkStack stack, void* data)
{
	if (NULL == stack)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	//ͷ�巨��ջ��ͷ���Ϊջ����β���Ϊջ��
	LStack *s = (LStack *)stack;
	StackNode *pNew = (StackNode *)data;
	pNew->next = s->header.next;
	s->header.next = pNew;
	s->size++;
}

//��ջ
void Pop_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	LStack *s = (LStack *)stack;
	if (s->size <= 0)
	{
		return;
	}

	s->header.next = s->header.next->next;
	s->size--;
}

//��ȡջ��Ԫ��
void* Top_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return NULL;
	}
	
	LStack *s = (LStack *)stack;
	return s->header.next;
}

//ջ��С��ջ��Ԫ�ظ�����
int Size_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	
	LStack *s = (LStack *)stack;
	return s->size;
}

//����ջ
void Destroy_LinkStack(LinkStack stack)
{
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
}
