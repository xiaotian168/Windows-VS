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

//β��ɾ������
void PopBack_DynamicArray(struct DArray *arr)
{
	if (NULL == arr)
	{
		return;
	}


}

//ͷ��ɾ������
void PopFront_DynamicArray(struct DArray *arr)
{
	if (NULL == arr)
	{
		return;
	}


}

//���ָ��λ��Ԫ��
void* Get_DynamicArray(struct DArray *arr, int pos)
{
	if (NULL == arr)
	{
		return;
	}

	if (pos < 0 || pos >= arr->size)
	{
		return;
	}

	return arr->pArry[pos];

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
