#pragma once

#include<stdlib.h>


//链表是由一系列节点组成
//定义链表节点的数据类型
struct LinkNode
{
	void *data;
	struct LinkNode *next;
};

typedef void* LinkList;
typedef void* LinkNode;

//为了C++中调用此函数
//c++不需要写此宏，C语言中需要写
#ifdef __cplusplus
extern "C"{
#endif

	//初始化 
	LinkList Init_LinkList();
	//插入
	void Insert_LinkList(LinkList list, int pos,void *data);
	//删除
	void Remove_LinkList(LinkList list, int pos);
	//遍历
	void Foreach_LinkList(LinkList list, void(*myforeach)(void *));
	//销毁
	void Destroy_LinkList(LinkList list);
	//获取链表大小
	int Size_LinkList(LinkList list);
	//在链表节点中寻找一个特定的值，并返回指向该节点值的指针。
	LinkNode Get_Value(LinkList list, int(*valfound)(void *, int *), void *val);
	//逆序打印链表
	void print_LinkList(LinkList list);

	//逆序打印；递归函数
	void Lnvers(void *node, void(*myforeach)(void *));

#ifdef __cplusplus
}
#endif