#include"LinkStack.h"

//��ʼ��ջ
LinkStack Init_LinkStack()
{
	//Ϊջ����洢�ռ�
	LStack *stack =(LStack *)calloc(1, sizeof(LStack));

	//��ʼ��
	stack->header.data = NULL;
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

	LStack *s = (LStack *)stack;
	//Ϊ�½ڵ����ռ�
	StackNode *pNew = (StackNode *)calloc(1, sizeof(StackNode));
	//��ֵ
	pNew->data = data;
	pNew->next = s->header.next;

	//ͷ�巨��ͷ�����Ϊջ��Ԫ�أ�β�����Ϊջ��Ԫ��
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

	StackNode *pDel = s->header.next;	//�ȱ���Ҫɾ���Ľڵ�
	s->header.next = pDel->next;	//���½�����ϵ
	free(pDel);		//�ͷŽڵ�
	pDel = NULL;
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
	if (s->size <= 0)
	{
		return NULL;
	}

	return s->header.next->data;
}

//��ȡջ��С��ջ��Ԫ�ظ�����
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
	if (NULL == stack)
	{
		return;
	}

	LStack *s = (LStack *)stack;
	StackNode *pCur = s->header.next;
	StackNode *pDel = NULL;
	while (pCur != NULL)	//�ͷŽڵ�
	{
		pDel = pCur;
		pCur = pCur->next;
		free(pDel);
		pDel = NULL;
	}

	free(stack);	//�ͷ�ջ
	stack = NULL;
}