#include"LinkList.h"

//初始化链表
LinkList *Init_LinkList()
{
	LinkList *list = (LinkList *)calloc(1, sizeof(sizeof(LinkList)));	//为链表分配空间
	list->header.next = NULL;
	list->size = 0;

	return list;
}

//插入函数
void Insert_LinkList(LinkList *list, int pos, void *data)
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	if (pos < 0 || pos > list->size)	//插入位置纠正
	{
		pos = list->size;
	}

	LinkNode *pCur = &(list->header);		//定义当前节点
	for (int i = 0; i < pos; ++i)	//移动当前节点到插入点位置
	{
		pCur = pCur->next;
	}
	LinkNode *pNew = (LinkNode *)data;	//接收新节点地址
	pNew->next = pCur->next;	//保存当前节点的next
	pCur->next = pNew;	//当前节点指向新节点

	list->size++;
}

//遍历函数
void Foreach_LinkList(LinkList *list, void(*myforeach)(void *))
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}

	LinkNode *pCur = list->header.next;	//辅助指针；指向当前节点
	while (pCur != NULL) 
	{
		myforeach(pCur);
		pCur = pCur->next;
	}
}

//链表逆序（翻转A->B->C-D变为：D->C->B-A）
void Inverted_LinkList(LinkList *list)
{
	if (NULL == list)
	{
		return;
	}

	if (list->size <= 1)
	{
		return;
	}

	LinkNode *pPre = list->header.next;	//辅助指针；指向首节点
	LinkNode *pCur = pPre->next; // 辅助指针；指向下一个节点
	LinkNode *tmp = NULL;
	while (pCur != NULL)
	{
		tmp = pCur->next;	//保存当前节点的指向
		pCur->next = pPre;	//当前节点指向前一个节点
		pPre = pCur;	//pPre移动到pCur
		pCur = tmp;		//pCur移动到pCur.next
	}

	//先保存尾结点
	list->header.next->next = NULL;
	//更新头结点
	list->header.next = pPre;
}

//链表排序
void Sort_LinkList(LinkList *list, int(*myCompare)(void *, void *))
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == myCompare)
	{
		return;
	}

	if (list->size < 2)
	{
		return;
	}

	//插入排序
	LinkNode *pPre = list->header.next;		//上一个节点
	LinkNode *pCur = pPre->next;	//当前节点
	LinkNode *tmp = NULL;
	
	while(pCur != NULL)	//(升序)
	{
		tmp = &(list->header);
		int pos = 0;	//记录插入点的位置
		if (myCompare(pPre, pCur) > 0)	//说明需要插入
		{
			while (myCompare(tmp->next, pCur) < 0 )		//查找插入点位置
			{
				pos++;
				tmp = tmp->next;
			}
			pPre->next = pCur->next;	//先缓冲当前节点的next,并且断掉当前节点连接			
			Insert_LinkList(list, pos, pCur);	//插入节点（将当前节点插入到找到的插入位置）		
			pCur = pPre->next;	//当前节点移动到next
			list->size--;

			//LinkNode *p1 = pCur->next;	//先缓冲当前节点的next
			//Insert_LinkList(list, pos, pCur);	//插入节点
			//pPre->next = p1;	//上一个节点的next指向当前节点的next
			//pCur = p1;	//当前节点移动到next
		}
		else
		{
			pPre = pPre->next;
			pCur = pCur->next;
		}
	}
}

//删除函数
void Remove_LinkList(LinkList *list, int pos)
{
	if (NULL == list)
	{
		return;
	}

	if (pos < 0 || pos >= list->size)
	{
		return;
	}

	LinkNode *pCur = &(list->header);
	for (int i = 0; i < pos; ++i)	//移动当前节点到删除节点的前一个位置
	{
		pCur = pCur->next;
	}

	//从新建立节点关系
	pCur->next = pCur->next->next;

	list->size--;
}

//销毁链表
void Destroy_LinkList(LinkList *list)
{
	if (NULL == list)
	{
		return;
	}

	list->size = 0;
	free(list);
	list = NULL;
}