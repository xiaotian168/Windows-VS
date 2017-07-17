#include"LinkStack.h"

//初始化栈
LinkStack Init_LinkStack()
{
	//为栈分配存储空间
	LStack *stack = (LStack *)calloc(1, sizeof(LStack));
	//初始化
	stack->header.next = NULL;
	stack->size = 0;

	return stack;
}

//入栈
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

	//头插法入栈；头结点为栈顶；尾结点为栈底
	LStack *s = (LStack *)stack;
	StackNode *pNew = (StackNode *)data;
	pNew->next = s->header.next;
	s->header.next = pNew;
	s->size++;
}

//出栈
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

//获取栈顶元素
void* Top_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return NULL;
	}
	
	LStack *s = (LStack *)stack;
	return s->header.next;
}

//栈大小（栈中元素个数）
int Size_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	
	LStack *s = (LStack *)stack;
	return s->size;
}

//销毁栈
void Destroy_LinkStack(LinkStack stack)
{
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
}
