#pragma once	//��ֹͷ�ļ��ظ�����

//��̬��������ݽṹ
struct DArray
{
	void **pArry;	//����ռ��׵�ַ
	int capacity;	//����
	int size;	//��С
};

typedef void(*MYFOREACH)(void*);	//��������ָ��

typedef int(*DATACOMPARE)(void *, void *);	//�ȽϺ���ָ��

#ifdef __cplusplus
extern "C" {
#endif

	//��ʼ����̬����
	struct DArray *Init_DynamicArray();

	//ָ��λ�ò��뺯��
	void Insert_DynamicArray(struct DArray *arr, int pos, void* data);

	//β�����뺯��
	void PushBack_DynamicArray(struct DArray *arr, void* data);

	//ͷ�����뺯��
	void PushFront_DynamicArray(struct DArray *arr, void* data);

	//ɾ������(��ָ��λ��ɾ��)
	void Remove_DynamicArray(struct DArray *arr, int pos);

	//��ֵɾ��
	void DeleteByVal_DynamicArray(struct DArray *arr, void* data, DATACOMPARE myCompare);

	//��������������ӡ��
	void Foreach_DynamicArray(struct DArray *arr, MYFOREACH myForeach);

	//��������
	void Destroy_DynamicArray(struct DArray *arr);
	

#ifdef __cplusplus
}
#endif
