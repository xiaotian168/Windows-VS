#include"LinkStack.h"

//初始化栈
LinkStack Init_LinkStack()
{
	//为栈分配存储空间
	LStack *stack =(LStack *)calloc(1, sizeof(LStack));

	//初始化
	stack->header.data = NULL;
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

	LStack *s = (LStack *)stack;
	//为新节点分配空间
	StackNode *pNew = (StackNode *)calloc(1, sizeof(StackNode));
	//赋值
	pNew->data = data;
	pNew->next = s->header.next;

	//头插法，头结点作为栈顶元素；尾结点作为栈底元素
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

	StackNode *pDel = s->header.next;	//先保存要删除的节点
	s->header.next = pDel->next;	//重新建立关系
	free(pDel);		//释放节点
	pDel = NULL;
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
	if (s->size <= 0)
	{
		return NULL;
	}

	return s->header.next->data;
}

//获取栈大小（栈中元素个数）
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
	if (NULL == stack)
	{
		return;
	}

	LStack *s = (LStack *)stack;
	StackNode *pCur = s->header.next;
	StackNode *pDel = NULL;
	while (pCur != NULL)	//释放节点
	{
		pDel = pCur;
		pCur = pCur->next;
		free(pDel);
		pDel = NULL;
	}

	free(stack);	//释放栈
	stack = NULL;
}