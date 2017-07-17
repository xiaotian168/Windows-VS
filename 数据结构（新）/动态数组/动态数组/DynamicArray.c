#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"DynamicArray.h"


//��ʼ����̬����
struct DArray *Init_DynamicArray()
{
	struct DArray *arr = (struct DArray *) calloc(1, sizeof(struct DArray));
	arr->capacity = 5;
	arr->pArry = (void **)calloc(arr->capacity, sizeof(void *));
	arr->size = 0;

	return arr;
}

//ָ��λ�ò��뺯��
void Insert_DynamicArray(struct DArray *arr, int pos, void *data)
{
	if (NULL == arr || pos < 0 || NULL == data)
	{
		return;
	}

	if (pos > arr->size)	//����λ�õ���
	{
		pos = arr->size;
	}

	if (arr->size == arr->capacity)	//�жϿռ��Ƿ��㹻
	{
		//�ռ䲻������չ
		int NewCapacity = arr->capacity * 2;
		arr->pArry = (void **)realloc(arr->pArry, NewCapacity *sizeof(void *));
		if (NULL == arr)
		{
			printf("�ڴ�ռ䲻��\n");
			return;
		}
		arr->capacity = NewCapacity;
	}

	for (int i = arr->size; i > pos; --i)	//pos�����λ���������ƣ��ճ�posλ��
	{
		arr->pArry[i] = arr->pArry[i-1];
	}

	arr->pArry[pos] = data;
	arr->size++;
}

//β�����뺯��
void PushBack_DynamicArray(struct DArray *arr, void* data)
{
	if (NULL == arr)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	Insert_DynamicArray(arr, arr->size, data);
}

//ͷ�����뺯��
void PushFront_DynamicArray(struct DArray *arr, void* data)
{
	if (NULL == arr)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	Insert_DynamicArray(arr, 0, data);
}

//ɾ������(��ָ��λ��ɾ��)
void Remove_DynamicArray(struct DArray *arr, int pos)
{
	if (NULL == arr || pos < 0 || pos >= arr->size)
	{
		return;
	}

	for (int i = pos; i < arr->size - 1; ++i)
	{
		arr->pArry[i] = arr->pArry[i + 1];
	}
	
	arr->size--;
}

//��ֵɾ��
void DeleteByVal_DynamicArray(struct DArray *arr, void* data, DATACOMPARE myCompare)
{
	if (NULL == arr)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	for (int i = 0; i < arr->size; ++i)
	{
		if (myCompare(arr->pArry[i], data) == 0)
		{
			Remove_DynamicArray(arr,i);
			i--;	//ɾ������ƥ�䵽��ֵ
			//break;	//ɾ����һ��ƥ�䵽��ֵ
		}
	}
}

//��������������ӡ���޸����ݣ�
void Foreach_DynamicArray(struct DArray *arr, MYFOREACH myForeach)
{
	if (NULL == arr || NULL == myForeach)
	{
		return;
	}

	for (int i = 0; i < arr->size; ++i)
	{
		myForeach(arr->pArry[i]);
	}
}

//��������
void Destroy_DynamicArray(struct DArray *arr)
{
	if (NULL == arr)
	{
		return;
	}

	if (arr->pArry != NULL)
	{
		arr->capacity = 0;
		arr->size = 0;
		free(arr->pArry);
		arr->pArry = NULL;
	}
	free(arr);
	arr = NULL;
}
