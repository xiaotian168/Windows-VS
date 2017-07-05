#pragma once
#include<stdlib.h>

#define MAXSIZE 1024

//定义队列数据结构
typedef struct SQueue
{
	void *data[MAXSIZE];	//保存数据的数组
	int size;	//大小
}SQueue;

typedef void* SeqQueue;

#ifdef __cplusplus
extern "C" {
#endif

	//初始化队列
	int Init_SQueue(SeqQueue *queue);

	//入队
	int Push_SQueue(SeqQueue queue, void *data);

	//出队
	int Pop_SQueue(SeqQueue queue);

	//获取队头元素
	void* Front_SQueue(SeqQueue queue);

	//获取队尾元素
	void* Rear_SQueue(SeqQueue queue);

	//获取队列元素个数
	int Size_SQueue(SeqQueue queue);

	//销毁队列
	int Destroy_SQueue(SeqQueue queue);

#ifdef __cplusplus
}
#endif
