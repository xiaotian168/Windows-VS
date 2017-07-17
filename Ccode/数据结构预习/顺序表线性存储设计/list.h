#pragma once	//防止头文件重复包含

typedef void List;
typedef void ListNode;

typedef struct Sql_list	//线性表结构
{
	int len;	//长度
	int Cay;	//容量
	unsigned int *node;	//线性表节点
}Sql_list;

//创建并返回一个空的线性表
List* List_Create(int Cay);

//销毁一个线性表
void List_Destroy(List* list);

//将一个线性表list中的所有元素清空，线性表回到创建时的初始状态
int List_Clear(List* list);

//返回一个线性表list中的所有元素个数
int List_Length(List* list);

//向一个线性表list的pos位置处插入新元素node
int List_Insert(List* list, ListNode* node, int pos);

ListNode *List_Get(List *list, int pos);

//获取一个线性表list的pos位置处的元素 返回值为被删除的元素，NULL表示删除失败
ListNode* List_Delete(List* list, int pos);