#include"LinkStack.h"

//��ʼ��
LinkStack *Init_LinkStack()
{
	LinkStack *stack = (LinkStack *)calloc(1, sizeof(LinkStack));	//Ϊջ����ռ�
	stack->header.next = NULL;
	stack->size = 0;

	return stack;
}

//��ջ
void Push_LinkStack(LinkStack *stack, void *data)
{
	if (NULL == stack)
	{
		return;
	}
	
	if (NULL == stack)
	{
		return;
	}
	//ͷ�巨��β�����Ϊջ��
	StackNode *Newnode = (StackNode *)data;
	//����ͷ����next
	Newnode->next = stack->header.next;
	stack->header.next = Newnode;	//ͷ���ָ���½ڵ�

	stack->size++;
}

//��ջ
void Pop_LinkStack(LinkStack *stack)
{
	if (NULL == stack)
	{
		return;
	}

	if (stack->size <= 0)
	{
		return;
	}

	stack->size--;
}

//��ȡջ��Ԫ��
void* Top_LinkStack(LinkStack *stack)
{
	if (NULL == stack)
	{
		return NULL;
	}

	if (0 == stack->size)
	{
		return NULL;
	}

	StackNode *pCur = stack->header.next;	//ָ���׽��(ջ��)
	stack->header.next = pCur->next;	//����ջ��
	return pCur;		//����ջ��
}

//���ջ��Ԫ�ظ���
int Size_LinkStack(LinkStack *stack)
{
	if (NULL == stack)
	{
		return;
	}

	return stack->size;
}

//����ջ
void Destroy_LinkStack(LinkStack *stack)
{
	if (NULL == stack)
	{
		return;
	}

	free(stack);
	stack = NULL;
}
