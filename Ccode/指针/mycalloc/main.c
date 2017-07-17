#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *mycalloc(size_t rmemb, size_t Size)
{
	size_t sum = rmemb * Size;
	if (sum == 0)	//�ж��β���ֵΪ��
		return NULL;
	void *ret = NULL;
	if (sum / rmemb == Size)	//�ж�Ҫ����Ŀռ������Χ�ڣ�δ�����
	{
		ret = (void *)malloc(sum);
		memset(ret, 0, sum);	//ע�⣺�˴�sum̫�����memset�����
		return ret;
	}
	else          //������ؿ�
		return NULL;
}

int main()
{
	/**************************************************************/
	/*
	��дcalloc��ʵ��
		ͨ������mallocִ�з���,����memset���ڴ�����Ϊ00
		��Ĵ���Ӧ��û���κ���������������©��,
		������������size\_t�ö���λ��ʾ,���붼Ӧ������������

	�⺯��calloc����������: 
  
		void *calloc(size_t rmemb, size_t Size) ;
		���ݿ��ĵ�: ������callocΪһ����������ڴ�,��������rmemb��Ԫ��,
		ÿ��Ԫ��Ϊsize�ֽڡ��ڴ�����Ϊ00,
		���rmemb��sizeΪ0,��calloc����NULL�� 
	*/
	/****************************************************************/
	int *p = (int *)mycalloc(4, 1000000000);	//������������ڵ�����memset�����
	system("pause");
	return 0;
}