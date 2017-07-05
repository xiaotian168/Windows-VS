#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"DynamicArray.h"


//初始化动态数组
struct DArray *Init_DynamicArray()
{
	struct DArray *arr = (struct DArray *) calloc(1, sizeof(struct DArray));
	arr->capacity = 5;
	arr->pArry = (void **)calloc(arr->capacity, sizeof(void *));
	arr->size = 0;

	return arr;
}

//插入函数
void Insert_DynamicArray(struct DArray *arr, int pos, void *data)
{
	if (NULL == arr || pos < 0 || NULL == data)
	{
		return;
	}

	if (pos > arr->size)	//插入位置调整
	{
		pos = arr->size;
	}

	if (arr->size == arr->capacity)	//判断空间是否足够
	{
		//空间不够；拓展
		int NewCapacity = arr->capacity * 2;
		arr->pArry = (void **)realloc(arr->pArry, NewCapacity *sizeof(void *));
		if (NULL == arr)
		{
			printf("内存空间不足\n");
			return;
		}
		arr->capacity = NewCapacity;
	}

	for (int i = arr->size; i > pos; --i)	//pos插入点位置整体右移；空出pos位置
	{
		arr->pArry[i] = arr->pArry[i-1];
	}

	arr->pArry[pos] = data;
	arr->size++;
}

//删除函数
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

//遍历函数，（打印，修改数据）
void Foreach_DynamicArray(struct DArray *arr, MYFOREACH myforeach)
{
	if (NULL == arr || NULL == myforeach)
	{
		return;
	}

	for (int i = 0; i < arr->size; ++i)
	{
		myforeach(arr->pArry[i]);
	}
}

//销毁数组
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




////初始化动态数组
//struct DArray *Init_DynamicArray()
//{
//	struct DArray *arr = malloc(sizeof(struct DArray));
//	arr->capacity = 5;
//	arr->pArry = malloc(sizeof(void *)* arr->capacity);
//	arr->size = 0;
//
//	return arr;
//}
//////插入函数
////void Insert_DynamicArray(struct DArray *arr, int pos, void *data)
////{
////	if (NULL == arr)
////	{
////		return;
////	}
////
////	if (NULL == data)
////	{
////		return;
////	}
////
////	//调整位置
////	if (pos < 0 || pos > arr->size)
////	{
////		pos = arr->size;
////	}
////
////
////	//判断空间是够足够
////	if (arr->size == arr->capacity)
////	{
////		//说明空间不够了
////
////		//1. 申请更大的内存空间(增长策略：原空间2倍增长)
////		int newcapacity = arr->capacity * 2;
////		void **newspace = malloc(sizeof(void *)* newcapacity);
////
////		//2. 将原空间的数据拷贝到新空间
////		memcpy(newspace, arr->pArray, arr->capacity * sizeof(void *));
////
////		//3. 释放原空间
////		free(arr->pArray);
////
////		arr->pArray = newspace;
////		arr->capacity = newcapacity;
////	}
////
////
////	//移动位置，将pos位置空出来
////	for (int i = arr->size - 1; i >= pos; --i)
////	{
////		arr->pArray[i + 1] = arr->pArray[i];
////	}
////
////	//直接将元素插入到pos位置
////	arr->pArray[pos] = data;
////	arr->size++;
////}
////删除函数
//void Remove_DynamicArray(struct DArray *arr, int pos)
//{
//	if (NULL == arr)
//	{
//		return;
//	}
//
//	if (pos < 0 || pos > arr->size - 1)
//	{
//		return;
//	}
//
//	for (int i = pos; i < arr->size - 1; ++i)
//	{
//		arr->pArray[i] = arr->pArray[i + 1];
//	}
//
//	arr->size--;
//
//}
////遍历函数（打印，修改数据）
//void Foreach_DynamicArray(struct DArray *arr, MYFOREACH myforeach)
//{
//
//	if (NULL == arr)
//	{
//		return;
//	}
//
//	if (NULL == myforeach)
//	{
//		return;
//	}
//
//	for (int i = 0; i < arr->size; ++i)
//	{
//		myforeach(arr->pArray[i]);
//	}
//
//}
////销毁数组
//void Destroy_DynamicArray(struct DArray *arr)
//{
//	if (NULL == arr)
//	{
//		return;
//	}
//
//	if (arr->pArray != NULL)
//	{
//		arr->capacity = 0;
//		arr->size = 0;
//
//		free(arr->pArray);
//		arr->pArray = NULL;
//	}
//
//	free(arr);
//	arr = NULL;
//}