#pragma once	//��ֹͷ�ļ��ظ�����

//��̬��������ݽṹ
struct DArray
{
	void **pArry;	//����ռ��׵�ַ
	int capacity;	//����
	int size;	//��С
};

typedef void(*MYFOREACH)(void*);	//����һ������ָ������

typedef void* SeqStack;

#ifdef __cplusplus
extern "C" {
#endif

	//��ʼ����̬����
	struct DArray *Init_DynamicArray();

	//���뺯��
	void Insert_DynamicArray(struct DArray *arr, int pos, void *data);

	//ɾ������
	void Remove_DynamicArray(struct DArray *arr, int pos);

	//��������������ӡ���޸����ݣ�
	void Foreach_DynamicArray(struct DArray *arr, MYFOREACH myforeach);

	//β��ɾ������
	void PopBack_DynamicArray(struct DArray *arr);

	//ͷ��ɾ������
	void PopFront_DynamicArray(struct DArray *arr);

	//���ָ��λ��Ԫ��
	void* Get_DynamicArray(struct DArray *arr, int pos);

	//��������
	void Destroy_DynamicArray(struct DArray *arr);
	

#ifdef __cplusplus
}
#endif
