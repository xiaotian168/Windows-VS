#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024

//定义队列的数据结构
typedef struct SQueue
{
	void* data[MAXSIZE];	//保存数据的数组
	int size;	//大小
}SQueue;

typedef void* SeqQueue;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	//初始化队列
	SeqQueue Init_SeqQueue();

	//入队
	int Push_SeqQueue(SeqQueue queue, void* data);

	//出队
	int Pop_SeqQueue(SeqQueue queue);

	//获取队头元素
	void* Front_SeqQueue(SeqQueue queue);

	//获取队尾元素
	void* Rear_SeqQueue(SeqQueue queue);

	//获取队列大小（队列中元素个数）
	int Size_SeqQueue(SeqQueue queue);

	//销毁队列
	int Destroy_SeqQueue(SeqQueue queue);

#ifdef __cplusplus
}
#endif // __cplusplus


