#include<stdio.h>
#include<stdlib.h>

//a��������Ԫ�ص�ַ
//pos��ָ����λ��
//data����Ҫ�����Ԫ��
//size������ĳ��ȣ�����Ԫ�صĸ�������������Ĵ�С������Ԫ�أ���Ҫ����Ӧ�޸�
void insert_array(int *a, int pos, int data, int *size)
{
	if (a == NULL || pos < 0)
		return;
	(*size)++;
	if (pos >= *size)	//�����λ�ü�����������
	{
		for (int i = *size-1; i < pos; ++i)
			a[i] = 0;
		a[pos] = data;
		(*size) = pos + 1;	//��������ʵ��Ԫ�ظ���
	}	
	else   //�����λ��������
	{
		for (int i = *size - 1; i > pos; --i)	//����㼰�����Ԫ����������һλ
			a[i] = a[i - 1];
		a[pos] = data;	//����Ԫ��
	}	
}

void remove_array(int *a, int pos, int *size)
{
	if (a == NULL || pos < 0  || pos >= *size)
		return;
	for (int i = pos; i < *size - 1; ++i)	//���������λ����������
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
		��һ�����飬����Ԫ��û�з��������һ����������
		ָ��λ�ò���ָ��Ԫ�أ�
		ָ��λ��ɾ��Ԫ��

	*/
	/************************************************************/	

	int a[15] = { 1, 3, 5, 7, 9, 11, 13 };
	int size = 7; //���鳤�ȣ��Ѿ���Ԫ�صĸ���

	print_array(a, size); //��ӡ
	insert_array(a, 0, -1, &size); //��0��λ�ò���-1
	print_array(a, size); //��ӡ

	insert_array(a, 2, 8, &size); //��2��λ�ò���8
	print_array(a, size); //��ӡ

	insert_array(a, 13, 250, &size); //��ĩβ��λ�ò���250
	print_array(a, size); //��ӡ

	print_array(a, size); //��ӡ
	remove_array(a, 13, &size); //ɾ����0��Ԫ��
	print_array(a, size); //��ӡ

	system("pause");
	return 0;
}