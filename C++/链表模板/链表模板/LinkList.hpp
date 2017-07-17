#pragma once
#include<iostream>

//定义链表节点类型
template<class T>
struct LinkNode
{
	T data;
	LinkNode *next;
};

//定义链表类型
template<class T>
class LinkList
{
public:
	//初始化链表
	LinkList()
	{
		header.next = NULL;
		mSize = 0;
	}

	//按指定位置插入数据
	void Insert(int pos, T data)
	{
		if (pos < 0 || pos > this->mSize)	//插入位置不合法；直接退出
		{
			return;
		}

		LinkNode<T> *pNew = new LinkNode<T>;	//增加新节点数据信息
		pNew->data = data;
		pNew->next = NULL;
		LinkNode<T> *pCur = &(this->header);
		for (int i = 0; i < pos; i++)	//移动节点到插入的前一个位置
		{
			pCur = pCur->next;
		}
		pNew->next = pCur->next;

		pCur->next = pNew;	//插入新节点
		this->mSize++;
	}

	//头部位置插入数据
	void PushFront(T data)
	{
		Insert(0, T data);
	}

	//尾部位置插入数据
	void PushBack(T data)
	{
		Insert(this->Size, T data);
	}

	//按指定位置删除数据
	void RemoveByPos(int pos)
	{
		if (pos < 0 || pos >= this->mSize)
		{
			return;
		}

		LinkNode<T> *pCur = &(this->header);
		for (int i = 0; i < pos; ++i)
		{
			pCur = pCur->next;
		}
		LinkNode<T> *pDel = pCur->next;	//先缓存要删除的节点
		pCur->next = pDel->next;	//重新建立节点关系
		delete pDel;	//释放要删除的节点
		this->mSize--;
	}

	//头部位置删除数据
	void PopFront()
	{
		RemoveByPos(0);
	}

	//尾部位置删除数据
	void PopBack()
	{
		RemoveByPos(this->Size);
	}

	//按指定值删除数据
	template<class T, class _CallBack>
	void RemoveByVal(T val, _CallBack compare)
	{
		if (this->mSize == 0)
		{
			return;
		}

		LinkNode<T> *pCur = &(this->header);	//要删除节点的前一个节点
		LinkNode<T> *pDel = NULL;
		while (pCur->next != NULL)
		{
			if (compare(pCur->next->data, val))	//找到匹配的值
			{
				pDel = pCur->next;	//保存要删除的节点
				pCur->next = pDel->next;
				delete pDel;
				pDel = NULL;
				this->mSize--;
				continue;
			}

			pCur = pCur->next;
		}
	}

	//遍历链表
	template<class _CallBack>
	void Foreach(_CallBack fun)	//类模板做函数参数(1.外部可以传函数指针类型  2.也可以传函数对象（本质也是一个对象）)
	{
		LinkNode<T> *pCur = this->header.next;
		for (int i = 0; i < this->mSize; ++i)
		{
			fun(pCur->data);
			pCur = pCur->next;
		}
	}

	//链表排序
	void Sort()
	{

	}

	//获取链表大小
	int Size()
	{
		return this->mSize;
	}

	//销毁链表
	~LinkList()
	{
		LinkNode<T> *pCur = this->header.next;
		LinkNode<T> *pDel = NULL;
		while (pCur != NULL)
		{
			pDel = pCur;	//先保存要释放的节点
			pCur = pCur->next;
			delete pDel;
		}
	}

private:
	LinkNode<T> header;	//头结点
	int mSize;
};