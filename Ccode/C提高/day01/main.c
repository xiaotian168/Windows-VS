#include<stdio.h>
#include<stdlib.h>

//a：数组首元素地址
//pos：指定的位置
//data：需要插入的元素
//size：数组的长度，数组元素的个数，不是数组的大小，增加元素，需要做相应修改
void insert_array(int *a, int pos, int data, int *size)
{
	if (a == NULL || pos < 0)
		return;
	(*size)++;
	if (pos >= *size)	//插入点位置及后面无数据
	{
		for (int i = *size-1; i < pos; ++i)
			a[i] = 0;
		a[pos] = data;
		(*size) = pos + 1;	//更新数组实际元素个数
	}	
	else   //插入点位置有数据
	{
		for (int i = *size - 1; i > pos; --i)	//插入点及后面的元素依次右移一位
			a[i] = a[i - 1];
		a[pos] = data;	//插入元素
	}	
}

void remove_array(int *a, int pos, int *size)
{
	if (a == NULL || pos < 0  || pos >= *size)
		return;
	for (int i = pos; i < *size - 1; ++i)	//插入点后面的位置依次左移
		a[i] = a[i + 1];
	(*size)--;
}

void print_array(int *a, int size)
{
	if (a == NULL || size < 0)
		return;
	for (int i = 0; i < size; ++i)
		printf("%d,", a[i]);
	printf("\n");
}

int main()
{
	/************************************************************/
	/*
		有一个数组，假如元素没有放满，设计一个函数能在
		指定位置插入指定元素，
		指定位置删除元素

	*/
	/************************************************************/	

	int a[15] = { 1, 3, 5, 7, 9, 11, 13 };
	int size = 7; //数组长度，已经放元素的个数

	print_array(a, size); //打印
	insert_array(a, 0, -1, &size); //在0的位置插入-1
	print_array(a, size); //打印

	insert_array(a, 2, 8, &size); //在2的位置插入8
	print_array(a, size); //打印

	insert_array(a, 13, 250, &size); //在末尾的位置插入250
	print_array(a, size); //打印

	print_array(a, size); //打印
	remove_array(a, 13, &size); //删除第0个元素
	print_array(a, size); //打印

	system("pause");
	return 0;
}