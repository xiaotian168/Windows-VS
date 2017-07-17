#include <stdio.h>
#include <stdlib.h>
#include "list.h"


//创建并返回一个空的线性表；并且指定线性表总长度,节点个数（容量）
List* List_Create(int Cay)
{
	if (Cay <= 0)	//异常处理
	{
		fprintf(stdout, "创建链表的容量必须大于0\n");
		return NULL;
	}
	Sql_list *pList = (Sql_list *)calloc(1, sizeof(Sql_list));	//为线性表分配存储空间
	if (pList == NULL)
	{
		fprintf(stdout, "链表空间分配失败，calloc failed\n");
		return NULL;
	}
	pList->node = (unsigned int *)calloc(Cay, sizeof(unsigned int));
	if(pList->node == NULL)
	{
		fprintf(stdout, "链表节点空间分配失败，calloc failed\n");
		free(pList);
		pList = NULL;
	}
	pList->Cay = Cay;
	pList->len = 0;
	return pList;	//返回空链表首地址
}

//销毁一个线性表
void List_Destroy(List* list)
{
	Sql_list *tmp = (Sql_list *)list;
	if (tmp)
	{
		if (tmp->node)
		{
			free(tmp->node);	//释放节点空间
			tmp->node = NULL;
		}
		free(tmp);	//释放堆中分配的链表空间
	}
}

//将一个线性表list中的所有元素清空，线性表回到创建时的初始状态
int List_Clear(List* list)
{
	Sql_list *tmp = (Sql_list *)list;
	if (tmp == NULL )	//异常处理
		return -1;
	tmp->len = 0;
	return 1;
}

//返回一个线性表list中的所有元素个数
int List_Length(List* list)
{
	Sql_list *tmp = (Sql_list *)list;
	if (tmp == NULL)	//异常处理
		return -1;
	return tmp->len;
}

//向一个线性表list的pos位置处插入新元素node
int List_Insert(List* list, ListNode* node, int pos)
{
	Sql_list *tmp = (Sql_list *)list;
	unsigned int t_node = *(unsigned int*)node;
	if (tmp == NULL || node == NULL || pos < 0)
	{
		fprintf(stdout, "没有创建线性表\n");
		return -1;
	}
	if (tmp->len < tmp->Cay)	//判断线性表没满；则可以插入指定位置元素
	{
		if (pos >= tmp->len)	//插入位置在实际位置后面，均作为从尾部插入
			pos = tmp->len;
		for (int i = tmp->len; i > pos; --i)
		{
			tmp->node[i] = tmp->node[i - 1];
		}
		tmp->node[pos] = t_node;	//在pos位置插入元素
		tmp->len++;
		return 0;
	}
	else
	{
		fprintf(stdout, "线性表容量已满；无法插入节点\n");
		return -2;
	}
}

//获取一个线性表list的pos位置处的元素的地址
ListNode *List_Get(List *list, int pos)
{
	if (list == NULL || pos < 0)
	{
		fprintf(stdout, "list == NULL || pos < 0");
		return NULL;
	}
	Sql_list *tmp = (Sql_list *)list;
	if (pos < tmp->len)
		return &tmp->node[pos];
	else
	{
		fprintf(stdout, "%d号位置没有值\n", pos);
		return NULL;
	}
}

//获取一个线性表list的pos位置处的元素 返回值为被删除的元素，NULL表示删除失败
ListNode* List_Delete(List* list, int pos)
{
	if (list == NULL || pos < 0)
	{
		fprintf(stdout, "list == NULL || pos < 0");
		return NULL;
	}
	Sql_list *tmp = (Sql_list *)list;
	if (pos < tmp->len)
	{
		unsigned int *tnode = &tmp->node[pos];	//保存被删除元素地址
		printf("\n第%d个位置的元素删除成功\n", pos);
		for (int i = pos; i < tmp->len - 1; ++i)
		{
			tmp->node[i] = tmp->node[i + 1];
		}
		tmp->len--;
		return &tmp->node[pos];
	}
	else
	{
		fprintf(stdout, "%d号位置没有值\n", pos);
		return NULL;
	}
}