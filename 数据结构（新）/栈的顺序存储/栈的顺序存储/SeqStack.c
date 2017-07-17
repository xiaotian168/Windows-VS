#include"SeqStack.h"

//栈的初始化
SeqStack Init_SeqStack()
{
	SStack *stack = (SStack *)calloc(1, sizeof(SStack));	//为栈分配存储空间
	if (NULL == stack)
	{
		return	NULL;
	}

	//初始化
	for (int i = 0; i < MAXSIZE; ++i)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;

	return stack;
}

//入栈(压栈)
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

//出栈（弹栈）
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

//获取栈顶元素
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

//获取栈的大小（栈中元素个数）
int Size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}

	SStack *s = (SStack *)stack;
	return s->size;
}

//销毁栈
void Destroy_SeqStack(SeqStack stack)
{
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}

}