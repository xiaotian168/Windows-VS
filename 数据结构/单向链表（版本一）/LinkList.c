#include"LinkList.h"

//链表的数据结构
struct LList
{
	struct LinkNode Header;	//头结点
	int size;	//链表大小
};

//初始化 
LinkList Init_LinkList()
{
	//为链表开辟空间
	struct LList *list = malloc(sizeof(struct LList));
	if (NULL == list)	//异常处理
		return NULL;
	list->Header.data = NULL;
	list->Header.next = NULL;
	list->size = 0;
}
//插入
void Insert_LinkList(LinkList list, int pos, void *data)
{
	if (NULL == list || NULL == data )	//异常处理
	{
		return;
	}
	struct LList *pList = (struct LList *)list;

	if (pos > pList->size || pos < 0)	//如果插入点位置大于链表大小或者小于0；则从尾部插入
	{
		pos = pList->size;
	}
	
	//为新节点分配空间
	struct LinkNode *pNew = (struct LinkNode *)calloc(1, sizeof(struct  LinkNode));
	if (NULL == pNew)
	{
		printf("没有可用内存为新节点分配空间了\n");
	}
	pNew->data = data;	//赋值
	pNew->next = NULL;

	//找到pos位置的插入点
	struct LinkNode *pCur = &(pList->Header);
	for (int i = 0; i < pos; ++i)
	{
		pCur = pCur->next;
	}

	//建立节点关系
	pNew->next = pCur->next;
	pCur->next = pNew;

	pList->size++;	//链表长度增加
}
//删除
void Remove_LinkList(LinkList list, int pos)
{
	struct LList *pList = (struct LList *)list;
	if (NULL == list || pos < 0 || pos >= pList->size || pList->size == 0)	//异常处理
	{
		return;
	}

	struct LinkNode *pCur = &(pList->Header);
	//移动节点到删除点位置的前一个节点
	for (int i = 0; i < pos; ++i)
	{
		pCur = pCur->next;
	}

	//先缓存要删除的节点
	struct LinkNode *pTmp = pCur->next;
	//从新建立关系
	pCur->next = pTmp->next;
	//释放要删除的节点
	free(pTmp);
	pTmp = NULL;
	
	pList->size--;

}
//遍历
void Foreach_LinkList(LinkList list, void(*myforeach)(void *))
{
	if (NULL == list || NULL == myforeach)	//异常处理
	{
		return;
	}

	struct LList *pList = (struct LList *)list;

	//辅助指针，指向当前节点（从首节点开始）
	struct LinkNode *pCur = pList->Header.next;
	while (pCur != NULL)
	{
		myforeach(pCur->data);
		pCur = pCur->next;
	}
}
//销毁
void Destroy_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}

	struct LList *pList = (struct LList *)list;

	//辅助指针，指向链表首节点
	struct LinkNode *pCur = pList->Header.next;
	struct LinkNode *Del = NULL;
	while (pCur != NULL)	//释放节点空间
	{
		Del = pCur->next;
		free(pCur);
		pCur = Del;
	}
	free(pList);	//释放链表空间
	pList = NULL;

}
//获取链表大小
int Size_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return 0;
	}
	struct LList *pList = (struct LList *)list;
	return pList->size;
}

//在链表节点中寻找一个特定的值，并返回指向该节点值的指针。
LinkNode Get_Value(LinkList list, int(*valfound)(void *, int *), void *val)
{
	if (NULL == list || NULL == valfound)	//异常处理
	{
		return;
	}

	struct LList *pList = (struct LList *)list;
	int *my_val = (int *)val;	

	//辅助指针，指向当前节点（从首节点开始）
	struct LinkNode *pCur = pList->Header.next;
	while (pCur != NULL)
	{
		if (0 == valfound(pCur->data, my_val))	//找到特定的值
		{
			return pCur->data;
		}
		pCur = pCur->next;
	}
	return NULL;
}

//逆序打印；递归函数与回调函数一起使用
void Lnvers(void *node, void(*myforeach)(void *))
{
	struct LinkNode *pCur = (struct LinkNode*)node;
	if (pCur->next == NULL)
	{
		myforeach(pCur->data);	//调用回调函数；打印尾部数据信息
		return;
	}
	Lnvers(pCur->next, myforeach);
	myforeach(pCur->data);	//调用回调函数，打印当前节点信息
}

//逆序打印链表
void print_LinkList(LinkList list, void(*myforeach)(void *))
{
	if (NULL == list)
		return;

	struct LList *pList = (struct LList *)list;
	if (NULL == pList->Header.next)
		return;
	//辅助指针，指向当前节点（从首节点开始）
	struct LinkNode *pCur = pList->Header.next;
	//for (int j = pList->size; j > 0; --j)
	//{
	//	for (int i = 1; i < j; ++i)
	//	{
	//		pCur = pCur->next;
	//	}
	//	//调用回调函数
	//	myforeach(pCur->data);
	//	pCur = pList->Header.next;	//pCur从新指回首节点
	//}
	
	//方法二：递归
	Lnvers(pCur, myforeach);
}
