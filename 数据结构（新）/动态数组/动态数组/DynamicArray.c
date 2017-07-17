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

//指定位置插入函数
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

//尾部插入函数
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

//头部插入函数
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

//删除函数(按指定位置删除)
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

//按值删除
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
			i--;	//删除所有匹配到的值
			//break;	//删除第一条匹配到的值
		}
	}
}

//遍历函数，（打印，修改数据）
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
