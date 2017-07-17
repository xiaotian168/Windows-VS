#include"LinkList.h"

//链表的数据类型
struct LList
{
	struct LinkNode header; //头结点
	int size; //链表大小
	//struct LinkNode *rear; //指向尾部节点
};

//初始化  后缀主要为了防止命名冲突
LinkList Init_LinkList()
{
	struct LList *list = malloc(sizeof(struct LList));
	list->header.data = NULL;
	list->header.next = NULL;
	list->size = 0;

	return list;
}
//插入
void Insert_LinkList(LinkList list, int pos, void *data)
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct LList *mylist = (struct LList *)list;

	if (pos < 0 || pos > mylist->size)
	{
		pos = mylist->size;
	}

	//辅助指针变量
	struct LinkNode *pCurrent = &(mylist->header);
	//找位置
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//1. 创建新节点
	struct LinkNode *newnode = malloc(sizeof(struct LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//2. 新结点入链表
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	mylist->size++;

}
//删除
void Remove_LinkList(LinkList list, int pos)
{
	if (NULL == list)
	{
		return;
	}

	struct LList *mylist = (struct LList *)list;

	if (pos < 0 || pos > mylist->size - 1)
	{
		return;
	}

	if (mylist->size == 0)
	{
		return;
	}

	//找到删除位置的前一个位置的节点
	struct LinkNode *pCurrent = &(mylist->header);

	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//先缓存下待删除节点
	struct LinkNode *pDel = pCurrent->next;
	//重新建立待删除节点的前驱和后继节点关系
	pCurrent->next = pDel->next;
	//释放删除节点的内存
	free(pDel);
	pDel = NULL;

	mylist->size--;
}
//遍历
void Foreach_LinkList(LinkList list, void(*myforeach)(void *))
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}

	struct LList *mylist = (struct LList *)list;

	//辅助指针
	struct LinkNode *pCurrent = mylist->header.next;
	while (pCurrent != NULL)
	{
		myforeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}

}
//销毁
void Destroy_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}


	struct LList *mylist = (struct LList *)list;
	//辅助指针
	struct LinkNode *pCurrent = mylist->header.next;

	struct LinkNode *pNext = NULL;
	while (pCurrent != NULL)
	{
		//先缓存当前节点的下一个节点
		pNext = pCurrent->next;
		//放心的释放当前节点的内存
		free(pCurrent);

		pCurrent = pNext;
	}


	free(mylist);
	mylist = NULL;
}

int Size_LinkList(LinkList list)
{

	if (NULL == list)
	{
		return -1;
	}

	struct LList *mylist = (struct LList *)list;

	return mylist->size;
}

void* Search_LinkList(LinkList list, void *data, bool(*compare)(void*, void*))
{
	if (NULL == list)
	{
		return NULL;
	}

	if (NULL == data)
	{
		return NULL;
	}
	if (NULL == compare)
	{
		return NULL;
	}

	struct LList *mylist = (struct LList *)list;

	//辅助指针变量
	struct LinkNode *pCurrent = mylist->header.next;
	while (pCurrent != NULL)
	{
		if (compare(pCurrent->data, data))
		{
			break;
		}

		pCurrent = pCurrent->next;
	}

	if (pCurrent == NULL)
	{
		return NULL;
	}

	return pCurrent->data;
}

void ReverseForeach_LinkList(LinkList list, void(*myforeach)(void *))
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}

	struct LList *mylist = (struct LList *)list;

	RecursionForeach(mylist->header.next, myforeach);

}

static void RecursionForeach(struct LinkNode *node, void(*myforeach)(void *))
{
	if (NULL == node)
	{
		return;
	}

	RecursionForeach(node->next, myforeach);

	myforeach(node->data);
}