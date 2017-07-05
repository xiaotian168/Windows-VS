#pragma once
#include<stdlib.h>
#include<stdio.h>

#define MAXSIZE 1024

//定义栈的数据结构
typedef struct SStack
{
	void *data[MAXSIZE];	//保存数据的数组
	int size;	//大小
}SStack;

typedef void* SeqStack;

#ifdef __cplusplus
extern "C" {
#endif

	//栈的初始化
	SeqStack Init_SeqStack();

	//入栈
	void Push_SeqStack(SeqStack stack, void *data);

	//出栈
	void Pop_SeqStack(SeqStack stack);

	//获取栈顶元素
	void *Top_SeqStack(SeqStack stack);

	//获得栈中元素个数
	int Size_SeqStack(SeqStack stack);

	//销毁栈
	void Destroy_SeqStack(SeqStack stack);

#ifdef __cplusplus
}
#endif
