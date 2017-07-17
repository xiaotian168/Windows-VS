#pragma once

#include<stdlib.h>
#include<stdbool.h>


//链表是由一系列节点组成
//定义链表节点的数据类型
struct LinkNode
{
	void *data;
	struct LinkNode *next;
};

typedef void* LinkList;


//为了C++中调用此函数
//c++不需要写此宏，C语言中需要写
#ifdef __cplusplus
extern "C"{
#endif

	//初始化  后缀主要为了防止命名冲突
	LinkList Init_LinkList();
	//插入
	void Insert_LinkList(LinkList list, int pos,void *data);
	//删除
	void Remove_LinkList(LinkList list, int pos);
	//遍历
	void Foreach_LinkList(LinkList list, void(*myforeach)(void *));
	//销毁
	void Destroy_LinkList(LinkList list);

	int Size_LinkList(LinkList list);

	//查找 bool类型 true false
	void* Search_LinkList(LinkList list, void *data, bool(*compare)(void*,void*) );
	//逆序打印
	void ReverseForeach_LinkList(LinkList list, void(*myforeach)(void *));

	static void RecursionForeach(struct LinkNode *node, void(*myforeach)(void *));

#ifdef __cplusplus
}
#endif