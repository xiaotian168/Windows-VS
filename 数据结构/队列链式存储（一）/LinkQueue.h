#pragma once
#include<stdlib.h>

//定义节点数据结构
typedef struct LinkNode
{
	void *data;
	struct LinkNode *next;
}LinkNode;

//定义队列数据结构
typedef struct LQueue
{
	LinkNode Header;	//头结点
	int size;
	LinkNode *rear;	//尾结点
}LQueue;

typedef void* LinkQueue;

#ifdef __cplusplus
extern "C" {
#endif 
	
	//初始化队列
	int Init_LinkQueue(void **q);

	//入队
	int Push_LinkQueue(LinkQueue queue, void *data);

	//出队
	int Pop_LinkQueue(LinkQueue queue);

	//获取队尾元素
	void* Back_LinkQueue(LinkQueue queue);

	//获取队头元素
	void* Front_LinkQueue(LinkQueue queue);

	//获取队列大小
	int Size_LinkQueue(LinkQueue queue);

	//销毁队列
	int Destroy_LinkQueue(LinkQueue queue);

#ifdef __cplusplus
}
#endif
