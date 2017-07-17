#pragma once
#include<stdio.h>
#include<stdlib.h>

//定义节点的数据结构
typedef struct StackNode
{
	struct StackNode *next;
}StackNode;

//定义栈的数据结构
typedef struct LStack
{
	StackNode header;
	int size;
}LStack;

//数据保护
typedef void* LinkStack;


#ifdef __cplusplus
extern "C" {
#endif

	//初始化栈
	LinkStack Init_LinkStack();

	//入栈
	void Push_LinkStack(LinkStack stack, void* data);

	//出栈
	void Pop_LinkStack(LinkStack stack);

	//获取栈顶元素
	void* Top_LinkStack(LinkStack stack);

	//栈大小（栈中元素个数）
	int Size_LinkStack(LinkStack stack);

	//销毁栈
	void Destroy_LinkStack(LinkStack stack);

#ifdef __cplusplus
}
#endif // __cplusplus

