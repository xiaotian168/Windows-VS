#pragma once
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1024

//定义栈的数据结构
typedef struct SStack
{
	void *data[MAXSIZE];	//保存数据的数组
	int size;	//大小
}SStack;

typedef void* SeqStack;		//数据保护，不让外部直接访问栈数据结构里面的元素

//分离式编译；告诉编译器如果是c++编译；怎下面代码采用c的方式编译
#ifdef __cplusplus
extern "C" {
#endif

	//栈的初始化
	SeqStack Init_SeqStack();

	//入栈(压栈)
	void Push_SeqStack(SeqStack stack, void* data);

	//出栈（弹栈）
	void Pop_SeqStack(SeqStack stack);

	//获取栈顶元素
	void* Top_SeqStack(SeqStack stack);

	//获取栈的大小（栈中元素个数）
	int Size_SeqStack(SeqStack stack);

	//销毁栈
	void Destroy_SeqStack(SeqStack stack);

#ifdef __cplusplus
}
#endif // __cplusplus
