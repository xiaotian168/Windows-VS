#include"SeqStack.h"

//栈的初始化
SeqStack Init_SeqStack()
{
	SStack *stack = (SStack *)calloc(1, sizeof(SStack));	//为栈分配空间
	//初始化保存数据的数组
	for (int i = 0; i < MAXSIZE; ++i)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;

	return stack;
}

//入栈
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

	SStack *s = (SStack *)stack;	//接收栈的地址
	if (s->size >= MAXSIZE)
	{
		return;
	}

	s->data[s->size++] = data;
}

//出栈
void Pop_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	SStack *s = (SStack *)stack;	//接收栈的地址
	if (0 == s->size)
	{
		return;
	}

	s->size--;
}

//获取栈顶元素
void *Top_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return NULL;
	}

	SStack *s = (SStack *)stack;	//接收栈的地址
	if (0 == s->size)
	{
		printf("栈中没有元素\n");
		return NULL;
	}

	return s->data[s->size - 1];
}

//获得栈中元素个数
int Size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}

	SStack *s = (SStack *)stack;	//接收栈的地址
	return s->size;
}

//销毁栈
void Destroy_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	free(stack);
	stack = NULL;
}