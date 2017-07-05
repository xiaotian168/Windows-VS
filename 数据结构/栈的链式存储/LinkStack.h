#pragma once
#include<stdlib.h>

//定义节点类型
typedef struct StackNode
{
	struct StackNode *next;
}StackNode;

//定义栈的数据结构
typedef struct LinkStack
{
	StackNode header;
	int size;
}LinkStack;


#ifdef __cplusplus
extern "C" {
#endif

	/*
	栈初始化
	@return 返回栈指针
	*/
	//初始化
	LinkStack *Init_LinkStack();

	//入栈
	void Push_LinkStack(LinkStack *stack, void *data);

	//出栈
	void Pop_LinkStack(LinkStack *stack);

	//获取栈顶元素
	void* Top_LinkStack(LinkStack *stack);

	//获得栈中元素个数
	int Size_LinkStack(LinkStack *stack);

	//销毁栈
	void Destroy_LinkStack(LinkStack *stack);

#ifdef __cplusplus
}
#endif