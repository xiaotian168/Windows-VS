#pragma once
#include<iostream>

//��������ڵ�����
template<class T>
struct LinkNode
{
	T data;
	LinkNode *next;
};

//������������
template<class T>
class LinkList
{
public:
	//��ʼ������
	LinkList()
	{
		header.next = NULL;
		mSize = 0;
	}

	//��ָ��λ�ò�������
	void Insert(int pos, T data)
	{
		if (pos < 0 || pos > this->mSize)	//����λ�ò��Ϸ���ֱ���˳�
		{
			return;
		}

		LinkNode<T> *pNew = new LinkNode<T>;	//�����½ڵ�������Ϣ
		pNew->data = data;
		pNew->next = NULL;
		LinkNode<T> *pCur = &(this->header);
		for (int i = 0; i < pos; i++)	//�ƶ��ڵ㵽�����ǰһ��λ��
		{
			pCur = pCur->next;
		}
		pNew->next = pCur->next;

		pCur->next = pNew;	//�����½ڵ�
		this->mSize++;
	}

	//ͷ��λ�ò�������
	void PushFront(T data)
	{
		Insert(0, T data);
	}

	//β��λ�ò�������
	void PushBack(T data)
	{
		Insert(this->Size, T data);
	}

	//��ָ��λ��ɾ������
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
		LinkNode<T> *pDel = pCur->next;	//�Ȼ���Ҫɾ���Ľڵ�
		pCur->next = pDel->next;	//���½����ڵ��ϵ
		delete pDel;	//�ͷ�Ҫɾ���Ľڵ�
		this->mSize--;
	}

	//ͷ��λ��ɾ������
	void PopFront()
	{
		RemoveByPos(0);
	}

	//β��λ��ɾ������
	void PopBack()
	{
		RemoveByPos(this->Size);
	}

	//��ָ��ֵɾ������
	template<class T, class _CallBack>
	void RemoveByVal(T val, _CallBack compare)
	{
		if (this->mSize == 0)
		{
			return;
		}

		LinkNode<T> *pCur = &(this->header);	//Ҫɾ���ڵ��ǰһ���ڵ�
		LinkNode<T> *pDel = NULL;
		while (pCur->next != NULL)
		{
			if (compare(pCur->next->data, val))	//�ҵ�ƥ���ֵ
			{
				pDel = pCur->next;	//����Ҫɾ���Ľڵ�
				pCur->next = pDel->next;
				delete pDel;
				pDel = NULL;
				this->mSize--;
				continue;
			}

			pCur = pCur->next;
		}
	}

	//��������
	template<class _CallBack>
	void Foreach(_CallBack fun)	//��ģ������������(1.�ⲿ���Դ�����ָ������  2.Ҳ���Դ��������󣨱���Ҳ��һ������)
	{
		LinkNode<T> *pCur = this->header.next;
		for (int i = 0; i < this->mSize; ++i)
		{
			fun(pCur->data);
			pCur = pCur->next;
		}
	}

	//��������
	void Sort()
	{

	}

	//��ȡ�����С
	int Size()
	{
		return this->mSize;
	}

	//��������
	~LinkList()
	{
		LinkNode<T> *pCur = this->header.next;
		LinkNode<T> *pDel = NULL;
		while (pCur != NULL)
		{
			pDel = pCur;	//�ȱ���Ҫ�ͷŵĽڵ�
			pCur = pCur->next;
			delete pDel;
		}
	}

private:
	LinkNode<T> header;	//ͷ���
	int mSize;
};