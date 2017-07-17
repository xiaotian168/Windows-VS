#pragma once
#include<stdlib.h>
#include<string.h>

typedef void* DArray;
typedef void(*MYFOREACH)(void *);
typedef struct _DYNAMICARRAY
{
	void **address;
	int capacity;
	int size;
}DynamicArray;
//��ʼ����̬����
DArray Init_DynamicArray()
{
	DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
	arr->size = 0;
	arr->capacity = 6;
	arr->address = (void **)malloc(sizeof(void *)* arr->capacity);
	return arr;
}
//����
void Insert_DynamicArray(DArray Darr, void *data, int pos)
{
	if (NULL == Darr)
		return;
	if (NULL == data)
		return;
	DynamicArray *arr = (DynamicArray *)Darr;
	if (arr->size == arr->capacity)
	{
		int newcapacity = arr->capacity * 2;
		void **newspace = (void **)malloc(sizeof(void *)*newcapacity);
		memcpy(newspace, arr->address, sizeof(void *)* arr->capacity);
		free(arr->address);
		arr->address = newspace;
		arr->capacity = newcapacity;
	}
	if (pos < 0 || pos >arr->size)
		pos = arr->size;
	//����Ԫ�غ��ƣ��ճ�posλ��
	for (int i = arr->size - 1; i >= pos; --i)
	{
		(arr->address)[i + 1] = (arr->address)[i];
	}
	//����Ԫ��
	(arr->address)[pos] = data;
	arr->size++;
}
//����
void Foreach_DynamicArray(DArray Darr, MYFOREACH myforeach)
{
	if (NULL == Darr)
		return;
	if (NULL == myforeach)
		return;
	DynamicArray *arr = (DynamicArray *)Darr;
	for (int i = 0; i < arr->size; ++i)
	{
		myforeach(arr->address[i]);
	}
}
//ɾ��
void Delete_DynamicArray(DArray Darr, int pos)
{
	if (NULL == Darr)
		return;
	DynamicArray *arr = (DynamicArray *)Darr;
	if (arr->size == 0)
		return;
	if (pos < 0 || pos >arr->size - 1)
		return;
	for (int i = pos; i< arr->size - 1; ++i)
	{
		arr->address[i] = arr->address[i + 1];
	}
	arr->size--;
}

//��������
void Destroy_DynamicArray(DArray Darr)
{
	if (NULL == NULL)
		return;
	DynamicArray *arr = (DynamicArray *)Darr;
	arr->capacity = 0;
	arr->size = 0;
	if (arr->address != NULL)
		free(arr->address);
	arr->address = NULL;
	free(arr);
	arr = NULL;
}