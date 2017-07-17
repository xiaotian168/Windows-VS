#pragma once
#include<stdio.h>
#include<stdlib.h>

//定义队列节点的数据结构
typedef struct QueueNode
{
	void* data;		//数据域
	struct QueueNode *next;		//指针域
}QueueNode;

//定义队列的数据结构
typedef struct LQueue
{
	QueueNode header;	//头结点
	QueueNode *rear;	//尾结点
	int size;
}LQueue;

typedef void* LinkQueue;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	//初始化队列
	LinkQueue Init_LinkQueue();

	//入队
	int Push_LinkQueue(LinkQueue queue, void* data);

	//出队
	int Pop_LinkQueue(LinkQueue queue);

	//获取队头元素
	void* Front_LinkQueue(LinkQueue queue);

	//获取队尾元素
	void* Rear_LinkQueue(LinkQueue queue);

	//获取队列大小
	int Size_LinkQueue(LinkQueue queue);

	//销毁队列
	int Destroy_LinkQueue(LinkQueue queue);

#ifdef __cplusplus
}
#endif // __cplusplus
