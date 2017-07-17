#pragma once
#include<stdio.h>
#include<stdlib.h>

//定义节点数据类型
typedef struct LinkNode
{
	struct LinkNode *next;
}LinkNode;

//定义链表数据类型
typedef struct LinkList
{
	LinkNode header;
	int size;
}LinkList;

#ifdef __cplusplus
extern "C" {
#endif 

	//初始化
	/*
	链表初始化
	@return 返回链表指针
	*/
	LinkList *Init_LinkList();

	//插入
	/*
	向链表在指定位置插入数据
	@param list 链表指针
	@param pos 插入位置
	@param data 插入数据
	*/
	void Insert_LinkList(LinkList *list, int pos, void *data);


	//遍历
	/*
	遍历链表
	@param list 链表指针
	@param myforeach 遍历回调函数
	*/
	void Foreach_LinkList(LinkList *list, void (*myforeach)(void *));

	//链表逆序（翻转）
	void Inverted_LinkList(LinkList *list);

	//链表排序
	void Sort_LinkList(LinkList *list, int (*mycompare)(void *, void *));

	//删除
	/*
	删除指定位置的节点
	@param list 链表指针
	@param pos 删除位置
	*/
	void Remove_LinkList(LinkList *list, int pos);

	//销毁链表
	/*
	销毁链表
	@param list 链表指针
	*/
	void Destroy_LinkList(LinkList *list);

#ifdef __cplusplus
}
#endif
