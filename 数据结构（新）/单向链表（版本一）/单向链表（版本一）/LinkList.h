#pragma once
#include<stdio.h>
#include<stdlib.h>


//链表是由一系列节点组成
//定义链表节点的数据类型
struct LinkNode
{
	void *data;
	struct LinkNode *next;
};

//定义链表的数据结构
struct LList
{
	struct LinkNode Header;	//头结点
	int size;	//链表大小
};

typedef void* LinkList;
typedef void* LinkNode;

//为了C++中调用此函数
//c++不需要写此宏，C语言中需要写
#ifdef __cplusplus
extern "C"{
#endif

	//初始化链表
	LinkList Init_LinkList();

	//指定位置插入数据
	void Insert_LinkList(LinkList list, int pos,void* data);

	//头部插入数据
	void PushFront_LinkList(LinkList list, void* data);

	//尾部插入数据
	void PushBack_LinkList(LinkList list, void* data);

	//指定位置删除数据删除
	void Remove_LinkList(LinkList list, int pos);

	//头部删除数据
	void PopFront_LinkList(LinkList list);

	//尾部删除数据
	void PopBack_LinkList(LinkList list);

	//按值删除数据
	void RemoveByVal_LinkList(LinkList list, void* data, int (*myCompare)(void* d1, void* d2));

	//遍历
	void Foreach_LinkList(LinkList list, void(*myForeach)(void *));

	//获取链表大小
	int Size_LinkList(LinkList list);
	
	//在链表节点中寻找一个特定的值，并返回指向该节点值的指针。
	LinkNode Get_Value(LinkList list, int(*valfound)(void *, int *), void *val);
	
	//逆序打印链表
	void print_LinkList(LinkList list, void(*myForeach)(void *));

	//逆序打印；递归函数
	void Lnvers(void *node, void(*myForeach)(void *));

	//销毁链表
	void Destroy_LinkList(LinkList list);

#ifdef __cplusplus
}
#endif