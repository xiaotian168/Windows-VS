#include"LinkStack.h"

//初始化
LinkStack *Init_LinkStack()
{
	LinkStack *stack = (LinkStack *)calloc(1, sizeof(LinkStack));	//为栈分配空间
	stack->header.next = NULL;
	stack->size = 0;

	return stack;
}

//入栈
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
	//头插法；尾结点作为栈底
	StackNode *Newnode = (StackNode *)data;
	//保存头结点的next
	Newnode->next = stack->header.next;
	stack->header.next = Newnode;	//头结点指向新节点

	stack->size++;
}

//出栈
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

//获取栈顶元素
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

	StackNode *pCur = stack->header.next;	//指向首结点(栈顶)
	stack->header.next = pCur->next;	//更新栈顶
	return pCur;		//返回栈顶
}

//获得栈中元素个数
int Size_LinkStack(LinkStack *stack)
{
	if (NULL == stack)
	{
		return;
	}

	return stack->size;
}

//销毁栈
void Destroy_LinkStack(LinkStack *stack)
{
	if (NULL == stack)
	{
		return;
	}

	free(stack);
	stack = NULL;
}
