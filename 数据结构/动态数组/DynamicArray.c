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

//���뺯��
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

//ɾ������
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

//��������������ӡ���޸����ݣ�
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




////��ʼ����̬����
//struct DArray *Init_DynamicArray()
//{
//	struct DArray *arr = malloc(sizeof(struct DArray));
//	arr->capacity = 5;
//	arr->pArry = malloc(sizeof(void *)* arr->capacity);
//	arr->size = 0;
//
//	return arr;
//}
//////���뺯��
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
////	//����λ��
////	if (pos < 0 || pos > arr->size)
////	{
////		pos = arr->size;
////	}
////
////
////	//�жϿռ��ǹ��㹻
////	if (arr->size == arr->capacity)
////	{
////		//˵���ռ䲻����
////
////		//1. ���������ڴ�ռ�(�������ԣ�ԭ�ռ�2������)
////		int newcapacity = arr->capacity * 2;
////		void **newspace = malloc(sizeof(void *)* newcapacity);
////
////		//2. ��ԭ�ռ�����ݿ������¿ռ�
////		memcpy(newspace, arr->pArray, arr->capacity * sizeof(void *));
////
////		//3. �ͷ�ԭ�ռ�
////		free(arr->pArray);
////
////		arr->pArray = newspace;
////		arr->capacity = newcapacity;
////	}
////
////
////	//�ƶ�λ�ã���posλ�ÿճ���
////	for (int i = arr->size - 1; i >= pos; --i)
////	{
////		arr->pArray[i + 1] = arr->pArray[i];
////	}
////
////	//ֱ�ӽ�Ԫ�ز��뵽posλ��
////	arr->pArray[pos] = data;
////	arr->size++;
////}
////ɾ������
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
////������������ӡ���޸����ݣ�
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
////��������
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